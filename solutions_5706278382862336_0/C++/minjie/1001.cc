#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <map>
typedef long long ll;

ll gcd(ll x, ll y) {
	if (y == 0) return x;	
	return gcd(y, x % y);
}
int is2(ll x) {
	for(int i = 0;i < 40; ++i) {
		if(1ll<<i == x) return i;
	}
	return -1;
}
int gao(ll x, ll y) {
	if (x == 1ll && is2(y) != -1) return is2(y);
	x *= 2ll;
	ll d = gcd(x, y);
	x /= d; y /= d;
	for(int i = 0;; ++i) {
		if ((1ll << i) * x >= y) return 1 + gao(1ll, 1ll<<i);
	}
}
int main() {
	int cas;
	scanf("%d", &cas);
	for(int it = 1;it <= cas; ++it) {
		printf("Case #%d: ", it);
		ll x, y;
		scanf("%lld/%lld", &x, &y);
		ll d = gcd(x, y);
		x /= d;
		y /= d;
		if(is2(y) == -1) {
			printf("impossible\n");
			continue;
		}
		printf("%d\n", gao(x, y));
	}
}
