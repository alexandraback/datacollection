#include <vector>
#include <stack>
#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <functional>
#include <set>
#include <cstring>
#include <queue>
#include <stdlib.h>
#include <time.h>
#define all(o) (o).begin(), (o).end()
#define mp(x, y) make_pair(x, y)
//#define x first
//#define y second
//#define pt pair <double, double>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int S = int(2e6) + 5;
const ull INF = ull(1e9) + 7;



ull sum(ull x, ull y, ull p)
{
	x %= p;
	y %= p;
	if(x >= p - y)
		return x - (p - y);
	return x + y;
}

ull mult(ull x, ull y, ull p)
{
	ull res = 0, cur = x;
	while(y)
	{
		if(y & 1)
			res = sum(res, cur, p);
		cur = sum(cur, cur, p);
		y >>= 1;
	}
	return res;
}

ull deg(ull x, ull y, ull p)
{
	ull a = x, res = 1;
	while(y)
	{
		if(y & 1)
			res = mult(res, a, p);
		a = mult(a, a, p);
		y >>= 1;
	}
	return res;
}

ull rnd()
{
	return (ull(rand()) << 32) + ull(rand());
}

bool prime(ull n)
{
	if(n == 2 || n == 3 || n == 5)
		return true;
	if(n % 2 == 0)
		return false;
	int r = 70, s = 0;
	bool broken = 0;
	ull m = n - 1, a, x;
	while(!(m & 1))
	{
		m >>= 1;
		s++;
	}
	for(int i = 0; i < r; i++)
	{
		a = rnd() % (n - 4) + 2;
		x = deg(a, m, n);
		if(x == 1 || x == n - 1)
			continue;
		broken = 0;
		for(int j = 0; j < s - 1; j++)
		{
			x = mult(x, x, n);
			if(x == 1)
				return false;
			if(x == n - 1)
			{
				broken = 1;
				break;
			}
		}
		if(!broken)
			return false;
	}
	return true;
}

ull gcd(ull a, ull b)
{
	return (b == 0 ? a : gcd(b, a % b));
}

ull diff(ull x, ull y)
{
	if(x > y)
		return x - y;
	return y - x;
}

ull pollard(ull n)
{
	if(n == 4)
		return 2;
	ull x, y, i, stage;
	while(1)
	{
		x = rnd() % (n - 4) + 2;
		y = 1;
		i = 0;
		stage = 2;
		//	pl = rnd() % (n - 3) + 3;
		while(gcd(n, diff(x, y)) == 1 && i < S)
		{
			if(i == stage)
			{
				y = x;
				stage <<= 1;
			}
			x = (mult(x, x, n) + 1) % n;
			i++;
		}
		if(i != S)
			break;
	}
	return gcd(n, diff(x, y));
}

int t, cnt = 16, num = 50;

ull convert(ull mask, ull base)
{
	ull res = 0, a = 1;
	for(int i = 0; i < cnt; i++)
	{
		res += a * (mask & 1);
		mask >>= 1;
		a *= base;
	}
	return res;
}


int main()
{
//	freopen("/Users/user/Downloads/B-large.in", "r", stdin);
//	freopen("key.out", "w", stdout);
//	cin >> t;
	t = 1;
	for(int q = 0; q < t; q++)
	{
		printf("Case #%d:\n", q + 1);
		for(ull mask = (1LL << (cnt - 2)); num > 0 && mask < (1LL << (cnt - 1)); mask++)
		{
			bool flag = true;
			vector <ull> v;
			for(int b = 2; b <= 10; b++)
			{
				ull x = convert(mask * 2 + 1, b);
				if(prime(x))
				{
					flag = false;
					break;
				}
				else
				{
					if(pollard(x) == 1)
						exit(1);
					v.push_back(pollard(x));
				}
			}
			if(flag)
			{
				num--;
				vector <int> u;
				ull m = 2 * mask + 1;
				for(int i = 0; i < cnt; i++)
				{
					u.push_back(m & 1);
					m >>= 1;
				}
				reverse(all(u));
				for(int i = 0; i < cnt; i++)
					printf("%d", u[i]);
				printf(" ");
				for(int i = 0; i < 9; i++)
					printf("%llu ", v[i]);
				printf("\n");
			}
		}
	}
	
	return 0;
}