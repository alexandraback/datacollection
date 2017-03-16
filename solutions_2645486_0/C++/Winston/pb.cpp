#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int V[10010];

int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("outb.txt", "w", stdout);
	int T;
	int tt = 1;
	scanf("%d", &T);
	while(T--)
	{
		int E, R, N;
		scanf("%d%d%d", &E, &R, &N);

		int i, j, k;
		for(i = 1 ; i <= N ; i++)
		{
			scanf("%d", &V[i]);
		}

		int dp[15][10];
		memset(dp, 0, sizeof(dp));

		for(i = 1 ; i <= N ; i++)
		{
			for(j = 0 ; j <= E ; j++)
			{
				for(k = j ; k >= 0 ; k--)
				{
					int nE = j-k+R;
					if(nE > E) nE = E;

					dp[i+1][nE] = 
						max(dp[i+1][nE], dp[i][j]+k*V[i]);
				}
			}
		}
		int ans = 0;
		for(i = 0 ; i <= E ; i++)
		{
			ans = max(ans, dp[N+1][i]);
		}
		printf("Case #%d: %d\n", tt, ans);
		tt++;
	}
	return 0;
}
