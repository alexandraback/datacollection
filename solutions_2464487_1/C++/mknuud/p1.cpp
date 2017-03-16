// g++ -std=c++0x p1.cpp; ./a.out < IN > OUT
#include <cmath>
#include <iostream>
using namespace std;

size_t f(size_t k, size_t r) {
	return k * (2 * k + 2 * r - 1);
}

size_t dw() {
	size_t r, t;
	cin >> r >> t;
	size_t lo = 0, hi = 1;
	while (f(hi, r) <= t) {
		hi = 2 * hi;
	}
	// cout << hi << endl;

	while (lo <= hi) {
		size_t mid = lo + (hi - lo) / 2;
		// cout << lo << " " << hi << " " << mid << " " << f(mid, r) << endl;
		if (f(mid, r) < t) {
			// cout << f(mid + 1, r) << endl;
			if (f(mid + 1, r) > t) {
				return mid;
			}
			lo = mid + 1;
		} else if (f(mid, r) == t) {
			return mid;
		} else {
			hi = mid - 1;
		}
	}

	// cout << "..." << endl;
	return lo;
}

int main() {
	size_t T;
	cin >> T;
	for (size_t i = 0; i < T; i++) {
		cout << "Case #" << (i + 1) << ": " << dw() << endl;
	}
	return 0;
}
