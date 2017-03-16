#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

long long a, b;
char ch;

long long gcd(long long x, long long y)
{
	if (y == 0) return x; else return gcd(y, x % y);
}

void work()
{
	cin >> a;
	cin >> ch;
	cin >> b;
	long long g = gcd(a, b);
	a /= g;
	b /= g;
	bool flag = false;
	for (long long i = 1ll; i <= 40ll; ++i)
	{
		if (b == (1ll << i))
		{
			flag = true;
			break;
		}
	}
	if (!flag)
	{
		printf("impossible\n");
		return;
	}
	int ans = 1;
	while (a < (b >> 1))
	{
		++ans;
		a <<= 1;
	}
	printf("%d\n", ans);
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; ++i)
	{
		printf("Case #%d: ", i + 1);
		work();
	}
	return 0;
}
