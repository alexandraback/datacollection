#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <fstream>

using namespace std;

struct node 
{
	int parent;
};

struct _pair
{
	int a;
	int b;
};

map<int, set<int>> dict;

ifstream fin("input.txt");
ofstream fout("output.txt");

void solution()
{
	vector<_pair> pairs_to_check;
	int N;
	fin>>N;
	int M;

	map<int, vector<int>> graph;
	map<int, set<int>> reachable;

	for (int i = 1;i <= N;i++)
	{
		fin>>M;
		int parent;
		for (int j = 0;j < M;++j)
		{
			fin>>parent;
			graph[i].push_back(parent);
		}
		for (vector<int>::iterator it = graph[i].begin(); it != graph[i].end(); it++)
		{
			for (vector<int>::iterator it1 = graph[i].begin(); it1 != graph[i].end(); it1++)
			{
				int x = (*it);
				int y = (*it1);
				if (x > y)
				{
					_pair p;
					p.a = x;
					p.b = y;
					pairs_to_check.push_back(p);
				}
			}
		}
	}
	//fout<<"pairs"<<endl;
	//for (vector<_pair>::iterator it = pairs_to_check.begin(); it != pairs_to_check.end();it++)
	//{
	//	fout<<(*it).a<<" "<<(*it).b<<endl;
	//}

	for (int i = 1;i <= N;++i)
	{
		//BFS FOR i
		queue<int> q;
		q.push(i);
		set<int> reached;
		int cur;
		while (!q.empty())
		{
			cur = q.front();
			q.pop();
			reached.insert(cur);
			for (vector<int>::iterator it = graph[cur].begin(); it != graph[cur].end(); it++)
			{
				if (reached.find(*it) == reached.end())
				{
					q.push(*it);
				}
			}
		}
		reachable[i] = reached;
		//fout<<"reachable "<<i<<endl;
		//for (set<int>::iterator it = reachable[i].begin(); it != reachable[i].end();it++)
		//{
		//	fout<<(*it)<<" ";
		//}
		//fout<<endl;
	}


	for (vector<_pair>::iterator it = pairs_to_check.begin(); it != pairs_to_check.end(); it++)
	{
		_pair p = (*it);
		int x = p.a;
		int y = p.b;
		set<int> s1 = reachable[x];
		set<int> s2 = reachable[y];
		//fout<<x<<" ... "<<y<<endl;

		//fout<<"reachable "<<x<<endl;
		//for (set<int>::iterator it = s1.begin(); it != s1.end();it++)
		//{
		//	fout<<(*it)<<" ";
		//}
		//fout<<endl;

		//fout<<"reachable "<<y<<endl;
		//for (set<int>::iterator it = s2.begin(); it != s2.end();it++)
		//{
		//	fout<<(*it)<<" ";
		//}
		//fout<<endl;

		for (set<int>::iterator it = s1.begin(); it != s1.end(); it++)
		{
			for (set<int>::iterator it1 = s2.begin(); it1 != s2.end(); it1++)
			{
				if ((*it) == (*it1))
				{
					fout<<"Yes"<<endl;
					return;
				}
			}
		}
	}
	fout<<"No"<<endl;
	return;

	//for (int i = 1;i <= N;i++)
	//{
	//	fin>>M;
	//	int parent;
	//	for (int j = 0;j < M;j++)
	//	{
	//		fin>>parent;
	//		dict[i].insert(parent);
	//		//for (int k = 0;k < j;k++)
	//		//{
	//		//	_pair p;
	//		//	p.a = dict[i][k];
	//		//	p.b = parent;
	//		//	pairs_to_check.insert(p);
	//		//}
	//	}
	//	for (set<int>::iterator it = dict[i].begin();it != dict[i].end();it++)
	//	{
	//		for (set<int>::iterator it1 = dict[i].begin();it1 != dict[i].end();it1++)
	//		{
	//			int x = (*it);
	//			int y = (*it1);
	//			if (x != y)
	//			{
	//				_pair p;
	//				p.a = x;
	//				p.b = y;
	//				pairs_to_check.push_back(p);
	//			}
	//		}
	//	}
	//}
	//for ()
	//{
	//}
}

int main()
{
	int T;
	fin>>T;
	for (int i = 1;i <= T;++i)
	{
		fout<<"Case #"<<i<<": ";
		solution();
	}
}