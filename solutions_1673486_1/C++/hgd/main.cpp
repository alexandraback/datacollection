#include <cstring>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cmath>


int main() {
	FILE *fin = fopen("A-large.in", "r");
	FILE *fout = fopen("out.txt", "w");
	int t;
	fscanf(fin, "%d", &t);
	for (int i = 1; i <= t; ++i) {
		int A, B;
		double p = 1, best;
		fscanf(fin, "%d%d", &A, &B);
		best = B + 2;
		if (best > A + B + 1) best = A + B + 1;
		for (int j = 1; j <= A; ++j) {
			double tmp;
			fscanf(fin, "%lf", &tmp);
			p *= tmp;
			tmp = A - j - j + (2 - p) * (B + 1);
			if (best > tmp) best = tmp;
		}
		fprintf(fout, "Case #%d: %lf\n", i, best);
	}
	fclose(fout);
	fclose(fin);
	return 0;
}
