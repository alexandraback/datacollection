#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

long long rev(long long n) {
	long long r = 0;
	while (n) {
		r *= 10;
		r += n % 10;
		n /= 10;
	}
	return r;
}

long long pow10[] = {
	1LL,
	10LL,
	100LL,
	1000LL,
	10000LL,
	100000LL,
	1000000LL,
	10000000LL,
	100000000LL,
	1000000000LL,
	10000000000LL,
	100000000000LL,
	1000000000000LL,
	10000000000000LL,
	100000000000000LL,
	1000000000000000LL,
	10000000000000000LL
};

int digs(long long n) {
	int r = 1;
	for (long long p = 10; p <= n; p *= 10) r++;
	return r;
}

long long solve(long long n, long long c = 0) {
//	cerr << n << ", " << c << endl;
	c += (n - 1) % 10; // get to the next ##1
	n -= (n - 1) % 10;
	long long r;
	if (n > 1000) {
		// bring it down to xx00?1 first
		// i.e. get rid of the right half of digits! :)
		int d = digs(n);
		d = d - d / 2;
		c += n % pow10[d] - 1;
		n -= n % pow10[d] - 1;
//		cerr << "## " << n << " " << c << endl;
		r = rev(n);
		if (r == n) {
			r -= 2;
			c++;
		}
	} else {
		r = rev(n);
		while (r >= n && n > 10) {
//			cerr << "-- " << r << " " << c << endl;
			c += 10;
			n -= 10;
			r = rev(n);
		}
//		cerr << "== " << r << " " << c << endl;
	}
	if (n <= 10) {
		return c + n;
	}
	++c; // the reverse
	return solve(r, c);
}

int main() {
	int T;
	cin >> T;
	for (int t = 0; t++ < T;) {
		long long N, c = 0, m;
		ostringstream oss;
		string s;

		cin >> N;
		N = solve(N);
		cout << "Case #" << t << ": " << N << endl;
//		cerr << "Case #" << t << ": " << N << endl;
	}
	return 0;
}
