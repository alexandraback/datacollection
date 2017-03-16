#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

typedef long long LL;

LL dp[101][101];
LL a[100], b[100];
int A[100], B[100];

int main() {
	int tc, n, m;
	scanf("%d", &tc);
	for (int scen=1; scen<=tc; ++scen)
	{
		scanf("%d %d", &n, &m);
		for (int i=0; i<n; ++i)
			scanf("%lld %d", &a[i], &A[i]);
		for (int i=0; i<m; ++i)
			scanf("%lld %d", &b[i], &B[i]);
		printf("Case #%d: ", scen);
		memset(dp, -1, sizeof(dp));
		dp[0][0] = 0;
		for (int i=0; i<n; ++i)
		{
			for (int j=0; j<m; ++j)
			{
				if (dp[i][j] == -1)
					continue;
				// now try to throw i away
				dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
				// try to throw j away
				dp[i][j+1] = max(dp[i][j+1], dp[i][j]);
				if (A[i] != B[j])
					continue;
				// now try to match
				LL c1 = 0;
				for (int ii=i; ii<n; ++ii)
				{
					LL c2 = 0;
					if (A[ii] == A[i])
						c1 += a[ii];
					for (int jj=j; jj<m; ++jj)
					{
						if (B[jj] == B[j])
							c2 += b[jj];
						dp[ii+1][jj+1] = max(dp[ii+1][jj+1], dp[i][j] + min(c1, c2));
					}
				}
			}
			dp[i+1][m] = max(dp[i+1][m], dp[i][m]);
		}
		printf("%lld\n", max(dp[n][m-1], dp[n][m]));
	}
	return 0;
}
