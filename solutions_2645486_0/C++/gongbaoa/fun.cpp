#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int dp[11][6];
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int cas = 1; cas <= t; ++ cas)
	{
		int e, r, n;
		scanf("%d%d%d", &e, &r, &n);
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < n; ++ i)
		{
			int x;
			scanf("%d", &x);
			for (int j = 0; j <= e; ++ j)
				for (int k = 0; k <= j; ++ k)
					dp[i + 1][min(e, j - k + r)] = max(dp[i + 1][min(e, j - k + r)], dp[i][j] + k * x);
		}
		printf("Case #%d: %d\n", cas, dp[n][r]);
	}
	return 0;
}
