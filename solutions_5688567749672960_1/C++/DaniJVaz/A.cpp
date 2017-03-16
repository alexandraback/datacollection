#include <cstdio>
#include <algorithm>
#include <vector>

typedef long long ll;

using namespace std;

ll llPow(ll b, ll n) {
	ll r = 1;
	for (int i=0; i<n; i++)
		r *= b;
	return r;
}

ll invert(ll n) {
	ll r = 0;
	while (n) {
		r = 10*r + (n%10);
		n /= 10;
	}
	return r;
}

ll len(ll a) {
	ll l = 0;
	while (a) {
		a /= 10;
		l ++;
	}
	return l;
}

int main() {
	int iC=0, nC;
	scanf("%d", &nC);

	ll lim = 1000000;
	ll *table = new ll[lim+1];
	for (int i=0; i<=lim; i++)
		table[i] = i;

	for (int i=1; i<=lim; i++) {
		ll inv = invert(i);
		if (i+1 <= lim)
			table[i+1] = min(table[i+1], table[i] + 1);
		if (inv <= lim)
			table[inv] = min(table[inv], table[i] + 1);
	}

	for (iC=1; iC<=nC; iC++) {
		ll N;
		scanf("%I64d", &N);

		ll c = 0;

		ll a = N;
		while (a > 20) {
			ll l = len(a);

			ll b = (a / llPow(10, l/2)) * llPow(10, l/2) + 1;
			if (b > a)		// Can't go to this invert point, must go to next
				b -= llPow(10, l/2);

			//printf("%I64d %I64d\n", a, invert(b));
			if (b <= a and invert(b)+1 < b) {
				c += a-b+1;
				a = invert(b);
			}

			if (a >= (llPow(10, l-1)-1)) {
				c += a - (llPow(10, l-1)-1);
				a = (llPow(10, l-1)-1);
			}
		}

		c += a;

		/*if (c != table[N])
			printf("AA %I64d %I64d %I64d\n", N, c, table[N]);*/

		if (N <= lim)
			c = table[N];

		printf("Case #%d: %I64d\n", iC, c);
	}
	return 0;
}