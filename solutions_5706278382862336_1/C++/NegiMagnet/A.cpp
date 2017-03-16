#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)
typedef unsigned long long ull;

ull gcd(ull a, ull b) {
	if( b==0 ) return a;
	return gcd(b, a%b);
}

int main() {
	int t;
	scanf("%d", &t);
	rep(tt, t) {
		ull p, q;
		scanf("%lld/%lld", &p, &q);
		ull cnt = 1;
		bool imp = false;
		ull g = gcd(p, q);
		q /= g;
		p /= g;
		ull tq = q;
		while( tq%2==0 ) tq /= 2;
		if( tq > 1 ) {
			imp = true;
		} else {
			while( p < q/2 ) {
				q /= 2;
				cnt++;
			}
		}
		printf("Case #%d: ", tt+1);
		if(imp) {
			printf("impossible\n");
		} else {
			printf("%lld\n", cnt);
		}
	}
	return 0;
}
