#include <iostream>
#include <cstring>
#include <string>

using namespace std;

typedef long long i64;

int main() {
	int T;
	cin >> T;
	for (int tt = 0; tt < T; ++tt) {
		i64 a, b;
		scanf("%lld/%lld", &a, &b);
		i64 d = __gcd(a, b);
		a /= d;
		b /= d;
		i64 x = b;
		while (x > 1 && !(x & 1)) {
			x >>= 1;
		}
		if (x > 1) {
			printf("Case #%d: impossible\n", tt + 1);
		} else {
			int r = 0;
			while (a < b) {
				a <<= 1;
				++r;
			}
			printf("Case #%d: %d\n", tt + 1, r);
		}
	}
	return 0;
}
