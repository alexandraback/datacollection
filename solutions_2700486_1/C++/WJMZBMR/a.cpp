#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include <cmath>
using namespace std;

const int MAX_N = int(1e6) + 10;

double calc(int tot, int at, int rem, int x) {
	static double dp[100][100];
	for (int i = 0; i < 100; ++i) {
		for (int j = 0; j < 100; ++j) {
			dp[i][j] = 0;
		}
	}
	dp[0][0] = 1;
	for (int i = 0; i <= rem; ++i) {
		for (int j = 0; i + j <= rem; ++j) {
			double c = dp[i][j];
			if (c < 1e-8)
				continue;
			if (i < tot / 2 && j < tot / 2) {
				dp[i + 1][j] += c / 2;
				dp[i][j + 1] += c / 2;
				continue;
			}
			if (i == tot / 2) {
				dp[i][j + 1] += c;
				continue;
			}
			if (j == tot / 2) {
				dp[i + 1][j] += c;
				continue;
			}
		}
	}
	double ans = 0;
	for (int i = 0; i <= rem; ++i) {
		int j = rem - i;
		double c = dp[i][j];
		if (c == 0)
			continue;
		if (x < 0 && i > at)
			ans += c;
		if (x > 0 && i > at)
			ans += c;
	}
	return ans;
}

typedef long long int64;

double work() {
	int n, x, y;
	cin >> n;
	cin >> x >> y;
	int64 before = 0;
	int d = abs(x) + abs(y);
	int cur = 1;
	for (int i = 0; i < d; i += 2) {
		before += cur;
		cur += 4;
	}
	if (before >= n) {
		return 0.0;
	}
	int tot = cur;
	int at = abs(y);
	int rem = n - before;
	if (rem >= tot)
		return 1.0;
//	if (x == 0)
//		return 0.0;

//C(rem,0)..C(rem,rem)

	long double prob = powl(0.5, rem);
	long double ans = 0;
	for (int goLeft = 0; goLeft <= rem; ++goLeft) {
		int left = goLeft;
		int right = rem - left;
		if (left > tot / 2) {
			left = tot / 2;
			right = rem - left;
		}
		if (right > tot / 2) {
			right = tot / 2;
			left = rem - right;
		}
		bool ok = false;
		if (x < 0 && left > at) {
			ok = true;
		}
		if (x > 0 && right > at) {
			ok = true;
		}
		if (x == 0 && (left > at || right > at)) {
			ok = true;
		}
		if (ok)
			ans += prob;
		//C(rem,goLeft) -> C(rem,goLeft+1)
		prob *= (rem - goLeft);
		prob /= goLeft + 1;
	}
//	cerr << ans << " " << calc(tot, at, rem, x) << endl;
//	if (x == 0)
//		cerr << ans << endl;
	return ans;
}

int main() {
	int T;
	cin >> T;
	for (int i = 1; i <= T; ++i) {
		printf("Case #%d: %0.6lf\n", i, work());
	}
}
