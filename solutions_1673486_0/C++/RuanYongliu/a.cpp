#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define sqr(x) ((x) * (x))
#define two(x) (1 << (x))
#define ord(x, y, z) ((x) <= (y) && (y) <= (z))
#define X first
#define Y second

typedef long long LL;
typedef pair<int, int> pair2;

const int N = 100020;
const double eps = 1e-9;
const int oo = 1000000000;

int n, m;
double p[N];

void init()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%lf", &p[i]);
	}
}

void solve()
{
	double ans = m + 2;
	double pp = 1;
	for (int bs = n; bs >= 0; --bs) {
		ans = min(ans, pp * (bs * 2 + m - n + 1) + (1 - pp) * (bs * 2 + 2 * m - n + 2));
		pp = pp * p[n - bs];
	}
	printf("%.8lf\n", ans);
}

int main()
{
	int T, cas = 0;
	scanf("%d", &T);
	while (T--) {
		init();
		printf("Case #%d: ", ++cas);
		solve();
	}
	return 0;
}

