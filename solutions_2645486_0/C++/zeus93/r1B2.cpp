#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 15
#define E 10
#define max(a,b) ((a)>(b)?(a):(b))
int val[N];
int dp[N][E];
int main()
{
	int tcase, icase = 1;
	int i, j, k;
	int e, r, n;
	scanf("%d", &tcase);
	while(tcase--)
	{
		scanf("%d%d%d", &e, &r, &n);
		for(i = 0; i < n; i++)
			scanf("%d", &val[i]);
		memset(dp, 0, sizeof(dp));
		if(r > e)
			r = e;
		for(i = r; i <= e; i++)
		{
			dp[0][i] = (e - (i - r)) * val[0];
		}
		for(i = 1; i < n; i++)
		{
			for(j = r; j <= e; j++)
			{
				for(k = max(r, j - r); k <= e; k++)
				{
					dp[i][j] = max(dp[i][j], dp[i - 1][k] + (k - (j - r)) * val[i]);
				}
			}
		}
		int ans = 0;
		for(i = r; i <= e; i++)
			ans = max(ans, dp[n - 1][i]);
		printf("Case #%d: %d\n", icase++, ans);
	}
	return 0;
}
