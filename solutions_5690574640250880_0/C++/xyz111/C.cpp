#include <cstdio>
#include <memory.h>
using namespace std;

int T, n, m, k;
bool dp[60][60][2600], cc;
char b[60][60];

void out(int x, int y, int z) {
	for (int i = 1; i <= y; i++)	b[i][x] = '.';
	if (x == 2) {
		for (int i = 1; i <= y; i++)	b[i][1] = '.';
		return ;
	}
	for (int j = y; j <= n; j++)
		for (int p = z; p <= n * m; p++)
			if (dp[x - 1][j][p - j]) {
				out(x - 1, j, p - j);
			}
}

int main() {
	freopen("C-small-attempt2.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &T);
	for (int Q = 1; Q <= T; Q++) {
		scanf("%d%d%d", &n, &m, &k);
		k = n * m - k;
		cc = true;
		if (k == 1) {
			memset(b, '*', sizeof b);
		}else if (n == 1) {
			memset(b, '*', sizeof b);
			for (int i = 1; i <= k; i++)	b[1][i] = '.';
		}else	if (m == 1) {
			memset(b, '*', sizeof b);
			for (int i = 1; i <= k; i++)	b[i][1] = '.';
		}else {
			memset(dp, 0, sizeof dp);
			for (int i = 1; i <= n; i++)	dp[2][i][2 * i] = true;
			for (int i = 3; i <= m; i++) {
				for (int j = 1; j <= n; j++)
					for (int p = 1; p <= n * m; p++)
						if (dp[i - 1][j][p]) 
							for (int q = 1; q <= j; q++)	dp[i][q][p + q] = true;
			}
			memset(b, '*', sizeof b);
			cc = false;
			for (int i = 2; i <= m && !cc; i++)
				for (int j = 2; j <= n && !cc; j++)	if (dp[i][j][k]) {
					out(i, j, k);
					cc = true;
				}
		}
		// printf("xx %d\n", dp[]);
		printf("Case #%d:\n", Q);
		if (!cc)	printf("Impossible\n");
		else {
			b[1][1] = 'c';
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= m; j++)	printf("%c", b[i][j]);
				printf("\n");
			}
		}
	}
}
