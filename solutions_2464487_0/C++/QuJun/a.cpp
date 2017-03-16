#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int test;
	cin >> test;
	for (int tt = 1; tt <= test; tt++) {
		long long r, t;
		cin >> r >> t;
		long long lo = 0, hi = sqrt(t);
		while (lo < hi) {
			long long mid = (lo + hi) >> 1;
			if ((4 * r + 2 + mid * 4) <=  2 * t / (mid + 1)) {
				lo = mid;
			} else {
				hi = mid - 1;
			}
			if (hi == lo + 1) {
				if ((4 * r + 2 + hi * 4) <= 2 * t / (hi + 1)) {
					lo = hi;
				} else {
					hi = lo;
				}
			}
		}
		cout << "Case #" << tt << ": " << lo + 1 << endl;
	}
}