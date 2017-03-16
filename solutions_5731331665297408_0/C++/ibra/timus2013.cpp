#include <cstdio>
#include <vector>
#include<cmath>
#include<ctime>
#include<sstream>
#include <algorithm>
#include<iostream>
#include<set>
#include <cstring>
#include<string>
#include<map>
#include<queue>
#include <cassert>
using namespace std;
typedef unsigned long long ull;
int nextint(){int a;scanf("%d",&a);return a;}
const double EPS = 1e-6;

vector<vector<int> > g;

bool go(vector<int> &per)
{
	vector<int> st;
	st.push_back(per[0]);
	for(int i = 1; i < per.size(); i++)
	{
		if(st.empty()) return false;
		bool ok = false;
		for(int j = 0; j < g[st.back()].size(); j++)
		{
			if(g[st.back()][j] == per[i])
			{
				ok = true;
			}
		}
		if(ok)
		{
			st.push_back(per[i]);
		}
		else
		{
			i--;
			st.pop_back();
		}
	}


	return true;
}

int main()
{
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("out", "w", stdout);
	int t = nextint();
	for(int test = 1; test <= t; test++)
	{
		int n = nextint();
		int m = nextint();
		vector<string> zip(n);
		for(int i = 0; i < n; i++)
			cin >> zip[i];

		g = vector<vector<int> > (n);
		for(int i = 0; i < m; i++)
		{
			int a = nextint()-1;
			int b = nextint()-1;
			g[a].push_back(b);
			g[b].push_back(a);
		}

		vector<int> per(n);
		int fac = 1;
		for(int i = 0; i < n; i++)
		{
			per[i] = i;
			fac *= i+1;
		}
		
		string res = "9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999";
		while(fac--)
		{
			next_permutation(per.begin(), per.end());
			if(go(per))
			{
				string cur = "";
				for(int i = 0; i < per.size(); i++)
					cur += zip[per[i]];
				res = min(res, cur);
			}
		}

		cout << "Case #" << test << ": " << res << endl;
	}

	return 0;
}