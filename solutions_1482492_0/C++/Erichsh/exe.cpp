#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <cstring>
#include <string>
using namespace std;

int main ()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	long long tc;		scanf("%lld", &tc);
	for (long long T = 1; T <= tc; T++)
	{
		printf("Case #%lld:\n", T);
		
		double d;	int n, aa;
		scanf("%lf%d%d", &d, &n, &aa);
		double t[100], x[100];
		for (int i = 1; i <= n; i++)	scanf("%lf%lf", t+i, x+i);
		for (int i = 0; i < aa; i++)
		{
			double a ;	scanf("%lf", &a);
			if (n == 1)
			{
				double t0 = d * t[1] / x[1], tt = sqrt(2.0 * d / a);
				if (tt <= t0)	printf("%.7lf\n", t0);
				else			printf("%.7lf\n", tt);
			}
			else
			{
				double t0 = sqrt(2.0 * x[1] / a), v;
				if(t0 < t[1])	
				{
					v = x[1] / t[1];
					double tt = t[1] + (-2.0 * v + sqrt(4*v*v + 8*a*(x[2]-x[1]))) / (2*a);
					double tx = t[1] + (d-x[1]) / ((x[2]-x[1])/(t[2]-t[1]));
					if (tt < tx)	printf("%.7lf\n", tx);
					else			printf("%.7lf\n", tt);
				}
				else
				{
					double tt = sqrt(2.0*d/a);
					double tx = t[1] + (d-x[1]) / ((x[2]-x[1])/(t[2]-t[1]));
					if (tt < tx)	printf("%.7lf\n", tx);
					else			printf("%.7lf\n", tt);
				}
			}
		}
	}
}