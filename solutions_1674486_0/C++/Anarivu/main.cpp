#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<string>
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<math.h>
using namespace std;


vector<vector<int> > g;


bool res = 0;

int u[1005] = {0};
int ci[1005] = {0};

void dfs(int v)
{
	u[v] = 1;

	for(int i = 0; i < g[v].size(); i++)
	{
		if(u[g[v][i]] == 1)
		{
			res = 1;
			return;
		}
		else if(!u[g[v][i]])
		{
			dfs(g[v][i]);
			if(res)
				return;
		}
	}
}


int main()
{
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);

	int tt;
	scanf("%d", &tt);

	for(int t = 0; t < tt; t++)
	{
		g.clear();
		int n;
		res = 0;
		scanf("%d", &n);
		g.resize(n);
		memset(ci, 0, 1005 * sizeof(int));

		for(int i = 0; i < n; i++)
		{
			int m ;
			scanf("%d", &m);
			for(int j = 0; j < m; j++)
			{
				int d;
				scanf("%d", &d);
				d--;

				ci[d]++;

				g[i].push_back(d);
			}
		}


		for(int i = 0; i < n && !res; i++)
		{
			if(!ci[i])
			{
				memset(u, 0, 1005 * sizeof(int));
				dfs(i);
			}
		}

		printf("Case #%d: ", t+1);
		if(res)
			printf("Yes\n");
		else
			printf("No\n");

	}


	return 0;
}


