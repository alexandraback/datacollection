#include <stdio.h>

int main () {
	int i, j, k, l, m, n, o, t;
	double c, f, x, tot, timf, tims, cur, cok;
	
	scanf("%d", &t);
	cok = 2.0;
	for (o = 1; o <=t ; o++) {
		scanf("%lf %lf %lf", &c, &f, &x);
		tims = x / cok;
		cur = cok;
		timf = (c/cur) + (x/(cur+f));
		if (tims > timf) {
			tot = c/cur;
			cur = cur + f;
			while (1) {
				tims = timf;
				timf = tot + (c/cur) + (x/(cur+f));
				tot = tot + (c/cur);
				cur += f;
				if (timf >= tims) {
					tot = tims;
					break;	
				} 
			}
		} else {
			tot = x/cok;	
		}
		printf("Case #%d: %.7lf\n", o, tot);
	}
	return 0;	
}
