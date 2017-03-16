#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define MAXN 110

long long cap[MAXN][2];
int tp[MAXN][2];

long long dp[MAXN][MAXN];

int n, m;

void Solve()
{
	int i, j, ii, jj;
	long long ti, tj, ret = 0;
	memset (dp, 0, sizeof dp);
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++)
		scanf("%I64d%d", &cap[i][0], &tp[i][0]);
	for (i = 1; i <= m; i++)
		scanf("%I64d%d", &cap[i][1], &tp[i][1]);
	memset (dp, 0, sizeof dp);
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
		{
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			if (tp[i][0] == tp[j][1])
				for (ii = i - 1, ti = 0; ii >= 0; ii--)
				{
					if (tp[ii + 1][0] == tp[i][0])
						ti += cap[ii + 1][0];
					for (jj = j - 1, tj = 0; jj >= 0; jj--)
					{
						if (tp[jj + 1][1] == tp[j][1])
							tj += cap[jj + 1][1];
						dp[i][j] = max(dp[i][j], dp[ii][jj] + min(ti, tj));
					}
				}
		}
	// for (i = 0; i <= n; i++)
	// {
		// for (j = 0; j <= m; j++)
			// printf("%3I64d ", dp[i][j]);
		// printf("\n");
	// }
	for (i = 0; i <= n; i++)
		ret = max(ret, dp[i][m]);
	for (i = 0; i <= m; i++)
		ret = max(ret, dp[n][i]);
	printf("%I64d\n", ret);
}

int main()
{
	int i, cas;
	scanf("%d", &cas);
	for (i = 1; i <= cas; i++)
	{
		printf("Case #%d: ", i);
		Solve();
	}
	return 0;
}
