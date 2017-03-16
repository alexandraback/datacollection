#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>

int f[1000], v[1000], term[1000], b[1000];

int main() {
	FILE * fin = fopen("input.in", "r"), * fout = fopen("output.out", "w");
	int T, t, n, i, j, bestcycle, count;
	fscanf(fin, "%d\n", &T);
	for (t = 1; t <= T; ++t) {
		fscanf(fin, "%d", &n);
		bestcycle = 0;
		memset(b, 0, n * sizeof(int));
		for (i = 0; i < n; ++i) {
			fscanf(fin, "%d", f + i);
			--f[i];
			if (f[i] < i && f[f[i]] == i) {
				term[i] = 1;
				term[f[i]] = 1;
			} else {
				term[i] = 0;
			}
		}
		for (i = 0; i < n; ++i) {
			if (term[i] == 0) {
				memset(v, 0, n * sizeof(int));
				count = 1;
				v[i] = 1;
				j = i;
				while (!v[f[j]]) {
					j = f[j];
					if (term[j]) {
						if (b[j] < count) b[j] = count;
						break;
					}
					++count;
					v[j] = 1;
				}
				if (f[j] == i && bestcycle < count) bestcycle = count;
			}
		}
		count = 0;
		for (i = 0; i < n; ++i) {
			if (term[i]) {
				count += b[i] + 1;
			}
		}
		if (bestcycle > count) {
			count = bestcycle;
		}
		fprintf(fout, "Case #%d: %d\n", t, count);
	}
	return 0;
}
