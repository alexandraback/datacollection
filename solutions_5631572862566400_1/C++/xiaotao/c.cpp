#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int Maxn = 1005;

int n, ans;
int f[Maxn], d[Maxn];
vector<int> g[Maxn];

void dfs(int dep, int v)
{
	if (d[v] >= 0)
	{
		ans = max(ans, dep - d[v]);
		return;
	}
	d[v] = dep;
	dfs(dep + 1, f[v]);
}

int dig(int v, int fa)
{
	int maxd = 0;
	for (auto it = g[v].begin(); it != g[v].end(); ++it)
		if (*it != fa)
			maxd = max(maxd, dig(*it, v));
	return maxd + 1;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int tt = 1; tt <= T; ++tt)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i)
			g[i].clear();
		for (int i = 1; i <= n; ++i)
		{
			scanf("%d", f + i);
			g[f[i]].push_back(i);
		}
		ans = 0;
		for (int i = 1; i <= n; ++i)
		{
			memset(d, 255, sizeof(d));
			dfs(0, i);
		}
		int sum = 0;
		for (int i = 1; i <= n; ++i)
			if (i < f[i] && f[f[i]] == i)
				sum += dig(i, f[i]) + dig(f[i], i);
		ans = max(ans, sum);
		printf("Case #%d: %d\n", tt, ans);
	}
	return 0;
}

