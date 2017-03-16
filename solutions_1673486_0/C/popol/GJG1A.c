#include <stdio.h>

#define N 100000

int main(int argc, char const *argv[])
{
	FILE *fin,*fout;
	int i,count,t,a,b;
	double pp,p[N],ex[N],min,temp;

	fin = fopen("GJC.in","r");
	fscanf(fin,"%d",&t);

	fout = fopen("GJC.out","w");
	for (count = 1;count<=t;count++) {
		fscanf(fin,"%d%d", &a, &b);
		pp = 1;
		for (i=1;i<=a;i++) {
			fscanf(fin,"%lf",&p[i]);
			pp *= p[i];
			ex[i] = pp*(b-i+1) + (1-pp)*(2*b-i+2);
		}
		
		min = N;
		for (i=0;i<a;i++) {
			temp = ex[a-i] + i;
			if (temp<min) min = temp;
		}
		if (b+2<min) min = b+2;

		fprintf(fout,"Case #%d: %.6lf\n", count,min);
	}

	fclose(fin);
	fclose(fout);
	return 0;
}