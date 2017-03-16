#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

long long c[30][30];
int n, x, y;

void work()
{
	int p = (x + y) / 2;
	p = (2 * p + 1) * (p + 1);
	if(n >= p)
	{
		printf("1.00000000\n");
		return;
	}
	else
	{
		int tp = (x + y) / 2 - 1;
		tp = (2 * tp + 1) * (tp + 1);
		if(n <= tp)
		{
			printf("0.00000000\n");
			return;
		}
		n -= tp;
	}
	if(x == 0)
	{
		printf("0.00000000\n");
		return;
	}
	long long u, v;
	u = 0, v = 0;
	for(int i = 0; i <= min(n, x + y); ++i)
	{
		int j = n - i;
		if(j <= x + y)
		{
			u += c[n][i];
			if(i >= y + 1) v += c[n][i];
		}
	}
	if(u == 0) u = 1;
	double ans = (double)v / u;
	printf("%lf\n", ans);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	for(int i = 0; i <= 20; ++i)
	{
		c[i][0] = 1;
		for(int j = 1; j <= i; ++j) c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
	}
	int ca;
	scanf("%d", &ca);
	for(int i = 1; i <= ca; ++i)
	{
		scanf("%d%d%d", &n, &x, &y);
		x = abs(x), y = abs(y);
		printf("Case #%d: ", i);
		work();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}