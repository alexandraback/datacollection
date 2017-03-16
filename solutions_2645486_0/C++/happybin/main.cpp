#include <stdio.h>
#include <math.h>

int E, R, N;
int v[20];

int dp[20][20];

int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("AB-small-attempt0.out", "w", stdout);
	int T, nt = 0;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d%d", &E, &R, &N);
		for (int i = 1; i <= N; ++i)
			scanf("%d", &v[i]);
		for (int j = 0; j <= E; ++j)
			dp[0][j] = 0;

		for (int i = 0; i <= N+1; ++i)
			for (int j = 0; j <= E; ++j)
			{
				dp[i][j] = 0;
			}
		for (int i = 1; i <= N; ++i)
			for (int j = 0; j <= E; ++j)
			{
				for (int k = 0; k <= j; ++k)
				{
					int t = (j-k+R);
					if (t > E) t = E;
					if (dp[i+1][t] < dp[i][j]+k*v[i])
						dp[i+1][t] = dp[i][j]+k*v[i];
				}
			}
		int ans = 0;
		for (int j = 0; j <= E; ++j)
			if (dp[N+1][j] > ans)
				ans = dp[N+1][j];
		printf("Case #%d: %d\n", ++nt, ans);
	}
	return 0;
}