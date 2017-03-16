#include <iostream>
using namespace std;


const int maxit = 1e7;

void solve()
{
	double C, F, X;
	scanf("%lf%lf%lf", &C, &F, &X);
	double v = 2.;
	double t = 0;
	double ans = t + X / v;
	for (int i = 0; i < maxit; i++)
	{
		t += C / v;
		v += F;
		double curans = t + X / v;
		ans = min(ans, curans);
	}
	printf("%.10lf", ans);
}


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++)
	{
		fprintf(stderr, "Case #%d\n", i);
		printf("Case #%d: ", i);
		solve();
		printf("\n");
	}



	return 0;
}