#include <cstdio>
#include <cstdlib>

double a[1000], b[1000];
int T, N;

int cmp(const void *x, const void *y) {
	double u = *(const double *)x;
	double v = *(const double *)y;
	if (u < v) return -1;
	if (u > v) return 1;
	return 0;
}

int main() {
	FILE *fp = fopen("D-large.in", "r");
	FILE *fout = fopen("out.txt", "w"); 
	fscanf(fp, "%d", &T);
	for (int t = 0; t < T; ++t) {
		fprintf(fout, "Case #%d: ", t + 1);
		fscanf(fp, "%d", &N);
		for (int i = 0; i < N; ++i)
			fscanf(fp, "%lf", &a[i]);
		for (int i = 0; i < N; ++i)
			fscanf(fp, "%lf", &b[i]);
		qsort(a, N, sizeof(double), cmp);
		qsort(b, N, sizeof(double), cmp);
		int score = 0;
		int i, j = 0;
		for (int i = 0; i < N; ++i) {
			if (a[i] > b[j]) {
				++score;
				++j;
			}
		}
		fprintf(fout, "%d ", score);
		for (i = 0; i < N; ++i) {
			for (j = 0; j < N; ++j) {
				if (b[j] < 0) continue;
				if (b[j] > a[i]) {
					b[j] = -1;
					break;
				}
			}
			if (j == N) break;
		}
		fprintf(fout, "%d\n", N - i);
	}
	fclose(fp);
	fclose(fout);
	return 0;
}