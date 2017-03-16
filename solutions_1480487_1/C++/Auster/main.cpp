#pragma comment(linker, "/STACK:16777216")
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>

using namespace std;

typedef long long LL;
typedef vector<int> vint;
typedef vector<vint> vvint;

int t, n;
double s[1 << 8];
double res[1 << 8];
double sum;

bool enough(int x, double m)
{
	double ss = 0;
	for(int i = 0; i < n; ++i)
	{
		if (i == x)
			continue;
		if (s[x] + sum * m > s[i])
			ss += s[x] + sum * m - s[i];
	}
	return ss > (1.0 - m) * sum;
}

int main()
{
	freopen("A.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	scanf("%d", &t);
	for(int I = 1; I <= t; ++I)
	{
		scanf("%d", &n);
		sum = 0;
		for(int j = 0; j < n; ++j)
		{
			scanf("%lf", &s[j]);
			sum += s[j];
		}
		for(int j = 0; j < n; ++j)
		{
			double L = 0, R = 1.0;
			while (R - L > 1e-10)
			{
				double M = (L + R) / 2;
				if (enough(j, M))
					R = M;
				else
					L = M;
			}
			res[j] = R;
		}
		printf("Case #%d:", I);
		for(int j = 0; j < n; ++j)
			printf(" %.7lf", 100.0 * res[j]);
		printf("\n");
	}
	return 0;
}