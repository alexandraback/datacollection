#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 101;
long long a[N], b[N], c[N][N], d[N][N], dp[N][N], mx;
int A[N], B[N];
int main() {
	freopen("C-large.in", "r", stdin);
	freopen("C-large.out", "w", stdout);
	int t, tt;
	int i, j, x, y, n, m;
	scanf("%d", &tt);
	for (t = 1; t <= tt; t++) {
		printf("Case #%d: ", t);
		scanf("%d%d", &n, &m);
		for (i = 1; i <= n; i++)
			scanf("%I64d%d", &a[i], &A[i]);
		for (i = 1; i <= m; i++)
			scanf("%I64d%d", &b[i], &B[i]);
		for (i = 1; i < N; i++) {
			for (j = 1; j <= n; j++) {
				c[i][j] = c[i][j-1];
				if (A[j] == i)
					c[i][j] += a[j];
			}
			for (j = 1; j <= m; j++) {
				d[i][j] = d[i][j-1];
				if (B[j] == i)
					d[i][j] += b[j];
			}
		}
		mx = 0;
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= m; j++) {
				dp[i][j] = 0;
				if (A[i] == B[j]) {
					for (x = 0; x < i; x++)
						for (y = 0; y < j; y++)
							dp[i][j] = max(dp[i][j], dp[x][y] + min(c[A[i]][i] - c[A[i]][x], d[B[j]][j] - d[B[j]][y]));
				} else {
					for (x = 1; x < i; x++)
						for (y = 1; y < j; y++)
							dp[i][j] = max(dp[i][j], dp[x][y]);
				}
				mx = max(mx, dp[i][j]);
			}
		}
		printf("%I64d\n", mx);
	}
	return 0;
}
