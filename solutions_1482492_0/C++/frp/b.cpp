#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;
vector<long double> solve_eq(long double a, long double b, long double c)
{
	long double d = b * b - 4 * a * c;
	vector<long double> sols;
	if(d == 0) sols.push_back(-b / (2 * a));
	else if(d > 0)
	{
		sols.push_back((-b - sqrt(d)) / (2 * a));
		sols.push_back((-b + sqrt(d)) / (2 * a));
	}
	return sols;
}
void test(int num)
{
	long double d; int n, a;
	cin >> d >> n >> a;
	vector<long double> ts(n), xs(n), as(a);
	for(int i = 0; i < n; i++)
		cin >> ts[i] >> xs[i];
	for(int i = 0; i < a; i++)
		cin >> as[i];
	cout << "Case #" << num << ":\n";
	for(int i = 0; i < a; i++)
	{
		long double xmy = 0, xot = xs[0], v0 = 0;
		for(int j = 1; j < n; j++)
		{
			long double td = ts[j] - ts[j - 1];
			long double xd = xs[j] - xs[j - 1];
			long double v = xd / td;
			if(xs[j] >= d)
			{
				ts[j] -= (xs[j] - d) / v;
				xs[j] = d;
				td = ts[j] - ts[j - 1];
				xd = xs[j] - xs[j - 1];
			}
			vector<long double> t_sols = solve_eq(as[i] / 2.0, v0 - v, xmy - xot);
			long double t_sol = -1;
			for(int ti = 0; ti < t_sols.size(); ti++)
				if(t_sols[ti] >= 0 && t_sols[ti] <= td && v0 + as[i] * t_sols[ti] >= v)
				{
					t_sol = t_sols[ti];
					break;
				}
			if(t_sol >= 0)
			{
				xmy = xs[j];
				xot = xs[j];
				v0 = v;
			}
			else
			{
				xmy += as[i] * td * td / 2.0 + v0 * td;
				v0 += as[i] * td;
				xot = xs[j];
			}
		}
		long double res = ts.back();
		if(xmy < d)
		{
			vector<long double> sols = solve_eq(as[i] / 2.0, v0, xmy - d);
			long double t_sol = 0;
			for(int i = 0; i < sols.size(); i++)
				if(sols[i] >= 0)
				{
					t_sol = sols[i];
					break;
				}
			res += t_sol;
		}
		cout << res << "\n";
	}
}
int main()
{
	int t;
	cin >> t;
	cout << fixed << setprecision(7);
	for(int i = 1; i <= t; i++)
		test(i);
	return 0;
}
