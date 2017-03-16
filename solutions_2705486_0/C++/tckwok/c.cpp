#include <cstdio>

#define N 64

FILE *f = fopen("dict.txt", "r");
char dict[1 << 20][16], s[256];
int T, dn, dp[N][5], len[1 << 20], n;
bool neq[16];

int min(int a, int b) {
	return a < b ? a : b;
}

int max(int a, int b) {
	return a > b ? a : b;
}

void update(int x, int k) {
	for (int i = 0; i < len[k]; ++i)
		neq[i] = (s[x + i] != dict[k][i]);
	int last = -1, first = -1, cnt = 0;
	for (int i = 0; i < len[k]; ++i)
		if (neq[i]) {
			if (last == -1) first = last = i;
			else if (i - last < 5) return;
			else last = i;
			++cnt;
		}
	int y = x + len[k];
	if (first = -1) first = 0;
	else first = max(4 - first, 0);
	if (last = -1) last = 4;
	else last = min(len[y] - last - 1, 4);
	dp[y][last] = min(dp[y][last], dp[x][4 - first] + cnt);
	for (int i = last - 1; i >= 0; --i)
		dp[y][i] = min(dp[y][i], dp[y][last]);
}

int main() {
	dn = 0;
	while (fscanf(f, "%s", dict[dn]) == 1) {
		len[dn] = -1;
		while (dict[dn][++len[dn]]);
		++dn;
	}
	fclose(f);
	scanf("%d", &T);
	for (int r = 1; r <= T; ++r) {
		scanf("%s", s);
		n = -1;
		while (s[++n]);
		for (int i = 0; i <= n; ++i)
			for (int j = 0; j < 5; ++j)
				dp[i][j] = n;
		dp[0][4] = 0;
		for (int i = 0; i < n; ++i)
			for (int k = 0; k < dn; ++k) if (i + len[k] <= n)
				update(i, k);
		printf("Case #%d: %d\n", r, dp[n][0]);
	}
	return 0;
}
