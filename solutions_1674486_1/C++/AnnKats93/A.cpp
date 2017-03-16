#include <cstdio>
#include <vector>
#include <iostream>
#include <cmath>
#include <queue>
#include <set>

using namespace std;

vector<int> g[1005];
int u[1005];
bool ci = 0;
int n;
bool was[1005];


void dfs(int v)
{
	u[v] = 1;
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if(u[to])
			ci = 1;
		if(!u[to])
			dfs(to);
	}
	u[v] = 2;
}


int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("a.out", "w", stdout);

	int t;
	scanf("%d", &t);
	for(int tt = 0; tt < t; tt++)
	{		
		scanf("%d", &n);

		ci = false;
		for(int i = 0; i < n; i++)
		{
			u[i] = 0;
			g[i].clear();
			was[i] = 0;
		}
		for(int i = 0; i < n; i++)
		{
			int m;
			scanf("%d", &m);
			for(int j = 0; j < m; j++)
			{
				int a;
				scanf("%d", &a);
				a--;
				g[i].push_back(a);
				was[a] = 1;
			}
		}

		for(int i = 0; i < n; i++)
		{
			if(!was[i])
			{
				memset(u, 0, sizeof(int) * 1003);
				dfs(i);
			}
		}

		if(ci)
			printf("Case #%d: Yes\n", tt+1);
		else
			printf("Case #%d: No\n", tt+1);
	}

	return 0;
}