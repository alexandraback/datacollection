#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int a[64][64];

long long gao(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	return 1 << (n - 2);
}

long long countWay(int b) {
	vector<long long> dp(b);
	dp[0] = 1;
	for (int i = 1; i < b; ++i) {
		for (int j = 0; j < i; ++j) {
			if (a[j][i]) dp[i] += dp[j];
		}
	}
	return dp[b-1];
}

bool test(int b, int m, int step) {
	if (step == b * b) {
		if (countWay(b) == m) return true;
		else return false;
	}

	int i = step / b, j = step % b;

	a[i][j] = 0;
	if (test(b, m, step + 1)) return true;

	if (i < j) {
		a[i][j] = 1;
		if (test(b, m, step + 1)) return true;
	}
	return false;
}

int main() {
	int T;
	cin >> T;
	for (int re = 1; re <= T; ++re) {
		long long b, m, n;
		cin >> b >> m;
		// cout << test(b, m, 0) << endl;
		memset(a, 0, sizeof(a));
		n = b;

		cout << "Case #" << re << ": ";

		while (m > 0) {
			if (gao(n) < m) {
				cout << "IMPOSSIBLE" << endl;
				break;
			}

			while (gao(n) > m) {
				--n;
			}

			if (n != b) a[n - 1][b - 1] = 1;
			for (int i = 0; i < n; ++i) {
				for (int j = i + 1; j < n; ++j) {
					a[i][j] = 1;
				}
			}

			m -= gao(n);
		}

		if (m == 0) {
			cout << "POSSIBLE" << endl;
			for (int i = 0; i < b; ++i) {
				for (int j = 0; j < b; ++j) {
					cout << a[i][j];
				}
				cout << endl;
			}
		}
	}
}