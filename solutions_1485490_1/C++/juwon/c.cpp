#include <cstdio>
#include <algorithm>

using namespace std;
int n, m;
long long a[101], b[101];
int A[101], B[101];
long long d[101][101];

int main() {
	int r, cs = 0;
	scanf("%d", &r);
	while (r--) {
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; ++i) {
			scanf("%lld %d", &a[i], &A[i]);
		}
		for (int i = 1; i <= m; ++i) {
			scanf("%lld %d", &b[i], &B[i]);
		}
		fill(d[0], d[101], 0);
		
		long long sol = 0;
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j) {
				d[i][j] = max(d[i - 1][j], d[i][j - 1]);
				if (A[i] != B[j]) continue;
				long long c1 = 0, c2 = 0, mm;
				
				for (int p = i; p >= 1; --p) {
					if (A[p] == A[i]) c1 += a[p];
					c2 = 0;
					for (int q = j; q >= 1; --q) {
						if (B[q] == A[i]) c2 += b[q];
						mm = min(c1, c2);
						if (d[i][j] < d[p - 1][q - 1] + mm) d[i][j] = d[p - 1][q - 1] + mm;
					}
				}
			}
		
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j) {
				if (d[i][j] > sol) sol = d[i][j];
					//printf("%d, %d : %lld\n", i, j, d[i][j]);
			
			}
		printf("Case #%d: %lld\n", ++cs, sol);
	}
	return 0;
}
