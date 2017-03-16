#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int T, K, N;
int init[201];
int a[201], key[201][201];
int dp[1 << 20];

int comp(int a, int b)
{
	if (a == 0 && b == 0) return 0;
	int ret = comp(dp[a], dp[b]);
	if (ret < 0) return -1;
	if (ret > 0) return 1;
	if (a - dp[a] < b - dp[b]) return -1;
	if (a - dp[a] > b - dp[b]) return 1;
	return 0;
}

int main()
{
	freopen("D-small-attempt0.in", "r", stdin);
	freopen("D-small-attempt0.out", "w", stdout);
	cin >> T;
	for(int t = 1; t <= T; t++)
	{
		cin >> K >> N;
		memset(init, 0, sizeof(init));
		memset(key, 0, sizeof(key));
		for(int i = 0; i < K; i++)
		{
			int type;
			cin >> type;
			init[type]++;
		}
		for(int i = 0; i < N; i++)
		{
			int type;
			cin >> type;
			a[i] = type;
			key[i][type]--;
			int n;
			cin >> n;
			for(int j = 0; j < n; j++)
			{
				cin >> type;
				key[i][type]++;
			}
		}
		memset(dp, -1, sizeof(dp));
		dp[0] = 0;
		for(int i = 0; i < (1 << N); i++)
			if (dp[i] != -1)
			{
				int cur[201];
				memcpy(cur, init, sizeof(cur));
				for(int j = 0; j < N; j++)
					if (i & (1 << j))
						for(int k = 1; k <= 200; k++)
							cur[k] += key[j][k];
				for(int j = 0; j < N; j++)
					if (!(i & (1 << j)) && cur[a[j]] > 0)
					{
						int to = i | (1 << j);
						if (dp[to] == -1)
							dp[to] = i;
						else if (comp(i, dp[to]) < 0) dp[to] = i;
					}
			}
		if (dp[(1 << N) - 1] == -1) printf("Case #%d: IMPOSSIBLE\n", t);
		else
		{
			printf("Case #%d:", t);
			int cur = (1 << N) - 1;
			vector<int> ans;
			while (cur)
			{
				int c = cur - dp[cur];
				for(int i = 0; i < N; i++)
					if (c == (1 << i))
					{
						ans.push_back(i + 1);
						break;
					}
				cur = dp[cur];
			}
			for(int i = 0; i < N; i++) printf(" %d", ans[N - 1 - i]);
			printf("\n");
		}
	}
	return 0;
}
