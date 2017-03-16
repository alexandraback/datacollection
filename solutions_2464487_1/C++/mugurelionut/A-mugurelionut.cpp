#include <stdio.h>

int main() {
	freopen("A-large.in", "r", stdin);
	freopen("Alarge.out", "w", stdout);

	int te, T;
	unsigned long long t, kmax, x;
	long long r, k, li, ls, mid;
	
	scanf("%d", &T);
	for (te = 1; te <= T; te++) {
		scanf("%lld %llu", &r, &t);

		kmax = 1;
		while ((kmax + 1) * (kmax + 1) < t)
			kmax *= 2;

		//fprintf(stderr, "t=%llu kmax=%llu:%llu\n", t, kmax, (kmax + 1) * (kmax + 1));
		
		li = 0; ls = kmax; k = -1;
		while (li <= ls) {
			mid = (li + ls) / 2;
			x = t / (mid + 1);
			if (2 * r + 1 + 2 * mid <= x) {
				li = mid + 1;
				k = mid;
			} else {
				ls = mid - 1;
			}
		}
		
		printf("Case #%d: %lld\n", te, k + 1);
		fprintf(stderr,"Case #%d: %lld\n", te, k + 1);
	}
	
	return 0;
}
