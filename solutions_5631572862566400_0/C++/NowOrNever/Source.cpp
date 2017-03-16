#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

int g[1005], res, n;
bool vis[1005];

void dfs(int root, int pre, int now, int tmp)
{
	if (g[now] == root || g[now] == pre)
	{
		if (tmp > res)
			res = tmp;
	}
	if (g[now] == pre)
	{
		for (int i = 1; i <= n; ++i)
		{
			if (!vis[i])
			{
				vis[i] = true;
				dfs(root, now, i, tmp + 1);
				vis[i] = false;
			}
		}
	}
	if (!vis[g[now]])
	{
		vis[g[now]] = true;
		dfs(root, now, g[now], tmp + 1);
		vis[g[now]] = false;
	}
}

int main(){
	freopen("d://C-small-attempt0.in", "r", stdin);
	freopen("d://out.out", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int ti = 1; ti <= t; ti++)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i)
			scanf("%d", &g[i]);
		res = 1;
		for (int i = 1; i <= n; ++i)
		{
			memset(vis, false, sizeof vis);
			vis[i] = true;
			dfs(i, -1, i, 1);
			vis[i] = false;
		}
		printf("Case #%d: %d\n",ti, res);
	}
	return 0;
}