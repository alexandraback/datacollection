#include <stdio.h>
const int nmax = 100;

int n, s, p, t, T;
int f[nmax + 18][nmax + 18];

void update(int &a, int b)
{
    if (a < b) a = b;
}

int main()
{
//    freopen("B.in", "r", stdin);
//    freopen("B.out", "w", stdout);
    scanf("%d", &T);
    for (int cases = 1; cases <= T; ++cases) {
	scanf("%d%d%d", &n, &s, &p);
	for (int i = 1; i <= n; ++i) {
	    scanf("%d", &t);
	    int c1 = t / 3 + !!(t % 3), c2 = t / 3 + 1 + (t % 3 == 2);
	    bool t1 = c1 >= p, t2 = (c2 >= p && t);
	    for (int j = 0; j <= s; ++j) {
		f[i][j] = 0;
		if (j) update(f[i][j], f[i - 1][j - 1] + t2);
		update(f[i][j], f[i - 1][j] + t1);
	    }
//	    printf("%d ", t);
	}
	printf("Case #%d: %d\n", cases, f[n][s]);
    }
}
