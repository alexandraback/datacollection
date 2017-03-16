#include <cstdio>
#include <cstring>

const double EPS = 1E-8;

double c, f, x;

bool check(double t)
{
	double cur = 0;
	double rate = 2;
	double money = 0;
	double target = (c < x ? c : x);
	while (1)
	{
		//printf("%lf %lf %lf\n", rate, money, cur);
		if (cur >= t) return false;
		if (money >= x) return true;
		if (cur + (x - money) / rate <= t) return true;
		if (money < target)
		{
			double dt = (target - money) / rate;
			money = target;
			cur += dt;
		}
		else if (cur + c / f < t)
		{
			money -= c;
			rate += f;
		}
		else
		{
			double dt = (x - money) / rate;
			money = x;
			cur += dt;
		}
	}
}

void solve()
{
	scanf("%lf %lf %lf", &c, &f, &x);
	double lt = 0;
	double rt = x * 0.5;
	double mid;
	while ((rt - lt) > EPS)
	{
		mid = (rt + lt) * 0.5;
		if (check(mid)) rt = mid;
		else            lt = mid;
	}
	printf("%.7lf\n", mid);
}

int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	int ii, tt;
	scanf("%d", &tt);
	for (ii = 1; ii <= tt; ++ii)
	{
		printf("Case #%d: ", ii);
		solve();
	}
}