#include <cstdio>
#include <cstdlib>
int N, s[1000][2], o[1000];

int comp(const void * a, const void * b) {
	return *(int *)a - *(int *)b;
}

int main() {
	FILE * fin = fopen("input.in", "r"), * fout = fopen("output.out", "w");
	int T, t, i, stars, j, y;
	fscanf(fin, "%d\n", &T);
	for (t = 1; t <= T; ++t) {
		fscanf(fin, "%d", &N);
		for (i = 0; i < N; ++i) {
			fscanf(fin, "%d%d", s[i] + 1, s[i]);
			o[i] = 2;
		}
		qsort(s, N, 8, comp);
		stars = 0;
		i = 0;
		y = 0;
		while (i < N) {
			if (stars >= s[i][0]) {
				stars += o[i];
				++i;
				++y;
			} else {
				for (j = N - 1; j >= i; --j) {
					if (stars >= s[j][1] && o[j] == 2) {
						++stars;
						o[j] = 1;
						++y;
						break;
					}
				}
				if (j < i) {
					break;
				}
			}
		}
		if (i < N) {
			fprintf(fout, "Case #%d: Too Bad\n", t);
		} else {
			fprintf(fout, "Case #%d: %d\n", t, y);
		}
	}
	return 0;
}
