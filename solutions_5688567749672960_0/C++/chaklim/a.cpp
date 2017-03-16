#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

int t, n, tn;
const int l = 1000005;
int dp[l];

int reverse(int n) {
	int tn = 0;
	while (n) {
		tn *= 10;
		tn += n % 10;
		n /= 10;
	}

	return tn;
}

int main() {
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i < l; i++) {
		dp[i] = 21474837;
	}

	for (int i = 2; i < l; i++) {
		tn = reverse(i);

		dp[i] = min(dp[i], dp[i-1] + 1);

		if (tn > i && tn < l) {
			dp[tn] = min(dp[tn], dp[i] + 1);
		}

		// if (i < 30) {
		// 	printf("%d: %d, %d: %d\n", i, dp[i], tn, (tn < l? dp[tn] : -1));
		// }
	}

	cin >> t;
	for (int C = 1; C <= t; C++) {
		printf("Case #%d: ", C);

		cin >> n;
		printf("%d\n", dp[n]);
	}
	return 0;
}
