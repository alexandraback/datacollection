#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 0x3fffffff;
const int N = 1000008;
int dp[N];

int reverse(int num) {
	int ret = 0;
	for (int t = num; t; t/= 10) {
		ret = ret*10+t%10;
	}
	return ret;
}

int main() {
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	int T;
	scanf("%d", &T);
	int maxN = 1000000;
	for (int i = 1; i <= 1000000; i++) {
		dp[i] = INF;
	}
	dp[1] = 1;
	for (int i = 1; i <= 1000000; i++) {
		if (i+1 <= 1000000) {
			dp[i+1] = min(dp[i+1], dp[i]+1);
		}
		int rev = reverse(i);
		if (rev <= 1000000) {
			dp[rev] = min(dp[rev], dp[i]+1);
		}
	}
	for (int cas = 1; cas <= T; cas++) {
		int n;
		scanf("%d", &n);
		printf("Case #%d: %d\n", cas, dp[n]);
	}
	return 0;
}