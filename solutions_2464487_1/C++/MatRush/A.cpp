#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cassert>
#include <cstdlib>
#include <map>
#include <sstream>
#include <cmath>
using namespace std;
const double eps = 1e-8;
const double pi = acos(-1.0);
inline int sgn(double x) {
	return x < -eps ? -1 : x > eps;
}
bool check(long long r, long long t, long long mid) {
	return sgn(double((double)2 * r * mid + (1 + double(4 * mid - 3)) * mid / 2) - t) > 0;
}
int main() {
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	int cas;
	long long R, t;
	scanf("%d", &cas);
	for (int T = 1; T <= cas; T++) {
		cin >> R >> t;
		long long l = 1, r = 0x3FFFFFFFLL;
		while (l <= r) {
			long long mid = (l + r) / 2;
			if (check(R, t, mid)) {
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		printf("Case #%d: %lld\n", T, l - 1);
	}
	return 0;
}
