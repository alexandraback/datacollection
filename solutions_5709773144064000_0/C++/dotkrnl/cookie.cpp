#include <cstdio>
using namespace std;

double work(double c, double f, double x)
{
	double t = 0., m = 0., s = 2.;
	while(x / s > x / (s + f) + c / s)
	{
		t += c / s;
		s += f;
	}

	return t + x / s;
}

int main()
{
	int t;

	freopen("cookie.in", "r", stdin);
	freopen("cookie.out", "w", stdout);

	scanf("%d", &t);
	for(int i = 1; i <= t; ++i)
	{
		printf("Case #%d: ", i);
		double c, f, x;
		scanf("%lf%lf%lf", &c, &f, &x);
		printf("%.7lf\n", work(c, f, x));
	}

	fclose(stdin);
	fclose(stdout);
}
