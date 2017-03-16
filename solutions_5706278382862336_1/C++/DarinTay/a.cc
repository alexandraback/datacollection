#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

#define ll long long

ll gcd(ll a, ll b) {
	if (b == 0)  return a;
	return gcd(b, a%b);
}

int main() {
	ll p, q;
	int T;
	scanf("%d", &T);
	for (int t=1;t<=T;++t) {
		scanf("%lld/%lld", &p, &q);	
		ll a = gcd(p, q);
		p/=a;
		q/=a;
		ll d=2;
		bool good = false;
		int i;
		int ans;
		for (i=1;i<=40;++i) {
			if (d % q == 0) {
				good = true;
				ll m = d/q;
				q *= m;
				p *= m;
				ans = 1;
				while (p*2 < q) {
					q/=2;
					ans++;
				}
				break;
			}

			d *= 2LL;
		}
		if (!good) {
			printf ("Case #%d: impossible\n", t);
		} else {
			printf ("Case #%d: %d\n", t, ans);
		}
	}
	// 0/1, 1/1
	// 0/2, 1/2, 2/2
	// 0/4, 1/4, 2/4, 3/4, 4/4
	// 0/8, 1/8, 2/8, 
}
