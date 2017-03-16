#include <iostream>
#include <cstdio>
#include <cmath>

#define SMALL
//#define LARGE

using namespace std;

int t, n, x, y;
double c[1005][1005];

void init() {
  c[1][0] = c[1][1] = 1.0;
	for (int i = 2; i <= 1000; ++i) {
		c[i][0] = c[i][i] = 1.0;
		for (int j = 1; j < i; ++j)
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
	}
}

int main()
{
#ifdef SMALL
	freopen("B_small.in", "r", stdin);
	freopen("B_small.out", "w", stdout);
#endif
#ifdef LARGE
	freopen("B_large.in", "r", stdin);
	freopen("B_large.out", "w", stdout);
#endif
	init();
	scanf("%d", &t);
	for (int Case = 1; Case <= t; ++Case) {
		scanf("%d %d %d", &n, &x, &y);
		if (x < 0)
			x *= -1;
		int n0, m0;
		n0 = 1;
		while (true) {
			n0 += 2;
      if ((n0 + 1) * n0 > 2 * n)
				break;
		}
		n0 -= 2;
		m0 = (1 + n0) * n0;
		m0 >>= 1;
		m0 = n - m0;
//		printf("%d %d %d %d\n", x, y, m0, n0);
		printf("Case #%d: ", Case);
		if (x + y < n0 || (x + y == n0 + 1) && (y < m0 - n0 - 1)) {
			printf("1.0\n");
		} else if (x + y > n0 + 1 || y >= m0 || y == n0 + 1) {
			printf("0.0\n");
		} else {
			if (m0 > n0 + 1) {
				y -= m0 - n0 - 1;
				m0 = 2 * n0 - m0 + 2;
			}
			double ans = 0.0;
			for (int i = y; i < m0; ++i)
				ans += c[m0][i + 1];
			printf("%.6lf\n", ans / pow(2.0, m0));
		}
	}
	return 0;
}
