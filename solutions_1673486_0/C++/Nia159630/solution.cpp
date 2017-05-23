#include <stdio.h>

inline double min (double a , double b) {
	return a < b ? a : b;
}

int main () {
	int T, tt, a, b, i;
	double P[100000];
	double e, ev, p;
	freopen ("A-small-attempt0.in" , "r" , stdin);
	freopen ("output.txt" , "w" , stdout);
	P[0] = 1;
	scanf ("%d" , &T);
	for (tt = 1 ; tt <= T ; tt++) {
		scanf ("%d%d" , &a , &b);
		for (i = 1 ; i <= a ; i++) {
			scanf ("%lf" , &P[i]);
		}
		ev = 1000000;
		p = 1;
		for (i = 0 ; i <= a ; i++) {
			p *= P[i];
			e = (a + b - i * 2 + 1) * p + (a + b * 2 - i * 2 + 2) * (1 - p);
			ev = min (ev , e);
		}
		ev = min (ev , (double) b + 2);
		printf ("Case #%d: %.06lf\n" , tt , ev);
	}
}