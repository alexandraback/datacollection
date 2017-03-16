#include <stdio.h>

int p10[9], x[10], xn;
static int v[2000010] = {0};

int main(void) {
	int tn, ti, i;
	scanf("%d", &tn);
	p10[0] = 1;
	for (i = 1; i < 9; i++) p10[i] = p10[i-1]*10;
	for (ti = 1; ti <= tn; ti++) {
		int a, b, n, m, d, r = 0;
		scanf("%d %d", &a, &b);
		for (d = 0, m = a; m; d++, m /= 10);
		for (n = a; n <= b; n++) {
			xn = 0;
			for (i = 1; i < d; i++) {
				m = (n%p10[i])*p10[d-i]+(n/p10[i]);
				if (m > n && m <= b && !v[m]) {
					v[m] = 1;
					x[xn++] = m;
					r++;
				}
			}
			for (i = 0; i < xn; i++) v[x[i]] = 0;
		}
		printf("Case #%d: %d\n", ti, r);
	}
	return 0;
}
