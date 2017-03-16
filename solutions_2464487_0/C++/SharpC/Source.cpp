#include <iostream>
#include <limits>
using namespace std;

long long f(long long r, int n) { return 2.0 * r * n > numeric_limits<long long>::max() ? numeric_limits<long long>::max() : 2LL * r * n + 2LL * n * (n + 1) - 3 * n; }

int main()
{
	int tests;
	cin >> tests;
	for (int test = 0; test < tests; ++test) {
		long long r, t;
		cin >> r >> t;
		int left = 0, right = 2000000000;
		while (right - left > 1) {
			int c = left + (right - left) / 2;
			if (f(r, c) > t) {
				right = c;
			} else {
				left = c;
			}
		}
		cout << "Case #" << test + 1 << ": " << left << endl;
	}
}
