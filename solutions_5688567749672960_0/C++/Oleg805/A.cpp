#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <functional>
using namespace std;

#pragma comment(linker,"/STACK:100000000")

char s[1050];

long long rev(long long n)
{
	long long res = 0;
	while (n > 0)
	{
		res = res*10 + n % 10;
		n /= 10;
	}
	return res;
}

long long solve2(long long n)
{
	long long ans = n;
	long long n1 = n;
	long long n2 = 0;
	long long ten = 1;
	while (n1 > 0)
	{
		n2 = n2 + n1 % 10 * ten;
		n1 /= 10;
		ten *= 10;
		if (n2 > 0)
		{
			ans = min(ans, rev(n1) + n2);
		}
		else if (rev(n1) != 1)
		{
			if (rev(n1 - 1) == 1)
			{
				ans = min(ans, ten);
			}
			else
			{
				ans = min(ans, rev(n1 - 1) + ten);
			}
		}
		if (rev(n1) == 1)
		{
			ans = min(ans, n2);
		}
	}
	return ans;
}

long long solve1(long long n)
{
	if (n < 10)
		return n;
	long long ten = 1;
	long long n1 = n;
	while (n1 > 0)
	{
		ten *= 10;;
		n1 /= 10;
	}
	return solve1(ten/10 - 1) + solve2(n) + 1;
}

void solve(int t)
{
	long long n;
	scanf("%lld", &n);
//	printf("%lld\n", solve2(n));
	printf("Case #%d: %lld\n", t, solve1(n));
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i)
	{
		solve(i + 1);
	}
	return 0;
}
