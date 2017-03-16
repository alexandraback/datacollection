#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 128;

__int64 min(__int64 a, __int64 b)
{
	return a < b ? a : b;
}

__int64 max(__int64 a, __int64 b)
{
	return a > b ? a : b;
}

__int64 a[N], b[N];
__int64 ac[N], bc[N];
__int64 dp[N][N];
__int64 acnt[N][N][N], bcnt[N][N][N];

int main()
{
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small.out", "w", stdout);
	
	//freopen("C-large-practice.in", "r", stdin);
	//freopen("C-large.out", "w", stdout);
	int i, j, k, kk;
	int cas;
	int T;
	scanf("%d", &T);
	for(cas = 1; cas <= T; cas ++)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		for(i = 1; i <= n; i ++)
		{
			scanf("%I64d %I64d", &ac[i], &a[i]);
		}
		for(i = 1; i <= m; i ++)
		{
			scanf("%I64d %I64d", &bc[i], &b[i]);
		}
		memset(acnt, 0, sizeof(acnt));
		for(i = 1; i <= m; i ++)
		{
			for(j = i; j <= m; j ++)
			{
				for(k = 1; k <= 100; k ++)
				{
					acnt[i][j][k] = acnt[i][j-1][k];
					if(k == a[j])acnt[i][j][k] += ac[j];
				}
			}
		}
		
		memset(bcnt, 0, sizeof(bcnt));
		for(i = 1; i <= m; i ++)
		{
			for(j = i; j <= m; j ++)
			{
				for(k = 1; k <= 100; k ++)
				{
					bcnt[i][j][k] = bcnt[i][j-1][k];
					if(k == b[j])bcnt[i][j][k] += bc[j];
				}
			}
		}
		memset(dp, 0, sizeof(dp));
		__int64 ans = 0;
		for(i = 1; i <= n; i ++)
		{
			for(j = 1; j <= m; j ++)
			{
				dp[i][j] = dp[i-1][j];
				for(k = 1; k <= j; k ++)
				{
					for(kk = 1; kk <= i; kk ++)
					{
						dp[i][j] = max(dp[i][j] , dp[kk-1][k-1] + min(bcnt[k][j][a[i]], acnt[kk][i][a[i]]));
					}
				}
				if(dp[i][j] > ans)ans = dp[i][j];
				//printf("%I64d ", dp[i][j]);
			}
			//putchar('\n');
		}
		printf("Case #%d: %I64d\n", cas, ans);
	}
	return 0;
}
