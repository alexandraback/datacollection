#include <stdio.h>
int p[22], pn, i;
int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T, K, sol;
	scanf("%d",&T);
	for (K = 1; K <= T; K++) {
		sol = 0;
		long long x, A, B, y;
		scanf("%lld%lld",&A,&B);
		for (x = 1; x*x <= B; x++) {
			if (x*x >= A) {
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
						++sol;
				}
			}
		}
		printf("Case #%d: %d\n",K,sol);
	}
	fcloseall();
	return 0;
}