#include <cstdio>
#include <cstdlib>
#include <cctype>

int main() {
	FILE *fp = fopen("B-small-attempt0.in", "r");
	FILE *fout = fopen("out.txt", "w");
	int T, ans, max, tmp, d, p[1000];
	fscanf(fp, "%d", &T);
	for (int i = 0; i < T; ++i) {
		ans = 9999;
		max = 0;
		fscanf(fp, "%d", &d);
		for (int j = 0; j < d; ++j) {
			fscanf(fp, "%d", &p[j]);
			if (p[j] > max) max = p[j];
		}
		for (int k = 1; k <= max; ++k) {
			tmp = k;
			for (int j = 0; j < d; ++j)
				tmp += (p[j] - 1) / k;
			if (tmp < ans) ans = tmp;
		}
		fprintf(fout, "Case #%d: %d\n", i + 1, ans);
	}
	fclose(fp);
	fclose(fout);
	return 0;
}