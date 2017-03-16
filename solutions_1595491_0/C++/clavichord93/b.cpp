#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int n, s, p, T;
int f[105][105];
int t[105], ss[105], cc[105];
int S(int t) {
	int res  = -1;
	if (t < 2) return res;
	if ((t + 3) % 3 == 0) res = max(res, (t + 3) / 3);
	if ((t + 4) % 3 == 0) res = max(res, (t + 4) / 3);
	if ((t + 2) % 3 == 0) res = max(res, (t + 2) / 3);
	return res;
}

int C(int t) {
	int res  = -1;
	if (t % 3 == 0) res = max(res, t / 3);
	if (t > 0 && (t + 1) % 3 == 0) res = max(res, (t + 1) / 3);
	if (t > 0 && (t + 2) % 3 == 0) res = max(res, (t + 2) / 3);
	return res;
}

void solve() {
	memset(t, 0, sizeof(t));
	memset(f, 0, sizeof(f));
	memset(ss, 0, sizeof(ss));
	memset(cc, 0, sizeof(cc));
	scanf("%d %d %d", &n, &s, &p);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &t[i]);
		ss[i] = S(t[i]);
		cc[i] = C(t[i]);
	}

	/*
	printf("\n");
	for (int i = 1; i <= n; i++) printf("%d ", ss[i]);
	printf("\n");
	for (int i = 1; i <= n; i++) printf("%d ", cc[i]);
	printf("\n");
	*/

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= s; j++) {
			if (j) f[i][j] = max(f[i][j], f[i - 1][j - 1] + (ss[i] >= p));
			f[i][j] = max(f[i][j], f[i - 1][j] + (cc[i] >= p));
		}
	}
	printf("%d\n", f[n][s]);
}

int main() {
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);

	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		printf("Case #%d: ", i);
		solve();
	}
}
