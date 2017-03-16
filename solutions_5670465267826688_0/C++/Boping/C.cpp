#include <cstdio>

int m[8][8] = {0, 1, 2, 3, 4, 5, 6, 7,
			   1, 4, 3, 6, 5, 0, 7, 2,
			   2, 7, 4, 1, 6, 3, 0, 5,
			   3, 2, 5, 4, 7, 6, 1, 0,
			   4, 5, 6, 7, 0, 1, 2, 3,
			   5, 0, 7, 2, 1, 4, 3, 6,
			   6, 3, 0, 5, 2, 7, 4, 1,
			   7, 6, 1, 0, 3, 2, 5, 4};

int s[10000];

int main() {
	int t, T, L, i, j, x, isee, jsee;
	long long X;
	FILE * fin = fopen("C.in", "r"), * fout = fopen("C.out", "w");
	fscanf(fin, "%d", &T);
	for (t = 1; t <= T; ++t) {
		fscanf(fin, "%d %lld\n", &L, &X);
		isee = 0;
		jsee = 0;
		s[0] = getc(fin) - 'h';
		if (s[0] == 1) {
			isee = 1;
		}
		for (i = 1; i < L; ++i) {
			s[i] = getc(fin) - 'h';
			s[i] = m[s[i - 1]][s[i]];
			if (s[i] == 1) {
				isee = 1;
			}
			if (isee == 1 && s[i] == 3) {
				jsee = 1;
			}
		}
		x = 1;
		for (j = s[L - 1]; x < 8; j = m[j][s[L - 1]]) {
			++x;
			if (x > X) {
				break;
			}
			for (i = 0; i < L; ++i) {
				if (m[j][s[i]] == 1) {
					isee = 1;
				}
				if (isee == 1 && m[j][s[i]] == 3) {
					jsee = 1;
				}
			}
		}
		X %= 4;
		j = 0;
		for (i = 0; i < X; ++i) {
			j = m[j][s[L - 1]];
		}
		if (j == 4 && isee && jsee) {
			fprintf(fout, "Case #%d: YES\n", t);
		} else {
			fprintf(fout, "Case #%d: NO\n", t);
		}
	}
	return 0;
}
