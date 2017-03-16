#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <math.h>
#include <memory.h>


using namespace std;

long long rev(long long a)
{
	long long res = 0;
	while (a)
	{
		res = res * 10 + a%10;
		a/=10;
	}
	return res;
}

long long dec(int n)
{
	long long res = 1;
	for (int i = 0; i < n; i++)
		res *= 10;
	return res;
}

long long upg(int l)
{
	if (l == 1)
		return 9;
	long long res = 0;
	int ll = l / 2 + l % 2;
	res += dec(ll);
	
	res += dec(l - ll);
	res -= 1;
	return res;
}

long long take(long long a, int n)
{
	long long b = rev(a);
	long long res = 0;
	for (int  i = 0; i < n; i++)
	{
		res = res * 10 + b % 10;
		b /= 10;
	}
	return res;
}

long long calc(long long N)
{
	long long res = 0;
	int l = 0;
	int a = N;
	while (a)
	{
		a /= 10;
		l++;
	}
	res = 1;
	for (int i = 1; i < l; i++)
		res += upg(i);
	if (N > dec(l-1))
	{
		long long p = N - dec(l-1);
		for (int i = 1; i <= l; i++)
		{
			long long q = take(N, i);
			long long w = N - q * dec(l - i);
			if (w == 0)
				continue;
			q= rev(q);
			long long r = q + 1 + w - 1;
			p = min(p, r);
		}
		res += p;
	}
	return res;
}

int main()
{
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);


	int T;
	cin >> T;

	
	for (int t = 0; t < T; t++)
	{
		long long N;
		cin >> N;
		long long res;
		
		if (N < 20)
			res = N;
		else
		{
			res = calc(N);
			for (int i = 1; i < 10; i++)
				res = min(res, calc(N - i) + i);
		}
		
		printf("Case #%d: %lld\n", t+1, res);
	}

	return 0;
}