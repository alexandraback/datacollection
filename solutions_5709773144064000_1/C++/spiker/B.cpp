#include <cstdio>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <set>
#include <map>
#include <queue>
#include <stack>

using namespace std;

double c,f,x;

double solve(int t)
{
	double res = 0;
	for (int i = 0; i < t - 1; i++)
		res += c / (2.0 + i * f);
	res += x / (2.0 + (t - 1) * f);
	return res;
}

double eps = 1e-9;

int main(void)
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int t;
	scanf("%d", &t);

	for (int q = 1; q <= t; q++)
	{
		
		scanf("%lf%lf%lf", &c, &f, &x);
		int l = 1;
		int r = (int)x + 1 - 2;
		while (r - l  > 2)
		{
			int m1 = l + (r - l ) / 3;
			int m2 = r - (r - l ) / 3;
			double sm1 = solve(m1);
			double sm2 = solve(m2);
			if (solve(m1) - solve(m2) > eps)
			{
				l = m1;
			}
			else
				r = m2;
		}
		double ans = solve(l);
		for (int i = l + 1; i <= r; i++)
			ans = min(ans, solve(i));
		printf("Case #%d: %.7lf\n", q, ans);
	}
	return 0;
}