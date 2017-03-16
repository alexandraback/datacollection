#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int a[1010], v[1010], f[1010], d[1010];
int T, t, n, m, ans, cycle, len, tot, cx, cy;
int head[1010], ver[2010], Next[2010];

void add(int x, int y)
{
	ver[++tot] = y, Next[tot] = head[x], head[x] = tot;
}

void dfs(int x, int fa)
{
	v[x] = 1; f[x] = 0;
	for (int i = head[x]; i; i = Next[i])
	{
		int y = ver[i];
		if (i == fa) continue;
		if (v[y])
		{
			cycle = max(cycle, abs(d[y] - d[x]) + 1);
			cx = x, cy = y;
		}
		else {
			d[y] = d[x] + 1;
			dfs(y, i ^ 1);
		}
	}
}

void dp(int x, int fa)
{
	f[x] = 0;
	for (int i = head[x]; i; i = Next[i])
	{
		int y = ver[i];
		if (y == fa) continue;
		dp(y, x);
		f[x] = max(f[x], f[y] + 1);
	}
}

int main()
{
	freopen("C-small-attempt1.in", "r", stdin);
	freopen("C-small-attempt1.out", "w", stdout);
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> n;
		ans = len = 0;
		tot = 1;
		memset(head, 0, sizeof(head));
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			add(i, a[i]);
			add(a[i], i);
		}
		memset(v, 0, sizeof(v));
		for (int i = 1; i <= n; i++)
		{
			if(v[i]) continue;
			cycle = d[i] = 0;
			dfs(i, 0);
			ans = max(ans, cycle);
			if (cycle == 2)
			{
				dp(cx, cy);
				dp(cy, cx);
				len += f[cx] + f[cy] + 2;
			}
		}
		ans = max(ans, len);
		printf("Case #%d: %d\n", t, ans);
	}
}