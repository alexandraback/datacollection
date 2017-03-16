#include <iostream>
#include <ostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;

#define ABS(x)	((x) < 0) ? -(x) : (x);

long gcd(long u, long v) {
    while ( v != 0) {
        long r = u % v;
        u = v;
        v = r;
    }

    return u;
}

int main() {
	int T; cin >> T;

	for (int t = 1; t <= T; ++t) {
		char trash;
		long p, q; cin >> p >> trash >> q;
		long res = -1;

		long g = gcd(p, q);
		p /= g;
		q /= g;

		if ((q > 1) && !(q & (q - 1))) { // q is power of two
			res = 1;
			long d = 2;
			while (p < q/d) {
				d <<= 1;
				++res;
			}
			cout << "Case #" << t << ": " << res << endl;
		} else {
			cout << "Case #" << t << ": impossible" << endl;			
		}
	}

	return 0;
}