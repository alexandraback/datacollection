#include<cstdio>

int t, ea, m[1005][1005], p, n;
bool c;

int main() {
	freopen("Al.in", "r", stdin);
	freopen("Al.out", "w", stdout);
	scanf("%d", &t);
	for (int z = 1 ; z <= t ; z++) {
		c = false;
		scanf("%d", &n);
		for (int i = 1 ; i <= n ; i++) {
			scanf("%d", &p);
			for (int j = 1 ; j <= p ; j++) {
				scanf("%d", &ea);
				m[ea][i] = 1;
			}
		}
		for (int k = 1 ; k <= n ; k++) for (int i = 1 ; i <= n ; i++) for (int j = 1 ; j <= n ; j++) m[i][j] += m[i][k] * m[k][j];
		for (int i = 1 ; i <= n ; i++) {
			for (int j = 1 ; j <= n ; j++) {
				if (m[i][j] >= 2) c = true;
				m[i][j] = 0;
			}
		}
		printf("Case #%d: %s\n", z, c ? "Yes" : "No");
	}
	scanf("\n");
	return 0;
}
