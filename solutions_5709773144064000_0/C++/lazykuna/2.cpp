#include <stdio.h>
#include <string.h>

double c,f,x;
FILE *fp, *fout;

double getBestTime(int factCnt, double factTime, double bestTime)
{
	double r = factTime + (double)x / (2 + factCnt*f);
	printf("%lf\n", r);
	if ((r < bestTime) || (bestTime < 0)) {
		return getBestTime(factCnt+1, factTime + (double)c / (2 + factCnt*f) ,r);
	} else {
		return bestTime;
	}
}

int main() {
	fp = fopen("2.input", "r");
	fout = fopen("2.output", "wb");

	int cnt=0;
	fscanf(fp, "%d", &cnt);
	for (int i=0; i<cnt; i++) {
		fscanf(fp, "%lf %lf %lf", &c, &f, &x);
		fprintf(fout, "Case #%d: %lf\n", i+1, getBestTime(0,0,-1));
	}

	fclose(fp);
	fclose(fout);
	
	return 0;
}
