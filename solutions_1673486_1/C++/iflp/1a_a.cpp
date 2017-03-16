#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 100005;
double p[N];
int n;

void solve ()
{
	static int kase = 0;
	int n, m;
	scanf("%d%d", &n, &m);
	double pip = 1;
	for (int i = 1; i <= n; ++i)
		scanf("%lf", &p[i]), pip *= p[i];
	double res1 = pip * (m - n + 1) + (1 - pip) * (2 * m - n + 1);
	double res3 = m + 2;
	double res2 = 1e100;
	pip = 1;
	for (int j = 1; j <= n; ++j)
	{
		double cur = pip * (2 * (1 + n - j) + m - n + 1) + 
			(1 - pip) * (2 * (1 + n - j) + m - n + 1 + m + 1);
		res2 = min(res2, cur);
		pip *= p[j];
	}
//	fprintf(stderr, "%.6lf %.6lf %.6lf\n", res1, res2, res3);
	printf("Case #%d: %.6lf\n",++kase, min(res1, min(res2, res3)));
}

int main ()
{
	int _; scanf("%d", &_);
	while (_--) solve();
}
