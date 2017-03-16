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
#define isNumber(x) ('0' <= x && x <= '9')

int a, b;
double pp[MAXN];
double pr[MAXN];

inline double readDouble()
{
	char ch;
	double r = 0;
	double p = 1;
	bool t = 0;
	while(!isNumber(ch)) scanf("%c", &ch);
	for (; ch == '.' || isNumber(ch);scanf("%c", &ch))
	{
		if (t)
		{
			r += p * (ch - '0');
			p *= 0.1;
			continue;
		}
		if (ch == '.')
		{
			t = 1;
			p *= 0.1;
			continue;
		}
		r = r * 10 + (ch - '0');
	}
	return r;
}

inline void solve(int test_case)
{
	scanf("%d%d", &a, &b);
	double ans = b + 2;
	double p = 1;
	pp[0] = 1;
	for (int i = 0; i < a; ++i)
	{
		double t;
//		scanf("%lf", &t);
		t = readDouble();
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
