#include <stdio.h>
#include <stdarg.h>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
#define clr(a) memset(a, 0, sizeof(a))

typedef long long ll;
typedef std::pair<int, int> pii;
#define DEBUG 1

void dbg(const char * fmt, ...)
{
#if DEBUG
	va_list args;
	va_start(args, fmt);
	vfprintf(stdout, fmt, args);
	va_end(args);
#endif
}

double ar[500];
double sum;
int n;

double solve_case(int x)
{
	double l = 0, r = 1;
	for(int _ = 0; _ < 100; _++)
	{
		double m = (l + r) / 2;
		double v = ar[x] + m * sum;
		double s = 0;
		for(int i = 0; i < n; i++)
			s += std::max(0., (v - ar[i]) / sum);
		if (s < 1)
			l = m;
		else
			r = m;
	}
	return l;
}


void solve(int test_case)
{
	printf("Case #%d: ", test_case);
	scanf("%d", &n);
	sum = 0;
	for(int i = 0; i < n; i++)
	{
		scanf("%lf", &ar[i]);
		sum += ar[i];
	}
	for(int i = 0; i < n; i++)
		printf("%.10lf ", solve_case(i) * 100);
	printf("\n");
}





int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		solve(i);

	return 0;
}
