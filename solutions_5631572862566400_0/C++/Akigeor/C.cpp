#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
const int N = 1005;
bool v[N];
int p[N];
vector<int> G[N];
int dfs(int x, int par)
{
	int ans = 1;
	for (int i : G[x])
	{
		if (i == par) continue;
		ans = max(ans, 1 + dfs(i, x));
	}
	return ans;
}
int main()
{
	int T, zzz = 0;
	scanf("%d", &T);
	while (T --)
	{
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; ++ i) G[i].clear();
		for (int i = 1; i <= n; ++ i)
		{
			scanf("%d", &p[i]);
			G[p[i]].push_back(i);
		}
		int ans = 0, tmp = 0;
		for (int i = 1; i <= n; ++ i)
		{
			int j = 1, k = p[i];
			memset(v, 0, sizeof(v));
			v[i] = 1;
			while (!v[k])
			{
				j ++;
				v[k] = 1;
				k = p[k];
			}
			if (k != i) continue;
			ans = max(ans, j);
			if (p[p[i]] == i)
			{
				tmp += dfs(i, p[i]) + dfs(p[i], i);
			}
		}
		ans = max(ans, tmp / 2);
		printf("Case #%d: %d\n", ++ zzz, ans);
	}
}

