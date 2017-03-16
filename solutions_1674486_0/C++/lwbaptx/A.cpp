#include <cstdio>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

const int maxn = 1010;

int c[maxn][maxn];
vector<int>v[maxn];
int d[maxn];
int vis[maxn];


void bfs(int st, int n)
{
	memset(d,0,sizeof(d));
	memset(vis,0,sizeof(vis));
	d[st] = 1;
	vis[st]=1;
    queue<int>q;
	while(q.size()>0)
		q.pop();
	q.push(st);
	while(q.size()>0)
	{
       int t=q.front();
	   q.pop();
	   for(int i=0;i<v[t].size();i++)
	   {
		  d[v[t][i]]+=d[t];
          if(vis[v[t][i]]==0 )
		  {
			  vis[v[t][i]]=1;
			  q.push(v[t][i]);
		  }
	   }
	}
	for(int i=1;i<=n;i++)
		c[st][i]=d[i];

}

int main(){
	int t, n, m, b;
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	scanf("%d", &t);
	for (int i = 1; i <= t; i++)
	{
		scanf("%d", &n);
        for(int j = 1; j <= n; j++)
			v[j].clear();

		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &m);
			for (int k = 1; k <= m; k++)
			{
				scanf("%d", &b);
				v[j].push_back(b);
			}
		}

		memset(c,0,sizeof(c));
		for (int j = 1; j <= n; j++)
			bfs(j, n);
		
		printf("Case #%d: ", i);
		bool ok = false;
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k <= n; k++)
			{
				if (c[j][k] > 1)
				{
					printf("Yes\n");
					ok = true;
					break;
				}
			}
			if (ok) break;
		}
		if (!ok) printf("No\n");
	}
	return 0;
}
