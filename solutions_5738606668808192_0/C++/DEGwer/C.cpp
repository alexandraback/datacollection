#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int main()
{
	int n = 16, m = 50;
	freopen("out1.txt", "w", stdout);
	printf("Case #1:\n");
	for (ll p = 0; p < m; p++)
	{
		ll t = (1LL << (n / 2 - 1)) + p * 2 + 1;
		for (int i = n / 2 - 1; i >= 0; i--)
		{
			printf("%d", (0 != (t&(1 << i))));
		}
		for (int i = n / 2 - 1; i >= 0; i--)
		{
			printf("%d", (0 != (t&(1 << i))));
		}
		for (int i = 2; i <= 10; i++)
		{
			ll now = 0;
			for (int j = n / 2 - 1; j >= 0; j--)
			{
				now *= i;
				now += (0 != (t&(1 << j)));
			}
			printf(" %lld", now);
		}
		printf("\n");
	}
}