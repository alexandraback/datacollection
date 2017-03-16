#include <cstdio>

using namespace std;

typedef long long ll;

const ll MAXR = 1100000000;
const ll infl = 1LL << 62;
int T;
ll r, t;

ll f(ll n) { // #ml paint for n rings
	ll fac = (2 * r + 1 + 2 * (n - 1));
	if (infl / n <= fac) return infl;
	return fac * n;
}

int main() {
	scanf("%d", &T);
	for(int test = 1; test <= T; ++test) {
		scanf("%lld %lld", &r, &t);

		ll lo = 0, hi = MAXR;
		while (lo < hi) {
			ll mid = (lo + hi + 1) / 2;
			if (f(mid) <= t) {
				lo = mid;
			} else {
				hi = mid - 1;
			}
		}

		printf("Case #%d: %lld\n", test, lo);
	}
	return 0;
}
