#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

const double eps = 1e-9;

bool double_less(double a, double b)
{
	return b - a > eps;
}

int t, n;
int ar[300];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &t);
	for (int q = 0; q < t; q++)
	{
		scanf("%d", &n);
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &ar[i]);
			sum += ar[i];
		}
		printf("Case #%d:", q + 1);
		double mid = 2.0 * sum / (n * 1.0);
		int cnt = n, sum2 = 0;
		for (int i = 0; i < n; i++)
		{
			if (double_less(mid, ar[i] * 1.0))
			{
				cnt--;
			}
			else
			{
				sum2 += ar[i];
			}
		}
		double mid2 = (sum + sum2) / (cnt * 1.0);
		for (int i = 0; i < n; i++)
		{
			if (double_less(mid, ar[i] * 1.0))
			{
				printf(" %.6lf", 0.0);
			}
			else
			{
				printf(" %.6lf", (mid2 - ar[i]) / (sum * 1.0) * 100.0);
			}
		}
		printf("\n");
	}
	return 0;
}