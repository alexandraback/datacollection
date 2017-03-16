#include <cstdio>
#include <algorithm>
#define FOR(i,b,e) for(int i=(b); i<=(e); ++i)
using namespace std;
typedef long long LL;
typedef long double ftype;

LL n, x, y, l, h, p;

void go(LL a, LL b)
{
	if (a+b == n) {
		if (b >= p) ++x;
		++y;
	} else {
		if (a < h) go(a+1, b);
		if (b < h) go(a, b+1);
	}
}


int main()
{
	int Q; scanf("%d", &Q);
	FOR(q, 1, Q) {
		scanf("%lld%lld%lld", &n, &x, &y);
		
		l = (abs(x)+y)/2;
		h = 2*l;
		p = y+1;
		
		n = max(0ll, n - l*(2*l-1));
		
		if (n >= 2*h+1) x = y = 1;
		else {
			x = y = 0;
			go(0, 0);
		}
		
		printf("Case #%d: %.10Lg\n", q, ftype(x)/y);
	}
	
	return 0;
}
