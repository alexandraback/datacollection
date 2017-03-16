#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 128;
int main()
{
	int tc, n, q;
	double dis, x[N], t[N], acc;
	scanf("%d", &tc);
	for (int cas = 1; cas <= tc; cas++)
	{
		scanf("%lf %d %d", &dis, &n, &q);
		for (int i = 0; i < n; i++)
			scanf("%lf %lf", t + i, x + i);
		printf("Case #%d:\n", cas);
		for (int i = 0; i < q; i++)
		{
			scanf("%lf", &acc);
			double ans = sqrt(2 * dis / acc);
			if (n == 1)
				printf("%lf\n", ans);
			else
				printf("%lf\n", max(ans, (t[1] - t[0]) / (x[1] - x[0]) * (dis - x[0]) + t[0]));
		}
	}
	return 0;
}

