#include <stdio.h>
#include <stdlib.h>

int main() {
	int T, t, c, l;
	double* p;
	double i, ans, exp;
	int A, B;
	float f;

	scanf("%d", &T);
	for(t=1; t<=T; t++) {
		scanf("%d %d", &A, &B);
		p = calloc(A, sizeof(double));
		i = 1;
		for(c=0; c<A; c++) {
			scanf("%f", &f);
			p[c] = f;
			i*= p[c];
		}
		//printf("%f\n", i);
		ans = (B-A+1)*i + (2*B-A+2)*(1-i);	// Keystrokes if i kepp typing
		//printf("%.6f\n", ans);
		i = 1;	// I contains probability that at least c first letters are ok
		for(c=1; c<A; c++) {
			exp = 1;
			i*= p[c-1];
			exp = (A-c + B-c + 1)*i + (A-c + B-c + 1 + B + 1)*(1-i);
			//printf("%.6f\n", exp);
			if(exp<ans) ans = exp;
		}
		//i*= p[A-1];
		exp = B + 2;	// press enter right away
		//printf("%.6f\n", exp);
		if(exp<ans) ans = exp;
		printf("Case #%d: %.6f\n", t, ans);
		free(p);
	}
}
