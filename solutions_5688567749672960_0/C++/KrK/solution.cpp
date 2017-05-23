#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

const int Maxn = 1000005;

int dp[Maxn];
int T;

int Rev(int x)
{
	int res = 0;
	while (x) {
		res = 10 * res + x % 10;
		x /= 10;
	}
	return res;
}

int main()
{
	fill(dp, dp + Maxn, Maxn); dp[1] = 1;
	queue <int> Q; Q.push(1);
	while (!Q.empty()) {
		int v = Q.front(); Q.pop();
		if (v + 1 < Maxn && dp[v] + 1 < dp[v + 1]) {
			dp[v + 1] = dp[v] + 1;
			Q.push(v + 1);
		}
		int r = Rev(v);
		if (r < Maxn && dp[v] + 1 < dp[r]) {
			dp[r] = dp[v] + 1;
			Q.push(r);
		}
	}
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		int n; scanf("%d", &n);
		printf("Case #%d: %d\n", tc, dp[n]);
	}
	return 0;
}