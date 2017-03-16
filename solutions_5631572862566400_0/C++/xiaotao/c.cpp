#include <cstdio>

const int Maxn = 1005;

int n, ans;
int list[Maxn], f[Maxn];
bool used[Maxn];

bool check(int m)
{
	list[0] = list[m];
	list[m + 1] = list[1];
	for (int i = 1; i <= m; ++i)
		if (list[i - 1] != f[list[i]] && list[i + 1] != f[list[i]])
			return false;
	return true;
}

void dfs(int dep)
{
	if (dep - 1 > ans && check(dep - 1))
		ans = dep - 1;
	if (dep > n) return;
	for (int i = 1; i <= n; ++i)
		if (!used[i])
		{
			list[dep] = i;
			used[i] = true;
			dfs(dep + 1);
			used[i] = false;
		}
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int tt = 1; tt <= T; ++tt)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i)
			scanf("%d", f + i);
		ans = 0;
		dfs(1);
		printf("Case #%d: %d\n", tt, ans);
	}
	return 0;
}
