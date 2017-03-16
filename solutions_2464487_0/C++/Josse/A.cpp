#include <iostream>
#include <cassert>
#include <cmath>

using namespace std;

long double kw(long double x) { return x * x; }

void solve(int casenum) {
	long long _r, _t;
	cin >> _r >> _t;
	__int128_t r = _r;
	__int128_t t = _t;
	__int128_t lo = 0;
	__int128_t hi = sqrt(((long double) _t) / 2.0L) + 2.0L;
	while (hi - lo > 1) {
		__int128_t mid = (hi + lo) / 2;
		__int128_t cur = mid*mid*2 + (r*2 - 1)*mid;
		(cur <= t ? lo : hi) = mid;
	}
	long long ans = (long long) lo;
	cout << "Case #" << casenum << ": " << ans << endl;
}

int main() {
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) solve(i);
	return 0;
}
