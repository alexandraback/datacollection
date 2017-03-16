#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int ca, x, y, m, n, tmp, a, b;
int c[25][25];
double ans;

int main()
{
	freopen("b.out","w",stdout);
	ios::sync_with_stdio(false);
	c[1][0] = 1; c[1][1] = 1;
	for (int i = 2; i <= 20; i++) {
		c[i][0] = 1;
		for (int j = 1; j <= i; j++) 
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
	}
	cin >> ca;
	for (int t = 1; t <= ca; t++) {
		cin >> m >> x >> y;
		x = abs(x);
		if (m == 1) {
			if ((x == 0) && (y == 0)) ans = 1; else ans = 0;
		} else {
			tmp = 6; n = 1;
			while (tmp <= m) {
				n += 2; tmp += 2 * n + 3;
			}
			tmp = (n + 1) * n / 2;
			m = m - tmp;
			if (x + y <= n) ans = 1; else 
			if (x + y > n + 1) ans = 0; else {
				if ((x == 0) || (m ==0)) ans = 0; else {
				a = 0; b = 1 << m;
				for (int i = 0; i <= min(m, y); i++) {
					if (m - n - 1 > y) continue;
					a += c[m][i];
				}
				if (b == 0) ans = 0; else {
					ans = a; ans /= b;
					ans = 1 - ans;
				}
				}
			}
		}
		printf("Case #%d: %.7lf\n", t, ans);
	}
	return 0;
}

