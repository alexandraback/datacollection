#include<stdio.h>
#include<string.h>
#define MAXD 1010
#define MAXM 100010
int N, next[MAXM], v[MAXM], e, first[MAXD], g[MAXD][MAXD], vis[MAXD], dgr[MAXD];
void add(int x, int y)
{
	v[e] = y;
	next[e] = first[x], first[x] = e ++;	
}
void init()
{
	int i, j, k, y;
	memset(g, 0, sizeof(g));
	memset(dgr, 0, sizeof(dgr));
	memset(first, -1, sizeof(first));
	e = 0;
	scanf("%d", &N);
	for(i = 1; i <= N; i ++)
	{
		scanf("%d", &k);
		for(j = 0; j < k; j ++)
		{
			scanf("%d", &y);
			if(!g[i][y])
				g[i][y] = 1, add(i, y), ++ dgr[y];
		}	
	}
}
int dfs(int cur)
{
	int i;
	vis[cur] = 1;
	for(i = first[cur]; i != -1; i = next[i])
	{
		if(vis[v[i]])
			return 1;
		if(dfs(v[i]))
			return 1;
	}
	return 0;
}
void solve()
{
	int i, j, k, ok = 0;
	for(i = 1; i <= N; i ++)
		if(dgr[i] == 0)
		{
			memset(vis, 0, sizeof(vis));
			if(dfs(i))
			{
				ok = 1;
				break;
			}
		}
	printf("%s\n", ok ? "Yes" : "No");
}
int main()
{
	freopen("A-large.in","r",stdin);
	freopen("out.txt","w",stdout);
	int t, tt;
	scanf("%d", &t);
	for(tt = 0; tt < t; tt ++)
	{
		init();
		printf("Case #%d: ", tt + 1);
		solve();
	}
	return 0;	
}
