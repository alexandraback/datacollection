#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

const int MAX_N = 110;
const double EPS = 1.0e-12;
char k[MAX_N], l[MAX_N];
int ti[26];
int K, L, S;
double dp[MAX_N][MAX_N][MAX_N];

int nxt[MAX_N];
void getNxt(char *s) {
	int i = 0, j = -1;
	nxt[i] = j;
	while (s[i]) {
		if (j == -1 || s[i] == s[j]) {
			++i, ++j;
			nxt[i] = j;
		} else {
			j = nxt[j];
		}
	}
}

void add(double& a, double b) {
	a += b;
}

int main() {
#ifdef _SHANGKE_
	time_t _t1 = clock();
	// freopen(".in", "r", stdin);
	// freopen(".out", "w", stdout);
#endif
	int n_case = 0;
	scanf("%d", &n_case);
	for (int ca = 1; ca <= n_case; ca++) {
		scanf("%d%d%d", &K, &L, &S);
		scanf("%s%s", k, l);
		memset(ti, 0, sizeof ti);
		for (int i = 0; i < K; i++) {
			++ti[k[i] - 'A'];
		}
		getNxt(l);
		fill(dp[0][0], dp[S - L + 2][0], 0.0);
		dp[0][0][0] = 1.0;
		for (int j = 0; j < S; j++) {
			for (int i = 0; i <= S - L + 1; i++) {
				for (int k = 0; k < L; k++) {
					if (dp[i][j][k] == 0.0) continue;
					for (char c = 'A'; c <= 'Z'; c++) {
						if (ti[c - 'A'] == 0) continue;
						int nk = k;
						while (nk != -1 && c != l[nk]) {
							nk = nxt[nk];
						}
						++nk;
						if (nk == L) {
							nk = nxt[nk];
							add(dp[i + 1][j + 1][nk], dp[i][j][k] * ti[c - 'A'] / K);
						} else {
							add(dp[i][j + 1][nk], dp[i][j][k] * ti[c - 'A'] / K);
						}
					}
				}
			}
		}
		int mx = 0, cc = 0;
		for (int i = 0; i < S; i++) {
			++cc;
			if (cc == L) {
				++mx;
				cc = nxt[cc];
			}
		}
		for (int i = 0; i < L; i++) {
			if (ti[l[i] - 'A'] == 0) {
				mx = 0;
			}
		}
		double need = 0.0;
		for (int i = 0; i <= S - L + 1; i++) {
			for (int k = 0; k < L; k++) {
				need += dp[i][S][k] * i;
			}
		}
		double ans = 1.0 * mx - need;
		printf("Case #%d: %.12lf\n", ca, ans);
	}
#ifdef _SHANGKE_
	fprintf(stderr, "%.3lf s\n", 1.0 * (clock() - _t1) / CLOCKS_PER_SEC);
#endif
	return 0;
}
