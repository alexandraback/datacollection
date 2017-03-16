#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <cassert>
#include <map>
#include <string.h>
#include <ctime>
#include <iostream>

using namespace std;

const char* FILE_NAME_IN = "input.txt";
const char* FILE_NAME_OUT = "output.txt";

const int size = 1000 + 5;
const int inf = 1000 * 1000 * 1000 + 5;
double const eps = 1e-9;

int a[size];
double m[size];

double max(double a, double b)
{
	return a > b ? a : b;
}

int main ()
{
	freopen(FILE_NAME_IN, "r", stdin);
	freopen(FILE_NAME_OUT, "w", stdout);

	int t, it, n, i;
	int sum;
	double x;

	scanf("%d", &it);
	
	for (t = 1; t <= it; t++)
	{
		printf("Case #%d: ", t);
		scanf("%d", &n);
		sum = 0;
		for (i = 0; i < n; i++)
		{
			scanf("%d", a + i);
			sum += a[i];
		}
		for (int j = 0; j < n; j++)
		{
			double l = 0, r = 1, m = 0.5;
			while (r - l > eps)
			{
				m = (l + r) / 2;
				x = 0;
				for (i = 0; i < n; i++)
					x += max((a[j] - a[i]) / (double) sum + m, 0);
				if (x > 1)
					r = m;
				else
					l = m;
			}
			printf("%.6lf ", 100 * r);
		}
		printf("\n");
	}
	
	return 0;
}