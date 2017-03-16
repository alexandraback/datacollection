#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

#define SZ(v) ((int)(v).size())
const int MAXN = 1024;

bool visit[MAXN], flag[MAXN], ans;
int t, n;
vector<int> maps[MAXN];

void dfs(int x)
{
	visit[x] = 1;
	for (int i = 0; i < SZ(maps[x]); ++ i)
	{
		int v = maps[x][i];
		if (visit[v])
			ans = 1;
		else
			dfs(v);
	}
}

int main()
{
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
	scanf("%d", &t);
	for (int l = 1; l <= t; ++ l)
	{
		memset(flag, 0, sizeof(flag));
		ans = 0;
		
		scanf("%d", &n);
		int m, a;
		for (int i = 1; i <= n; ++ i)
		{
			maps[i].clear();
			scanf("%d", &m);
			for (int j = 0; j < m; ++ j)
			{
				scanf("%d", &a);
				flag[a] = 1;
				maps[i].push_back(a);
			}
		}
		for (int i = 1; i <= n; ++ i)
			if (! flag[i] && ! ans)
			{
				memset(visit, 0, sizeof(visit));
				dfs(i);
			}	
		if (ans)
			printf("Case #%d: Yes\n", l);
		else
			printf("Case #%d: No\n", l);
	}
    return 0;
}
