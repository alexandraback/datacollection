#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int v[10000];
int dp[10][6];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		int E, R, N;
		cin >> E >> R >> N;
		for (int i = 0; i < N; i++)
			cin >> v[i];
		memset(dp, -1, sizeof(dp));
		for (int j = 0; j <= E; j++)
			dp[0][min(E, E - j + R)] = v[0] * j;
		for (int i = 0; i < N - 1; i++)
			for (int j = 0; j <= E; j++)
				if (dp[i][j] > -1)
					for (int k = 0; k <= j; k++)
					{
						int energy = min(E, j - k + R);
						dp[i + 1][energy] = max(dp[i + 1][energy], dp[i][j] + k * v[i + 1]);
					}
		int ans = 0;
		for (int j = 0; j <= E; j++)
			ans = max(ans, dp[N - 1][j]);
		printf("Case #%d: %d\n", t, ans);
	}
	return 0;
}