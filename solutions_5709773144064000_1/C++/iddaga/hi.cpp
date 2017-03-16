#include <stdio.h>
#include <memory.h>
double C, F, X;
int main()
{
	FILE *in=fopen("input.txt","r");
	FILE *out=fopen("output.txt","w");
	int t, T, i, j, k;
	
	fscanf(in,"%d",&T);
	for (t = 1; t <= T; t++) {
		printf("%d / %d\n",t,T);
		fprintf(out,"Case #%d: ",t);
		fscanf(in,"%lf%lf%lf",&C,&F,&X);
		double v = 2, r = X/2, vv, rr;
		for (;;) {
			vv = v+F;
			rr = r - X/v + C/v + X/vv;
			if (rr > r) break;
			v = vv; r = rr;
		}
		fprintf(out,"%.7lf\n",r);
	}
	fclose(in);
	fclose(out);
	return 0;
}