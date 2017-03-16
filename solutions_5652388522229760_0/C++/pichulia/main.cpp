#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int n;
long long int dap()
{
	bool a[10] = { 0, };
	int i, j, k;
	int res = 0;
	for (i = 1; ; i++)
	{
		long long int m = (long long int)n*i;
		while (m)
		{
			res += (1 - a[m % 10]);
			a[m % 10] = 1;
			m /= 10;
		}
		if (res == 10)break;
	}
	return (long long int)n*i;
}
void test()
{
	for (n = 1; n < 1000000; n++)
	{
		long long int k= dap();
		if (k > 20*n)printf("%d\n", n);
	}
	printf("done");
}
int main()
{
	int t;
	int tv = 1;

	freopen("A-small-attempt0.in", "rt", stdin);
	freopen("A-small-attempt0.out", "wt", stdout);

	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		printf("Case #%d: ", tv);
		if (n > 0)
		{
			printf("%lld\n", dap());
		}
		else
		{
			printf("INSOMNIA\n");
		}
		tv++;
	}
}