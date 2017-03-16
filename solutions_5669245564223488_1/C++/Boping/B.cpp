#include <cstdio>
#include <cstring>

#define MOD 1000000007

char cars[100][101];
int visited[26];

int scount[26], begin[26], end[26];
long long nf, fcount[26];

int main() {
	FILE * fin = fopen("B.in", "r"), * fout = fopen("B.out", "w");
	int T, t;
	int i, j, k, N, possible, temp;
	long long ans;
	fscanf(fin, "%d", &T);
	for (t = 1; t <= T; ++t) {
		possible = 1;
		for (i = 0; i < 26; ++i) {
			scount[i] = 0;
			begin[i] = -1;
			end[i] = -1;
			visited[i] = 0;
		}
		fscanf(fin, "%d", &N);
		for (i = 0; i < N; ++i) {
			fscanf(fin, "%s", cars[i]);
			for (j = 1; cars[i][j] == cars[i][0]; ++j);
			if (!cars[i][j]) {
				++scount[cars[i][0] - 'a'];
			} else {
				if(end[cars[i][0] - 'a'] != -1) {
					possible = 0;
				} else {
					end[cars[i][0] - 'a'] = i;
				}
				for (++j; cars[i][j]; ++j) {
					if (cars[i][j] != cars[i][j - 1]) {
						if (end[cars[i][j - 1] - 'a'] != -1 || begin[cars[i][j - 1] - 'a'] != -1) {
							possible = 0;
						} else {
							end[cars[i][j - 1] - 'a'] = -2;
							begin[cars[i][j - 1] - 'a'] = -2;
						}
					}
				}
				if (cars[i][j - 1] == cars[i][0]) {
					possible = 0;
				}
				if(begin[cars[i][j - 1] - 'a'] != -1) {
					possible = 0;
				} else {
					begin[cars[i][j - 1] - 'a'] = i;
				}
			}
		}
		for (i = 0; i < 26; ++i) {
			if (scount[i] && begin[i] == -2) {
				possible = 0;
			}
		}
		if (possible) {
			nf = 0;
			for (i = 0; i < 26; ++i) {
				if (begin[i] == -1 && end[i] != -1) {
					ans = 1;
					for (j = 2; j <= scount[i]; ++j) {
						ans *= j;
						ans %= MOD;
					}
					for (k = cars[end[i]][strlen(cars[end[i]]) - 1] - 'a'; end[k] != -1; k = cars[end[k]][strlen(cars[end[k]]) - 1] - 'a') {
						visited[k] = 1;
						for (j = 2; j <= scount[k]; ++j) {
							ans *= j;
							ans %= MOD;
						}
					}
					visited[k] = 1;
					for (j = 2; j <= scount[k]; ++j) {
						ans *= j;
						ans %= MOD;
					}
					fcount[nf] = ans;
					++nf;
				} else if (begin[i] == -1 && end[i] == -1 && scount[i]) {
					ans = 1;
					for (j = 2; j <= scount[i]; ++j) {
						ans *= j;
						ans %= MOD;
					}
					fcount[nf] = ans;
					++nf;
				}
			}
			for (i = 0; i < 26; ++i) {
				if (begin[i] >= 0 && !visited[i]) {
					possible = 0;
				}
			}
			ans = possible;
			for (i = 0; i < nf; ++i) {
				ans *= fcount[i];
				ans %= MOD;
			}
			for (j = 2; j <= nf; ++j) {
				ans *= j;
				ans %= MOD;
			}
			fprintf (fout, "Case #%d: %lld\n", t, ans);
		} else {
			fprintf (fout, "Case #%d: 0\n", t);
		}
	}
	return 0;
}
