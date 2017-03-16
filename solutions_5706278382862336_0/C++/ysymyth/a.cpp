#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

long long gcd(long long a, long long b) {
	return b ? gcd(b, a % b) : a; 
}

int main() {
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);

	int _; cin >> _;
	for (int __ = 1; __ <= _; ++ __) {
		printf("Case #%d: ", __);
		long long p, q; 
		scanf("%lld/%lld", &p, &q);
		long long d = gcd(p, q);
		p /= d, q /= d; 

		bool ok = false;
		int ii = -1;

		for (long long i = 0; i <= 40; ++ i) 
			if ((1ll << i) == q) {
				ii = i; 
				ok = true;
				break; 
			}

		int now; 
		for (now = 40; now >= 0; -- now)
			if ((p >> now) & 1) break;


		if (! ok) puts("impossible"); 
		else printf("%d\n", ii - now); 
	}

	return 0; 
}