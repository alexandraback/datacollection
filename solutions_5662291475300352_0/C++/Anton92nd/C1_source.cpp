#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

const double eps = 1e-12;

bool doubleEqual(double a, double b)
{
	return fabs(a - b) < eps;
}

bool doubleLess(double a, double b)
{
	return a < b && !doubleEqual(a, b);
}

int n;
int d1, m1, d2, m2;
int dist;

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t, p;
	scanf("%d", &t);
	for (int q = 0; q < t; q++)
	{
		printf("Case #%d: ", q + 1);
		scanf("%d", &n);
		if (n == 2)
		{
			scanf("%d%d%d%d%d%d", &d1, &p, &m1, &d2, &p, &m2);
			if (m1 > m2)
			{
				swap(d1, d2);
				swap(m1, m2);
			}
		}
		else
		{
			scanf("%d%d%d", &d1, &p, &m1);
			if (p == 2)
			{
				d2 = d1;
				m2 = m1 + 1;
			}
			else
			{
				printf("0\n");
				continue;
			}
		}
		double v1 = 360.0 / m1;
		double v2 = 360.0 / m2;
		double dist = 360 + d2 - d1;
		double t2 = (360.0 - d2) / v2;
		double t1 = m1 == m2 ? 1e9 : dist / (v1 - v2);
		if (doubleLess(t2, t1))
		{
			printf("0\n");
		}
		else
		{
			printf("1\n");
		}
	}
	return 0;
}