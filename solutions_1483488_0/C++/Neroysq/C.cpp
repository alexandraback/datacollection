#include <stdio.h>
const int nmax = 2000000, dmax = 7;

int A, B;
int ed[nmax + 18], wdt, t;
int ans;

int calc(int n)
{
    ++wdt;
    int rnt = 0, k = 1;
    while (k <= n) k *= 10;
    k /= 10;
    for (int d = 10; d <= n; d *= 10, k /= 10) 
	if ((n / (d / 10)) % 10) {
	    int m = n / d + (n % d) * k;
	    if (m > n && m <= B && ed[m] != wdt)
		/*printf("%d %d\n", n, m), */++rnt, ed[m] = wdt;
	}
    return rnt;
}

int main()
{
//    freopen("C.in", "r", stdin);
//    freopen("C.out", "w", stdout);
    scanf("%d", &t);
    for (int cases = 1; cases <= t; ++cases) {
	ans = 0;
	scanf("%d%d", &A, &B);
	for (int i = A; i <= B; ++i) 
	    ans += calc(i);
	printf("Case #%d: %d\n", cases, ans);
    }
}
