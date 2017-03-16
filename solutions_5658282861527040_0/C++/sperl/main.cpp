#include <stdio.h>

#include <vector>
#include <list>
#include <limits.h>
#include <string.h>
#include <math.h>

#define ll long long

#define N_MAX 102


void solve() {

	ll A, B, K;
	
	scanf("%lld %lld %lld", &A, &B, &K);
	
	ll amount = 0;
	
	for (ll i = 0; i < A; i++) {
		for (ll j = 0; j < B; j++) {
			ll x = i&j;
			if (x < K)
				amount++;
		}
	}
	
	printf("%lld", amount);
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


