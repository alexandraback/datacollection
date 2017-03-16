#include <cstdio>

int main() {
	FILE * fin = fopen("input.in", "r"), * fout = fopen("output.out", "w");
	int T, t, A, B, i, k;
	double ans, p, tp;
	fscanf(fin, "%d\n", &T);
	for (t = 1; t <= T; ++t) {
		fscanf(fin, "%d%d", &A, &B);
		ans = B + 2;
		tp = 1;
		for (i = 1; i <= A; ++i) {
			fscanf(fin, "%lf", &p);
			tp *= p;
			k = A + B - (i << 1) + 1;
			if (ans > k + (1 - tp) * (B + 1)) {
				ans = k + (1 - tp) * (B + 1);
			}
		}

		fprintf(fout, "Case #%d: %f\n", t, ans);
	}
	return 0;
}
