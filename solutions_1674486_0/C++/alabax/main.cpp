#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int conj[1000][10];
int M[1000];
int N;
int color[1000];

void dump()
{
	return;
	cout << endl;
	for (int i=0;i<N;++i)
	{
		cout << color[i] << ' ';
	}
	cout << endl;
}

void solve()
{
	for (int i=0; i<N; ++i)
	{
		memset(color, 0, sizeof(color));
		for (int j=0; j<M[i]; ++j)
		{
			int next = conj[i][j];
			if (color[next] != 0 && color[next] != j+1)
			{
				fout << "Yes";
				return;
			}
			color[next] = j+1;
			dump();
			stack<int> que;
			que.push(next);
			
			while (!que.empty())
			{
				int t = que.top();
				que.pop();
				for (int k=0; k<M[t]; ++k)
				{
					next = conj[t][k];
					if (color[next]!=0 && color[next] != j+1)
					{
						fout << "Yes";
						return;
					}
					if (color[next] == 0)
					{
						color[next] = j+1;
						que.push(next);
					}
				}
				dump();
			}
		}
	}
	fout << "No";
}

int main()
{
	int T;
	fin >> T;
	for (int i=0;i<T;++i)
	{
		fin >> N;
		
		for (int k=0; k<N; ++k)
		{
			fin >> M[k];
			for (int j=0; j<M[k]; ++j)
			{
				fin >> conj[k][j];
				--conj[k][j];
			}
		}
		
		fout << "Case #" << i+1 << ": ";
		solve();
		fout << endl;
	}
	return 0;
}