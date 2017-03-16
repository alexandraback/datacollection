#include <iostream>
#include <ostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;

#define ABS(x)	((x) < 0) ? -(x) : (x);

int main() {
	int T; cin >> T;

	for (int t = 1; t <= T; ++t) {
		long a, b, k; cin >> a >> b >> k;
		long res = 0;

		if (a > b) swap(a, b);

		if (k >= a) {
			res = a * b;
		} else {
			res = k * b;
			res += (a - k) * k;
			for (int i = k; i < a; ++i) {
				for (int j = k; j < b; ++j) {
					if ((i&j) < k) ++res;
				}
			}
		}

		cout << "Case #" << t << ": " << res << endl;
	}

	return 0;
}