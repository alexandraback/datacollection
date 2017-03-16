
#include <cstdio>

typedef long long ll;

ll g(ll a, ll b) {
	while ( a != 0 ) {
		ll r = b % a;
		b = a;
		a = r;
	}
	return b;
}

void p() {
	ll x, y;
	scanf("%lld/%lld", &x, &y);
	ll z = y / g(x, y);
	if ( z & (z-1) ) {
		printf("impossible\n");
		return;
	}
	int c = 0;
	while ( (x << c) < y )
		++c;
	printf("%d\n", c);
}


int main() {
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; ++i) {
		printf("Case #%d: ", i);
		p();
	}
	return 0;
}


