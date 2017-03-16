#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ep(...) fprintf(stderr, __VA_ARGS__); fflush(NULL)
#define sd(num) (sizeof(double) * num)
#define sd1(num) (sd(num + 1))
// descending; wrong order!
int compar(const void *a, const void *b) {
	double A = *(double*)a;
	double B = *(double*)b;
	if(A < B) {
		return 1;
	}
	else if(B > A) {
		return -1;
	}
	return 0;
}
int main(int argc, char **argv) {
	int cases = 0;
	scanf("%d\n", &cases);
	ep("%d cases.\n", cases);
	
	for(int cas = 0; cas < cases; ++cas) {
		int typed, length;
		scanf("%d %d", &typed, &length);
		ep("case %d, typed %d, length %d\n", cas, typed, length);
		double *floats = malloc(sd(typed));
		memset(floats, 0, sd(typed));
		for(int i = 0; i < typed; ++i) {
			scanf("%lf", &floats[i]);
		}
		
		// keep typing, restart now, restart fail
		double pkt = 1.0;
		double prn = 1.0;
		double prf = 1.0;
		int kkt = (length - typed) + 1;
		int krn = length + 2;
		int krf = (length - typed) + length + 2;
		for(int i = 0; i < typed; ++i) {
			pkt *= floats[i];
		}
		
		double *bsfacts = malloc(sizeof(double) * (typed + 2));
		int *bskeys = malloc(sizeof(int) * (typed + 2));
		for(int i = 1; i <= typed; ++i) {
			bskeys[i] = (length - typed) + 1 + (i * 2);
			bsfacts[i] = 1.0;
			for(int j = 0; j < typed - i; ++j) {
				bsfacts[i] *= floats[j];
			}
			ep("if backspace %d times, %d keys @ %lf chance\n", i, bskeys[i], bsfacts[i]);
		}
		
		double fkt = ((double)kkt * pkt) + (krf) * (1 - pkt);
		double frn = (double)krn;
		
		ep("kkt=%d pkt=%lf krn=%d prn=%lf krf=%d prf=%lf\n", kkt, pkt, krn, prn, krf, prf);
		ep("fkt=%lf frn=%lf\n", fkt, frn);
		double lowest = fkt < frn ? fkt : frn;
		for(int i = 1; i <= typed; ++i) {
			double fact = ((double)bskeys[i]) * bsfacts[i];
			ep("good case keys %d: %lf\n", i, fact);
			int penalty = bskeys[i] + length + 1;
			fact += ((double)penalty) * (1 - bsfacts[i]);
			ep("fact for %d: %lf\n", i, fact);
			if(fact < lowest) {
				lowest = fact;
			}
		}
		
		free(bsfacts);
		free(bskeys);
		free(floats);
		printf("Case #%d: %lf\n", cas + 1, lowest);
		fflush(NULL);
	}

	exit(0);
}