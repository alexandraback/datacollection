#include <cstdio>
#include <cstdlib>

int main() {
	FILE *fp = fopen("B-small-attempt0.in", "r");
	FILE *fout = fopen("out.txt", "w");
	int T, f;
	double C, F, X, ans, t;
	fscanf(fp, "%d", &T);
	for (int i = 0; i < T; ++i) {
		fscanf(fp, "%lf%lf%lf", &C, &F, &X);
		fprintf(fout, "Case #%d: ", i + 1);
		ans = X / 2;
		t = 0;
		for (f = 0; f < X / C - 2 / F; ++f) {
			double tmp = t + X / (2 + F * f);
			if (tmp < ans) ans = tmp;
			t += C / (2 + F * f);
		}
		fprintf(fout, "%lf\n", ans);
	}
	fclose(fp);
	fclose(fout);
	return 0;
}