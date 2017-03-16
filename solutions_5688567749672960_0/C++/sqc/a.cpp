#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

int reverse(int i) {
	int res = 0;
	while (i != 0) {
		res *= 10;
		res += i % 10;
		i = i / 10;
	}
	return res;
}

int main() {
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	//freopen("A-large.in", "r", stdin);
	//freopen("A-large.out", "w", stdout);
	int t;
	scanf("%d", &t);
	vector<int> dp(1000002, 0);
	for (int i = 1; i < 1000002; i++) {
		dp[i] = i;
	}
	int rev;
	for (int i = 2; i < 1000002; i++) {
		dp[i] = min (dp[i], dp[i - 1] + 1);
		rev = reverse(i);
		dp[rev] = min(dp[rev], dp[i] + 1);
	}
	int n;
	for (int tt = 1; tt <= t; tt++) {
		scanf("%d", &n);
		printf("Case #%d: %d\n", tt, dp[n]);
	}
	return 0;
}