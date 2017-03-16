#include "cmath"
#include "cstdio"
#include "algorithm"
#include "map"
#include "numeric"
#include "queue"
#include "set"
#include "string"
#include "utility"
#include "vector"
#include "iostream"
#include "iomanip"

using namespace std;

map <pair<int, pair<int, int>>, long long> dp;

long long solve(int a, int b, int k) {
	long long res;
	auto p = make_pair(a, make_pair(b, k));
	auto val = dp.find(p);
	if (val != dp.end()) {
		res = val->second;
	}
	else {
		int m = 1 << 30;
		for (; m > 0 && (m & a) == 0 && (m & b) == 0 && (m & k) == 0; m >>= 1);
		if (m == 0) {
			res = 0;
		} else
		if (m & k) {
			if ((m & a) == 0 || (m & b) == 0) {
				res = a * 1LL * b;
			}
			else {
				res = m * 1LL * a + m * 1LL * b - m * 1LL * m + solve(a - m, b - m, k - m);
			}
		}
		else {
			if ((a & m) == 0) {
				res = min(a, k) + solve(a, m - 1, k) + solve(a, b - m, k);
			}
			else if ((b & m) == 0) {
				res = min(b, k) + solve(m - 1, b, k) + solve(a - m, b, k);
			}
			else {
				res = solve(m - 1, m - 1, k) + 2LL * k + solve(a - m, m - 1, k) + solve(m - 1, b - m, k) + min(a - m, k) + min(b - m, k);
			}
		}
		dp[p] = res;
	}
	return res;
}

int main() {

	freopen("B-small-0.in", "r", stdin);
	freopen("B-small-0.out", "w", stdout);

	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int a, b, k;
		dp.clear();
		cin >> a >> b >> k;
		cout << "Case #" << t << ": " << solve(a, b, k) << endl;
	}
	
	return 0;
}
