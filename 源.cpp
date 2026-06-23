//有5名选手，10个评委打分，去除最高分，最低分，取平均分


//2.遍历vector容器，取出来每一个选手，执行for循环，可以把10个评委打分放到deque容器中
//3.sort算法对deque容器中分数排序，去除最高和最低分
//4.deque容器遍历一遍，累加总分
//5.或取平均分


#include<iostream>
#include<vector>
#include<deque>
#include<string>
#include<algorithm>
#include<ctime>
using namespace std;

class Person
{
public:
	Person(string name, int score)
	{
		this->m_Name = name;
		this->m_Score = score;
	}

	string m_Name;
	int m_Score;//平均分
};

//创建选手
void createPerson(vector<Person>& v)//一定要引用传递
{
	string nameSeed = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		string name = "选手";
		name += nameSeed[i];

		int score = 0;
		Person p(name, score);
		//将创建的对象放入容器
		v.push_back(p);
	}
}

//打分
void setScore(vector<Person>& v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		//将评委的分数放入到deque容器中
		deque<int>d;
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60; //60~100  rand()%40是0到39
			d.push_back(score);
		}

		/*cout << "选手：" << it->m_Name << "打分：" << endl;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			cout << *dit << " ";
		}
		cout << endl;*/

		//排序
		sort(d.begin(), d.end());

		//去除最高和最低分
		d.pop_back();
		d.pop_front();  //deque容器好处可以对头端去除

		//取平均分
		int sum = 0;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			sum += *dit;//累加评委分数
		}

		int avg = sum / d.size();

		//将平均分赋值给选手

		it->m_Score = avg;//it是人的指针
	}
}

void showScore(vector<Person>& v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout<<it->m_Name << "平均分:" << it->m_Score << endl;
	}
}
int main()
{
	//随机数种子
	srand((unsigned int)time (NULL));


	//1..创建五名选手，放到vector中 
	vector<Person>v;  //存放选手的容器
	createPerson(v);
	//测试
	/*for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout<<"姓名：" << (*it).m_Name << "  分数：" << (*it).m_Score << endl;
	}*/

	//2.给5名选手打分
	setScore(v);

	//3.显示最后得分
	showScore(v);
	return 0;
}