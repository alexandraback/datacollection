#include <cstdio>
#include <cstring>
#define max(a, b) ((a) >= (b) ? (a) : (b))
#define min(a, b) ((a) <= (b) ? (a) : (b))
using namespace std;

int test, n, m, A[105], B[105];
long long ans, a[105], b[105], suma[105][105], sumb[105][105], dp[105][105];

long long geta(int type, int i, int j)
{
	return suma[j][type] - suma[i - 1][type];
}

long long getb(int type, int i, int j)
{
	return sumb[j][type] - sumb[i - 1][type];
}

int main()
{
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);
	scanf("%d", &test);
	for (int num = 1; num <= test; num++)
	{
		memset(dp, 0, sizeof(dp));
		ans = 0;
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; i++) scanf("%lld %d", &a[i], &A[i]);
		for (int j = 1; j <= m; j++) scanf("%lld %d", &b[j], &B[j]);
		for (int i = 1; i <= n; i++)
			for (int x = 1; x <= 100; x++)
			{
				suma[i][x] = suma[i - 1][x];
				if (x == A[i]) suma[i][x] += a[i];
			}
		for (int j = 1; j <= m; j++)
			for (int x = 1; x <= 100; x++)
			{
				sumb[j][x] = sumb[j - 1][x];
				if (x == B[j]) sumb[j][x] += 
			}
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				for (int k = 0; k < i; k++)
					for (int l = 0; l < j; l++)
					{
						dp[i][j] = max(dp[i][j], min(geta(A[i], k + 1, i), getb(A[i], l + 1, j)));
						dp[i][j] = max(dp[i][j], min(geta(B[j], k + 1, i), getb(B[j], l + 1, j)));
					}
				ans = max(ans, dp[i][j]);
			}
		printf("Case #%d: %lld\n", num, ans);
	}
	return 0;
}
