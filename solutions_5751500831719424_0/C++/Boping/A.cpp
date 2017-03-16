#include <cstdio>
#include <cstdlib>

int comp(const void * a, const void * b) {
	return *(int *)a - *(int *)b;
}

char strings[100][101];
int n[100], it[100];

int main() {
	int T, t, N, i, ans;
	char c;
	FILE * fin = fopen("A.in", "r"), * fout = fopen("A.out", "w");
	fscanf(fin, "%d", &T);
	for (t = 1; t <= T; ++t) {
		ans = 0;
		fscanf(fin, "%d", &N);
		for (i = 0; i < N; ++i) {
			fscanf(fin, "%s", &strings[i]);
			it[i] = 0;
		}
		while (c = strings[0][it[0]]) {
			for (i = 0; i < N; ++i) {
				n[i] = 0;
				while (c == strings[i][it[i]]) {
					++n[i];
					++it[i];
				}
				if (!n[i]) {
					break;
				}
			}
			if (i < N) {
				break;
			}
			qsort(n, N, 4, comp);
			for (i = 0; i < N; ++i) {
				ans += abs(n[i] - n[N >> 1]);
			}
		}
		if (c) {
			fprintf(fout, "Case #%d: Fegla Won\n", t);
		} else {
			for (i = 0; i < N; ++i) {
				if(strings[i][it[i]]) {
					break;
				}
			}
			if (i < N) {
				fprintf(fout, "Case #%d: Fegla Won\n", t);
			} else {
				fprintf(fout, "Case #%d: %d\n", t, ans);
			}
		}
	}
	return 0;
}

