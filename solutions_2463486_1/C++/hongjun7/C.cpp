#include <stdio.h>
int p[22], pn, i;
long long l[111111], ln;
int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T, K, sol;
	scanf("%d",&T);
	long long x, A, B, y;
	for (x = 1; x <= 10000000; x++) {
		pn = 0;
		y = x*x;
		while (y) {
			p[++pn] = y%10;
			y/=10;
		}
		for (i = 1; i <= pn/2; i++) {
			if (p[i] != p[pn-i+1])
				break;
		}
		if (i == pn/2+1) {
			pn = 0;
			y = x;
			while (y) {
				p[++pn] = y%10;
				y/=10;
			}
			for (i = 1; i <= pn/2; i++) {
				if (p[i] != p[pn-i+1])
					break;
			}
			if (i == pn/2+1)
				l[++ln] = x*x;
		}
	}
	for (K = 1; K <= T; K++) {
		sol = 0;
		scanf("%lld%lld",&A,&B);
		for (i = 1; i <= ln; i++) {
			if (l[i] >= A && l[i] <= B)
				++sol;
		}
		printf("Case #%d: %d\n",K,sol);
	}
	fcloseall();
	return 0;
}