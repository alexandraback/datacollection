#include <stdio.h>
#pragma G++ optimize ("O2")
const int N = 1000;
int cnt[N +1][N +1];
int tmp[N +1][N +1];
int ans[N +1][N +1];
int worked[N +1][N +1];
int main()
{	freopen("A-small-attempt4.in", "r", stdin);
	freopen("ans.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t) {
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				worked[i][j] = ans[i][j] = cnt[i][j] = 0;
				
		for (int v = 1; v <= n; ++v) {
			int m;
			scanf("%d", &m);
			for (int j = 0; j < m; ++j) {
				int u;
				scanf("%d", &u);
				worked[u][v] = ans[u][v] = cnt[u][v] = 1;
			}
		}
		
		int find = 0;
		for (int round = 1; round <= n; ++round) {
			for (int i = 1; i <= n; ++i)
				for (int j = 1; j <= n; ++j)
					tmp[i][j] = 0;
			for (int i = 1; i <= n && !find; ++i) {
				for (int j = 1; j <= n && !find; ++j)
					for (int k = 1; k <= n && !find; ++k) {
						if (worked[i][j] && (ans[i][k] * cnt[k][j]) > 0)
							find = 1;
						tmp[i][j] += (ans[i][k] * cnt[k][j]);
						if (tmp[i][j] > 1)
							find = 1;
					}
			}

			if (find)	break;
		
			for (int i = 1; i <= n; ++i)
				for (int j = 1; j <= n; ++j)
					ans[i][j] = tmp[i][j];
		
			for (int i = 1; i <= n; ++i)
				for (int j = 1; j <= n; ++j)
					if (ans[i][j])
						worked[i][j] |= 1;
		}
		printf("Case #%d: ", t);
		if (find)	puts("Yes");
		else		puts("No");
	}
	//scanf(" ");
	return 0;
}
