
#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:160777216")
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <cmath>
#include <string>
#include <cstdio>
#include <ctime>
#include <cstring>

#define VI vector<int>
#define PII pair<int,int>
#define MP make_pair
#define INF 1000000000000000000LL
#define eps 1e-9

#define ll long long
#define f0(i,n) for (i = 0; i < n; i++)

using namespace std;

int i , j , n, m , k;
int a[3500];
int u[3000] , u1[3000] , u2[3000];
vector<int> g[30000];

int dfs(int x)
{
	int i;
	u[x] = 1;
	int ret = 0;
	for (i = 0 ;i < g[x].size(); i++)
		if (!u[g[x][i]])
		{
			ret = max(ret , dfs(g[x][i]) + 1);
		}
	return ret;
}
int main()
{
	freopen("C-small-attempt1.in" , "r" , stdin);
	freopen("C-small-attempt1.out" , "w" , stdout);
	
	int testcnt , t;
	cin>>testcnt;
	for (t = 1; t <= testcnt; t++)
	{
		cin>>n;
		
		for (i = 0 ;i < n; i++)
			g[i].clear();
		for (i = 0; i < n; i++)
		{
			
			u[i] = u1[i] = u2[i] = 0;
			cin>>a[i];
			a[i]--;
			g[a[i]].push_back(i);
			
		}

		int ans = 1;

		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
				u[j] = 0;

			int x = i;
			int nom = 1;
			while (!u[x])
			{
				u[x] = nom++;
				x = a[x];
			}

			ans = max(ans , nom - u[x]);	
		}

		int ans1 = 0;
		
		for (i = 0; i < n; i++)
		{
			if (a[i] > i && a[a[i]] == i)
			{
				for (j = 0; j < n; j++)
					u[j] = 0;
				u[i] = u[a[i]] = 1;
				ans1 += dfs(i) + dfs(a[i]) + 2;
			}
		}
		
		cout<<"Case #"<<t<<": "<<max(ans , ans1)<<endl;
		
		
	}
	return 0;
}