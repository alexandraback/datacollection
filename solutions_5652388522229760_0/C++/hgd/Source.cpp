#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cctype>

int main() {
	FILE *fp = fopen("A-small-attempt0.in", "r");
	FILE *fout = fopen("out.txt", "w");
	int T, N;
	fscanf(fp, "%d", &T);
	for (int iii = 0; iii < T; ++iii) {
		fscanf(fp, "%d", &N);
		bool v[10] = { false };
		int cnt = 0, k = N;
		for (int i = 1; i <= 100; ++i) {
			int tmp = k;
			while (tmp) {
				if (v[tmp % 10] == false) {
					v[tmp % 10] = true;
					++cnt;
				}
				tmp /= 10;
			}
			if (cnt == 10) break;
			k += N;
		}
		if (cnt < 10) fprintf(fout, "Case #%d: INSOMNIA\n", iii + 1);
		else fprintf(fout, "Case #%d: %d\n", iii + 1, k);
	}
	fclose(fp);
	fclose(fout);
	return 0;
}