#include <cstdio>
#include <cmath>

int main()
{
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int tc = 0;++tc <= t;tc) {
		int j, p, s, q;
		scanf("%d %d %d %d", &j, &p, &s, &q);
		int ps[10][10] = { 0, };
		int js[10][10] = { 0, };
		int jp[10][10] = { 0, };
		int res[1000][3],cnt=-1;
		for (int i = 0;i < j;++i)
			for (int j = 0;j < p;++j)
				for (int k = 0;k < s;++k)
					if (jp[i][j] < q && js[i][k] < q && ps[j][k] < q) {
						res[++cnt][0] = i + 1;
						res[cnt][1] = j + 1;
						res[cnt][2] = k + 1;
						++jp[i][j];
						++js[i][k];
						++ps[j][k];
					}
		printf("Case #%d: %d\n", tc, cnt+1);
		for (int i = 0;i <= cnt;++i)
			printf("%d %d %d\n", res[i][0], res[i][1], res[i][2]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}