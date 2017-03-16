#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>


using namespace std;


long long gcd(long long a, long long b)
{
	while(a != 0 && b != 0)
		if(a > b)
			a %= b;
		else
			b %= a;
	return a + b;
}


void solve(long long a, long long b, int t)
{
	long long g = gcd(a, b);
	a /= g;
	b /= g;
	long long x = 1;
	int pow = -1;
	for(int i = 0; i < 50; i++)
	{
		if(b == x)
		{
			pow = i;
			break;
		}
		x *= 2;
	}
	if(pow == -1)
	{
		printf("Case #%d: impossible\n", t);
		return;
	}
	int ans = 1;
	while(a < b / 2)
	{
		ans++;
		b /= 2;
	}
	printf("Case #%d: %d\n", t, ans);
}


int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; i++)
	{
		long long a, b;
		scanf("%lld/%lld", &a, &b);
		solve(a, b, i + 1);
	}
}