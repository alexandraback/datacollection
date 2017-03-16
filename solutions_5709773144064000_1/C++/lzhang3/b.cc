#include <iostream>

#include <cstdio>
#include <cstdlib>

#include <vector>
#include <algorithm>

using namespace std;

double solve()
{
	double c, f, x;  cin >> c >> f >> x;
	double s = 0.0, tt = 0.0, u = 2.0;
	if (c > x)
	{
		return x / u;
	}
	double dt = c / u;
	while (true)
	{
		tt += dt;
		s += dt * u;
		double nobuy = (x - s) / u;
		double   buy = (x - (s - c)) / (u + f);
		if (buy < nobuy)
		{
			s -= c;
			u += f;
		}
		dt = c / u;
		if (min(buy, nobuy) < dt)
		{
			return tt + min(buy, nobuy);
		}
	}
}

int main(void)
{
	int t;  cin >> t;
	for (int i = 1; i <= t; ++i)
	{
		double val = solve();
		printf("Case #%d: %.8lf\n", i, val);
	}
}