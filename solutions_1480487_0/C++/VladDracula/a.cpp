#include <stdio.h>

int n;
int votes[256];
double res[256];

int main() {
	FILE *fi = fopen("a.in", "r");
	FILE *fo = fopen("a.out", "w");

	int tests;
	fscanf(fi, "%d", &tests);
	for (int test=0; test<tests; test++) {
		fscanf(fi, "%d", &n);
		int sum = 0;
		for (int i=0; i<n; i++) {
			fscanf(fi, "%d", votes+i);
			sum += votes[i];
		}
		for (int i=0; i<n; i++) {
			double left = 0.0;
			double right = 100.0;
			while (right-left>1e-7) {
				double x = (left+right)*0.5;
				double score = votes[i] + sum*x*0.01;
				double pleft = 100.0 - x;
				int bigger = 0;
				int same = 0;
				for (int j=0; j<n && pleft>0.0; j++)
					if (i != j) {
						if (votes[j]>score) bigger++;
						else {
							double need = (score-votes[j])/double(sum)*100;
							pleft -= need;
							same++;
						}
					}
				if (pleft>0.0 || same==0) {
					left=x;
				} else {
					right=x;
				}
			}

			res[i] = left;
		}

		fprintf(fo, "Case #%d: ", test+1);
		for (int i=0; i<n-1; i++)
			fprintf(fo, "%.6lf ", res[i]);
		fprintf(fo, "%.6lf\n", res[n-1]);
	}

	fclose(fi);
	fclose(fo);
	return 0;
}
