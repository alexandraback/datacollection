#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 52;

typedef long long ll;

int ans[N][N];
ll dp[N];
ll f[N];

bool solve(int b, ll M)
{
	if (M > dp[b])
		return false;
	ll M0 = M;
	int n = 0;
	for (int i = 0; i < b; i ++)
		for (int j = 0; j < b; j ++)
			ans[i][j] = 0;
	if (!M)
		return true;
	for (int i = 1; i <= b; i ++)
			if (dp[i] <= M && dp[i+1] > M)
			{
				//printf("b, M, n = %d, %lld, %d\n", b, M, i);
				n = i; M -= dp[i];
				for (int j = 2; j <= n; j ++)
					for (int k = j-1; k >= 1; k --)
						ans[b-j][b-k] = 1;
				break;
			}
	if (M && n < b)
	{
		n ++; ans[b-n][b-n+1] = 1;
		//printf("%d(%d), %lld\n", b, n, M);
		for (int i = 0; i < n; i ++)
			if (M & (1LL << i))
			{
				M -= 1LL << i;
				ans[b-n][b-2-i] = 1;
			}
	}
	if (M != 0)
		return false;
	for (int i = n+1; i <= b; i ++)
		ans[b-i][b-i+1] = 1;
	return true;
}

int main()
{
	freopen("b3.in", "r", stdin);
	freopen("b.out", "w", stdout);
	
	dp[1] = 0;
	for (int i = 2; i <= 50; i ++){
		dp[i] = 1;
		for (int j = 1; j < i; j ++)
			dp[i] += dp[j];
		//printf("%d: %lld\n", i, dp[i]);
	}
	
	int T = 0;
	scanf("%d", &T);
	for (int t = 1; t <= T; t ++)
	{
		int b; ll M;
		scanf("%d%lld", &b, &M);
		
		printf("Case #%d:", t);
		if (solve(b, M))
		{
			puts(" POSSIBLE");
			for (int i = 0; i < b; i ++, puts(""))
				for (int j = 0; j < b; j ++) printf("%d", ans[i][j]);
		}
		else
		{
			puts(" IMPOSSIBLE");
		}
	}
	return 0;
}
