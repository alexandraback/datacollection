#include <cstdio>
#include <cstring>
const int N = 120;
int T, n, m, l, max, p[N];
double ans, f[N][N][N];
char s[N], t[N];
bool succ;
int main(){
	//freopen("B.in", "r", stdin);
	//freopen("B.out", "w", stdout);
	scanf("%d", &T);
	for (int Ti = 1; Ti <= T; ++Ti){
		scanf("%d%d%d", &n, &m, &l);
		scanf("%s%s", s + 1, t + 1);
		for (int i = 1; i <= m; ++i){
			succ = false;
			for (int j = 1; j <= n; ++j) if (s[j] == t[i]){
				succ = true;
				break;
			}
			if (!succ) break;
		}
		if (!succ){
			printf("Case #%d: %.10f\n", Ti, 0.0);
			continue;
		}
		memset(p, 0, sizeof(p));
		p[1] = 0;
		int j = 0;
		for (int i = 2; i <= m; ++i){
			while (j > 0 && t[j + 1] != t[i]) j = p[j];
			if (t[j + 1] == t[i]) ++j;
			p[i] = j;
		}
		max = 1 + (l - m) / (m - p[m]);
		for (int i = 0; i <= 105; ++i)
			for (int j = 0; j <= 105; ++j)
				for (int k = 0; k <= 103; ++k) f[i][j][k] = 0;
		f[0][0][0] = 1;
		for (int i = 0; i < l; ++i)
			for (int j = 0; j < m; ++j)
				for (int k = 1; k <= n; ++k){
					int newj = j;
					for (; newj != 0 && s[k] != t[newj + 1]; newj = p[newj]);
					if (s[k] == t[newj + 1]) ++newj;
					if (newj == m)
						for (int x = 0; x <= max; ++x)
							f[i + 1][p[m]][x + 1] += f[i][j][x] / n;
					else
						for (int x = 0; x <= max; ++x)
							f[i + 1][newj][x] += f[i][j][x] / n;
				}
		/*for (int i = 0; i <= l; ++i){
			for (int j = 0; j <= m; ++j){
				printf("f[%d][%d] = %.10f g = %.10f\n", i, j, f[i][j], g[i][j]);
			}
		}*/
		ans = 0;
		for (int j = 0; j < m; ++j)
			for (int k = 1; k <= max; ++k)
				ans += f[l][j][k] * k;
		printf("Case #%d: %.10f\n", Ti, max - ans);
		//printf("Case #%d: %.10f\n", Ti, ans);
	}
	return 0;
}
