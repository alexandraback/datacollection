#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ldb;

#define forab(i, a, b) for(int i = int(a); i < int(b); ++i)
#define forba(i, b, a) for(int i = int(b) - 1; i >= int(a); --i)
#define forn(i, n) forab(i, 0, n)

const ldb EPS = 1e-14;
const ldb M_PI = acos(-1.0L);

const int MAXN = 20;

int d[MAXN];
int m[MAXN];
int n;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int T;
	scanf("%d ", &T);
	forn(test, T) {
		printf("Case #%d: ", test + 1);

		int q;
		scanf("%d", &q);

		n = 0;

		forn(i, q) {
			int h;
			scanf("%d%d%d", &d[n], &h, &m[n]);
			forn(j, h) {
				d[n + 1] = d[n];
				m[n + 1] = m[n] + 1;
				n++;
			}
		}

		if (n <= 1) {
			printf("0\n");
			continue;
		}

		if (n == 2) {
			if (m[0] > m[1]) {
				swap(m[0], m[1]);
				swap(d[0], d[1]);
			}

			int ans = 0;

			ldb t = m[1] * ((360 - d[1]) / 360.0L);

			assert(d[1] / 180.0L * M_PI + t / m[1] * 2 * M_PI > 2 * M_PI - EPS);

			ldb x = d[0] / 180.0L * M_PI + t / m[0] * 2 * M_PI;

			if (d[0] < d[1]) {
				if (x > 2 * M_PI - EPS)
					ans = 1;
			} else {
				if (x > 4 * M_PI - EPS)
					ans = 1;
			}

			printf("%d\n", ans);
			continue;
		}

		printf("neudacha\n");
	}
	return 0;
}
