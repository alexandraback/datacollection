#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <map>
#include <string>

using namespace std;

#define int64 long long

inline int64 square_sum (int64 n) {
	return (n * (n+1) * (2*n+1) / 2);
}

bool candraw (int64 mid, int64 r, int64 t) {
	double test = double(mid) * double(2.0*r + 2.0*mid - 1.0);
	if (test > 1000000000000000000LL) {
		return !(test>t);
	}
	else {
		int64 sum = mid * (2*r + 2*mid - 1);
		return sum <=t;
	}
}

int64 find (int64 r, int64 t) {
	int64 a = 1;
	int64 b = 1000000000LL;
	b *= 2;

	while (a < b) {
		int64 mid = (a+b) / 2;
		if (candraw (mid, r, t)) {
			a = mid;
			if (b-a==1) {
				if (candraw (b, r, t))
					return b;
				else
					return a;
			}
		}
		else {
			b = mid - 1;
		}
	}

	return a;
}

int main () {
	int testcases;

	cin >> testcases;

	for (int testcase=1; testcase<=testcases; testcase++) {
		cout << "Case #" << testcase << ": ";
		int64 r, t;
		cin >> r >> t;
		cout << find (r, t);

		cout << endl;
	}

	return 0;
}
