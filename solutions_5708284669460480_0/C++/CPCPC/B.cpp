#include <cstring>
#include <cstdio>
const int N = 255;
double g[N][N];
int a[N], f[N];
char s[N], ss[N];
int main() {
	int T;
	scanf("%d", &T);
	for (int C = 1; C <= T; C++) {
		int n, l, m;
		scanf("%d%d%d", &n, &l, &m);
		scanf("%s", ss);
		memset(a, 0, sizeof(a));
		memset(g, 0, sizeof(g));
		for (int i = 0; i < n; i++) a[ss[i]-'A']++;
		scanf("%s", s);
		bool ok = true;
		for (int i = 0; i < l; i++) 
			if (a[s[i]-'A'] == 0) ok = false;
		if (!ok) { printf("Case #%d: 0\n", C); continue; }
		for (int i = 1, j = 0; i < l; i++) {
			while (j&&(s[i] != s[j])) j = f[j];
			f[i+1] = (s[i] == s[j])? ++j: 0;
		}
		int cnt = (m-l)/(l-f[l])+1;
		double ans = cnt;
		g[0][0] = 1;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < l; j++)
				for (int k = 0; k < n; k++) {
					int p = j;
					while (p&&(s[p] != ss[k])) p = f[p];
					if (s[p] == ss[k]) p++;
					if (p == l) { p = f[p]; ans -= g[i][j]/n; }
					g[i+1][p] += g[i][j]/n;
				}
		}
		printf("Case #%d: %.12lf\n", C, ans);
	}
}
