#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAXN = 100;

int N, X, Y;
double ans;
double dp[4000][4000];

int aabs(int x)
{
	if (x < 0)
		return -x;
	return x;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++) {
		scanf("%d %d %d", &N, &X, &Y);
		int h = 1;
		while(h * (2 * h - 1) <= N)
			h++;
		h--;
		int n = N - (h * (2 * h - 1));
		h--;
		if ((aabs(X) + aabs(Y)) / 2 <= h)
		{
			ans = 1;
		} else
		if ((aabs(X) + aabs(Y)) / 2 > h + 1)
		{
			ans = 0;
		} else
		if (n == 0)
		{
			ans = 0;
		} else
		{
			h += 2;
			h = 2 * h - 1;
			int x = h - aabs(X);
			for(int i = 0; i <= n; i++)
				for(int j = 0; j <= h; j++)
					dp[i][j] = 0;
			dp[0][0] = 1;
			for(int i = 0; i < n; i++)
				for(int j = 0; j <= i && j < h; j++)
				{
					if (j == h - 1)
						dp[i + 1][j] += dp[i][j];
					else
					if ((i - j) == h - 1)
						dp[i + 1][j + 1] += dp[i][j];
					else
						dp[i + 1][j + 1] += dp[i][j] / 2, dp[i + 1][j] += dp[i][j] / 2;
				}
			ans = 0;
			for(int i = x; i < h; i++)
				ans += dp[n][i];
		}
		printf("Case #%d: %.6lf\n", t, ans);
	}
	return 0;
}
