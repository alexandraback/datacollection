#include <cstdio>

int A, B;

int main() {
	int r, cs = 0;
	scanf("%d", &r);
	while (r--) {
		scanf("%d %d", &A, &B);
		
		double p = 1.0;
		double e;
		double sol = B + 2;
		for (int i = 1; i <= A; ++i) {
			double t;
			scanf("%lf", &t);
			p *= t;
			e = p * ((A - i) * 2 + (B - A) + 1) + 
				(1 - p) * ((A - i) * 2 + (B - A) + 1 + B + 1);
//			printf("%lf\n", e);
			if (e < sol) sol = e;
		}
		printf("Case #%d: %.7lf\n", ++cs, sol);
	}
	return 0;
}
