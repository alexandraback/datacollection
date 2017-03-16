#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <cctype>
#include <cmath>
#include <algorithm>

using namespace std;

const int N = 1024;

int vis[N];
vector<int> adj[N];

bool dfs(int u)
{
	vis[u] = true;
	for (int i = 0; i < adj[u].size(); i++)
	{
		int v = adj[u][i];
		if (!vis[v])
		{
			if (!dfs(v))
				return false;
		}
		else
			return false;
	}
	return true;
}

int main()
{
	int t, n, m, num;
	scanf("%d", &t);
	for (int cas = 1; cas <= t; cas++)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			adj[i].clear();
			scanf("%d", &m);
			while (m--)
			{
				scanf("%d", &num);
				adj[i].push_back(num);
			}
		}
		bool ans = true;
		for (int i = 1; i <= n && ans; i++)
		{
			memset(vis, 0, sizeof (vis));
			if (!dfs(i))
				ans = false;
		}
		if (!ans)
			printf("Case #%d: Yes\n", cas);
		else
			printf("Case #%d: No\n", cas);
	}
	return 0;
}
