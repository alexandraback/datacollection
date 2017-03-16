#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <functional>
using namespace std;

#pragma comment(linker,"/STACK:100000000")

const double eps = 1e-10;

int a[505];
double ans[505];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int T, tt;
	scanf("%d", &T);
	for (tt = 0; tt < T; ++tt)
	{
		int i, j, u;
		int n, s;
		s = 0;
		scanf("%d", &n);
		for (i = 0; i < n; ++i)
		{
			scanf("%d", &a[i]);
			s += a[i];
		}
		for (i = 0; i < n; ++i)
		{
			double left = 0, right = 1;
			for (j = 0; j < 100; ++j)
			{
				double med = (left + right)/2;
				double xx = 0;
				for (u = 0; u < n; ++u)
					if (u != i && a[u] <= a[i] + s*med + eps)
						xx += (a[i] + s*med - a[u]);
				if ((1 - med)*s > xx + eps)
					left = med;
				else
					right = med;
			}
			ans[i] = left;
		}
		printf("Case #%d: ", tt + 1);
		for (i = 0; i < n; ++i)
			printf("%.8lf ", ans[i]*100);
		printf("\n");
	}
	return 0;
}