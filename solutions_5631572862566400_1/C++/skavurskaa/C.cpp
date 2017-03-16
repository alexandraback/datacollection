#include <bits/stdc++.h>
using namespace std;

int N, BFF[1111], X, visited[1111];
vector<int> INV[1111];

int dfs(int root, int cur)
{
	if (visited[cur]) return -9999999;
	visited[cur] = 1;
	if (BFF[cur] == root) return 1;
	return dfs(root, BFF[cur]) + 1;
}

int dp[1111];
int lp(int root)
{
	if (dp[root] == -1)
	{
		int ret = 1;
		for (auto v : INV[root])
			if (v != BFF[root])
				ret = max(ret, lp(v)+1);
		dp[root] = ret;
	}
	return dp[root];
}

int main()
{
	ios_base::sync_with_stdio(false);
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++)
	{
		scanf("%d", &N);
		for (int i = 0; i < N; i++) INV[i].clear();
		for (int i = 0; i < N; i++)
		{
			scanf("%d", &X); X--;
			BFF[i] = X;
			INV[X].push_back(i);
		}

		int ret = 0;
		for (int i = 0; i < N; i++)
		{
			memset(visited,0,sizeof(visited));
			ret = max(ret, dfs(i,i));
		}

		memset(dp,-1,sizeof(dp));
		int cntbff = 0;
		for (int i = 0; i < N; i++)
			if (BFF[BFF[i]] == i && BFF[i] > i)
				cntbff += lp(i) + lp(BFF[i]);

		ret = max(ret, cntbff);
		printf("Case #%d: %d\n", t, ret);
	}
}
