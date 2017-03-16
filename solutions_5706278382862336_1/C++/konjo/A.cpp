#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

long long gcd(long long a, long long b) {
	if(b > a)
		swap(a, b);
	
	if(!(a % b)) {
		return b;
	}
	else
		return gcd(b, a % b);
}

int main() {
	int T;
	long long P, Q;

	scanf("%d", &T);
	for(int t = 0; t < T; t++) {
		int ans = 0;
		scanf("%lld/%lld", &P, &Q);

		long long gcdpq;
		gcdpq = gcd(P, Q);
		P /= gcdpq;
		Q /= gcdpq;

		int impossible = 0;
		for(int i = 0; i <= 50; i++) {
			if(Q & ((long long)1 << i)) {
				impossible++;
			}
		}

		long double accume = 1;
		while(1) {
			if(accume <= ((long double)P / Q))
				break;
			ans++;
			accume /= 2;
		}

		cout << "Case #" << t + 1 << ": ";
		if(impossible != 1)
			cout << "impossible" << endl;
		else
			cout << ans << endl;
	}
}
