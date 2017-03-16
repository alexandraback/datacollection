#include <bits/stdc++.h>
using namespace std;

const int N = int(2e6);

int dp[N], que[N];

int main ()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int tk;
	cin >> tk;
	dp[1] = 1;
	int f = 0, r = 0;
	que[++r] = 1;
	while (f != r)
	{
		int u = que[++f];
		if (u + 1 < N && !dp[u + 1]) dp[que[++r] = u + 1] = dp[u] + 1;
		int a = 0, b = u;
		while (b) a = a * 10 + b % 10, b /= 10;
		if (a < N && !dp[a]) dp[que[++r] = a] = dp[u] + 1;
	}
	int t = 0;
	while (tk--)
	{
		int s;
		cin >> s;
		cout << "Case #" << ++t << ": " << dp[s] << endl;
	}
}
