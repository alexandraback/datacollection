#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 100001;
double p[N], q[N];
int main() {
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out","w",stdout);
	int ii, tt;
	int i, n, m;
	double mn;
	scanf("%d", &tt);
	for (ii = 1; ii <= tt; ii++) {
		scanf("%d%d", &n, &m);
		for (i = 1; i <= n; i++)
			scanf("%lf", &p[i]);
		q[0] = 1;
		for (i = 1; i <= n; i++)
			q[i] = q[i-1] * p[i];
		mn = m + 2;
		for (i = 0; i <= n; i++)
			mn = min(mn, q[n-i] * (2 * i + m - n + 1) + (1 - q[n-i]) * (2 * i + m - n + 1 + m + 1));
		printf("Case #%d: %lf\n", ii, mn);
	}
	return 0;
}
