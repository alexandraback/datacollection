#include <stdio.h>

#define N_MAX 151
#define ll long long

void fraction(ll& p, ll&q) {
	while(p%2 == 0) {
		p = p/2;
		q = q/2;
	}
}

void fraction2(ll& p, ll&q) {
	
	ll x = q;
	while(x%2 == 0) {
		x /= 2;
	}
	
	if (x == 1) {
		fraction(p, q);
	}
	else {
		if (p % x == 0) {
			p /= x;
			q /= x;
			fraction(p, q);
		}
	}
	
}

int sol(ll p, ll q) {
	if (p == q) {
		return 0;
	}
	
	if (p == q-1)
		return 1;
	
	if (p*2 > q) 
		return 1;
	
	
	q/=2;
	
	//fraction(p, q);
	
	return 1+ sol(p, q);
}

void solve() {
	
	ll P,Q;
	
	scanf("%lld/%lld", &P, &Q);

	fraction2(P, Q);
	
	int level = 0;
	ll n = 1;
	while(Q > n) {
		level++;
		n = n*2;
	}
	
	if (Q != n) {
		printf("impossible");
		return;
	}
	
	printf("%d", sol(P, Q));	
}

int main() {
	
	int T = 0;
	scanf("%d", &T);

	for (int t = 1; t <= T; t++)  {
		printf("Case #%d: ", t);
		solve();
		printf("\n");
	}
}


