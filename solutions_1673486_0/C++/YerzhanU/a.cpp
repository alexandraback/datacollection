#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <vector>

using namespace std;

#define MAXN 100000

int a, b;
double pp[MAXN];
double pr[MAXN];

inline void solve(int test_case)
{
	scanf("%d%d", &a, &b);
	double ans = b + 2;
	double p = 1;
	pp[0] = 1;
	for (int i = 0; i < a; ++i)
	{
		double t;
		scanf("%lf", &t);
		pp[i] = p * t;
		pr[i] = p * (1 - t);
		p *= t;
	}
	double t = p * (b - a + 1) + (1 - p) * (b - a + 1 + b + 1);
	ans = min(ans, t);
	for (int i = 0; i < a - 1; ++i)
		ans = min(ans, pp[a - 1 - i - 1] * (b - a + 1 + 2 * (i + 1)) + (1 - pp[a - 1 - i - 1]) * (b - a + 1 + 2 * (i + 1) + b + 1));
	printf("Case #%d: %.10lf\n", test_case + 1, ans);
}

int main()
{
	int test_cases;
	scanf("%d", &test_cases);
	for (int test_case = 0; test_case < test_cases; ++test_case)
	{
		solve(test_case);
	}
	return 0;
}
