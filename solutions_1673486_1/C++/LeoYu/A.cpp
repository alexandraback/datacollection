#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

inline int	read()
{
	char ch = getchar(); int x = 0; bool flag = 0;
	for (; ch != '-' && (ch < '0' || ch > '9'); ch = getchar());
	if (ch == '-') 	{	flag = 1;	ch = getchar();	}
	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
	if (flag) return - x; return x;
}

inline void	Main()
{
	int A = read(), B = read();
	long double ans = B + 2, now = 1;
	for (int i = 0; i <= A; ++ i)
	{
		ans = min(ans, now * ((A - i) * 2 + B - A + 1) + (1 - now) * ((A - i) * 2 + B - A + 1 + B + 1));
		if (i < A)
		{
			double x; scanf("%lf", &x);
			now *= x;
		}
	}
	printf("%.8lf\n", (double)ans);
}

int main()
{
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	int T = read();
	for (int t = 1; t <= T; ++ t)
	{
		printf("Case #%d: ", t);
		Main();
	}
	return 0;
}
