#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cctype>

int main() {
	FILE *fp = fopen("D-small-attempt0.in", "r");
	FILE *fout = fopen("out.txt", "w");
	int T, K, C, S;
	fscanf(fp, "%d", &T);
	for (int iii = 0; iii < T; ++iii) {
		fscanf(fp, "%d%d%d", &K, &C, &S);
		if (S < (K + C - 1) / C) fprintf(fout, "Case #%d: IMPOSSIBLE\n", iii + 1);
		else {
			fprintf(fout, "Case #%d:", iii + 1);
			int tmp = 0;
			for (int i = 0; i < (K + C - 1) / C; ++i) {
				long long s = 0;
				for (int j = 0; j < C; ++j) {
					if (tmp < K) s = s * K + tmp;
					else s *= K;
					++tmp;
				}
				fprintf(fout, " %lld", s + 1);
			}
			fprintf(fout, "\n");
		}
	}
	fclose(fp);
	fclose(fout);
	return 0;
}