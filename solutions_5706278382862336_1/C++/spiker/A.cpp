#include <cstdio>
#include <string>
#include <algorithm>
#include <memory.h>
#include <cmath>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>

using namespace std;

long long GCD(long long a, long long b)
{
	return a ? GCD(b % a, a) : b;
}

int main(void)
{
	freopen("input.txt","r", stdin);
	freopen("output.txt","w", stdout);

	int t ;
	scanf("%d", &t);

	for (int q = 1; q <= t; q++)
	{
		long long a, b;
		scanf("%lld/%lld\n", &a, &b);
		long long gcd = GCD(a,b);
		a /= gcd;
		b /= gcd;
		bool ok = 0;

		for (int i = 0; i < 40; i++)
		{
			if ((1ll << i) == b)
			{
				ok = 1;
				break;
			}
		}
		if (!ok)
		{
			printf("Case #%d: impossible\n",q);
		}
		else
		{
			b /= 2;
			int ans = 1;
			while (a < b)
			{
				ans++;
				b /= 2;
			}
			printf("Case #%d: %d\n", q, ans);
		}
	}

	return 0;
}