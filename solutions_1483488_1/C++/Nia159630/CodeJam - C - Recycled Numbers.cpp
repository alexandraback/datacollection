#include <stdio.h>

int used[62500];

bool checked (int x) {
	return (used[(x - 1) / 32] & (1 << (x - 1) % 32)) != 0;
}

void check (int x) {
	used[(x - 1) / 32] |= 1 << (x - 1) % 32;
}

int main () {
	freopen ("C-large.in" , "r" , stdin);
	freopen ("output.txt" , "w" , stdout);
	int tt, t, a, b, m, n, i, x, cir, ans;
	int exp10[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};
	scanf ("%d" , &tt);
	for (t = 1 ; t <= tt ; t++) {
		scanf ("%d%d" , &a , &b);
		ans = 0;
		for (i = 0 ; i < 62500 ; i++) {
			used[i] = 0;
		}
		for (n = 1 ; exp10[n] <= a ; n++) ;
		for (i = a ; i <= b ; i++) {
			if (!checked (i)) {
				check (i);
				cir = 1;
				for (m = 1 ; exp10[m] <= i ; m++) {
					x = i / exp10[m] + i % exp10[m] * exp10[n - m];
					if (x >= a && x <= b && !checked (x)) {
						cir++;
						check (x);
					}
				}
				ans += cir * (cir - 1) / 2;
			}
		}
		printf ("Case #%d: %d\n" , t , ans);
	}
}