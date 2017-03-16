
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
#include <cctype>
#include <map>
#include <list>
#include <cmath>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long l;

vector<string> ss;

void fun(int N, int m, int tek, int k, string tekS)
{
	if(tek>=m)
	{
		ss.push_back(tekS);
		return;
	}
	for(int i=k+1; i<=N; i++)
		fun(N, m, tek+1, i, tekS+(char)(i+48));
}

void main()
{
	int T;
	ifstream in;
	ofstream out;
	in.open("C-small-attempt1.in", ios_base::in);
	out.open("C.txt", ios_base::app);
	in>>T;
	for(int t = 0; t < T; ++t)
	{
		int c, d, v, ans = 0;
		in>>c>>d>>v;
		vector<int> cns;
		vector<int> scns;
		for(int i = 0; i < d; ++i)
		{
			int cc;
			in>>cc;
			scns.push_back(cc);
		}
		start:
		for(int i = 0; i < d; ++i)
		{
			fun(d, i + 1, 0, 0, "");
		}
		for(int i = 0; i < ss.size(); ++i)
		{
			int newC = 0;
			for(int j = 0; j < ss[i].size(); ++j)
			{
				newC += scns[ss[i][j] - '0' - 1];
			}
			cns.push_back(newC);
		}
		for(int i = 1; i < v; ++i)
		{
			bool f = 0;
			for(int j = 0; j < cns.size(); ++j)
			{
				if(cns[j] == i)
				{
					f = 1;
					break;
				}
			}
			if(!f)
			{
				scns.push_back(i);
				++d;
				++ans;
				cns.clear();
				ss.clear();
				goto start;
			}
		}
		ss.clear();
		out<<"Case #"<<t + 1<<": "<<ans<<endl;
	}
	system("pause");
}
