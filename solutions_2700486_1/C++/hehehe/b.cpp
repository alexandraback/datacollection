#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;

double dp[5000][5000];

int main() {

	int cases;
	cin >> cases;
	for (int t = 1; t <= cases; ++t) {
		int n, x, y;
		cin >> n >> x >> y;
		printf("Case #%d: ", t);
		int low = 1, high = 1000;
		while (low < high) {
			int mid = (low + high) / 2 + 1;
			if (2 * mid * mid - mid > n) {
				high = mid - 1;
			} else {
				low = mid;
			}
		}

		int k = low;
		// cout << k << endl;
		int diag = (abs(x) + abs(y)) / 2 + 1;

		if (diag <= k) {
			cout << "1.0" << endl;
			continue;
		}

		int nowLevel = k + 1;

		if (diag > nowLevel || (y % 2 == 0 && y / 2 + 1 == nowLevel)) {
			cout << "0.0" << endl;
			continue;
		}

		int oneside = nowLevel * 2 - 2;
		int position = y + 1;
		int filled = n - 2 * k * k + k;

		for (int i = 0; i <= filled; ++i) {
			for (int j = 0; j <= oneside; ++j) {
				dp[i][j] = 0.0;
			}
		}

		dp[0][0] = 1.0;
		for (int i = 0; i < filled; ++i) {
			for (int j = 0; j <= oneside && j <= i; ++j) {
				int otherside = i - j;
				if (j + 1 <= oneside) {
					if (otherside < oneside) {
						dp[i + 1][j + 1] += dp[i][j] * 0.5;
					} else {
						dp[i + 1][j + 1] += dp[i][j];
					}
				}

				if (otherside + 1 <= oneside) {
					if (j < oneside) {
						dp[i + 1][j] += dp[i][j] * 0.5;
					} else {
						dp[i + 1][j] += dp[i][j];
					}
				}

			}
		}

		double answer = 0;
		for (int i = position; i <= oneside; ++i) {
			answer += dp[filled][i];
		}

		printf("%.12f\n", answer);
	}
	return 0;
}