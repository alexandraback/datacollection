#include<cstdio>
#include<cmath>
#include<algorithm>
#define NMAX 2005
using namespace std;

void solve()
{
	double T[NMAX], X[NMAX], d;
	int n, na;

	scanf("%lf%d%d", &d, &n, &na);
	for(int i = 0; i < n; ++i)
		scanf("%lf%lf", T + i, X + i);

	while(na--)
	{
		double a;
		scanf("%lf", &a);
		double ans = sqrt(2*d/a);
		if(n == 2)
		{
			double v = (X[1] - X[0]) / T[1];
			ans = max(ans, (d - X[0]) / v);
		}
		printf("%lf\n", ans);
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small.out", "w", stdout);

	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; ++t)
	{
		printf("Case #%d:\n", t);
		solve();
	}
	return 0;
}
