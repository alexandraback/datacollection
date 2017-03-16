#include <cstdio>

int f[105][105];
int n, m, p;
int T;

void work()
{
	scanf("%d%d%d", &n, &m, &p);
	for (int i = 0; i <= n; ++i) for (int j = 0; j <= m; ++j)
		f[i][j] = -0x3f3f3f3f;
	f[0][0] = 0;
	for (int i = 1; i <= n; ++i) {
		int score;
		scanf("%d", &score);
		for (int j = 0; j <= m; ++j) {
			//non-surprising
			int bestresult = score / 3 + (score % 3 != 0);
			int value = f[i - 1][j] + (bestresult >= p);
			f[i][j] = value;
			//surprising
			if (j > 0) {
				int stand = score / 3;
				for (int a = stand - 2; a <= stand + 2; ++a)
					for (int b = a; b <= stand + 2; ++b) {
						int c = score - a - b;
						if (a >= 0 && c >= b && c - a == 2) {
							int value = f[i - 1][j - 1] + (c >= p);
							if (value > f[i][j]) f[i][j] = value;
						}
					}
			}
		}
	}
	static int ttt = 0;
	printf("Case #%d: %d\n", ++ttt, f[n][m]);
}

int main()
{
	scanf("%d", &T);
	while (T--) work();
}