#include <stdio.h>
#include <stdlib.h>

FILE *in, *out;

int n;
double naomi[1000], ken[1000];

int compare(const void *a, const void *b) {
	double da = *(double*) a;
	double db = *(double*) b;
	if(da > db)
		return 1;
	else if(da < db)
		return -1;
	else
		return 0;
}

void runtestcase(int caseno) {
	fprintf(out, "Case #%i: ", caseno);
	fscanf(in, "%i", &n);
	int i;
	for(i = 0; i < n; i++) {
		fscanf(in, "%lf", &naomi[i]);
	}
	qsort(naomi, n, sizeof(double), compare);
	for(i = 0; i < n; i++)
		fscanf(in, "%lf", &ken[i]);
	qsort(ken, n, sizeof(double), compare);
	int wincount = 0;
	int nl = 0, nr = n-1, kl = 0, kr = n-1;
	while(nl <= nr) {
		if(naomi[nr] > ken[kr]) {
			wincount++;
			nr--, kr--;
		}
		else {
			nl++, kr--;
		}
	}
	fprintf(out, "%i ", wincount);
	wincount = 0;
	nl = 0, nr = n-1, kl = 0, kr = n-1;
	while(nl <= nr) {
		if(naomi[nr] > ken[kr]) {
			wincount++;
			nr--, kl++;
		}
		else {
			nr--, kr--;
		}
	}
	fprintf(out, "%i\n", wincount);
}

void main(int argc, char *argv[]) {
	in = fopen(argv[1], "r");
	out = fopen("decietful.out", "w");
	
	int t;
	fscanf(in, "%i", &t);
	int i;
	for(i = 0; i < t; i++) {
		runtestcase(i + 1);
	}
}