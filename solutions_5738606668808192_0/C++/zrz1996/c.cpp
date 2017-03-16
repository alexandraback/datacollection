#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <cassert>
#include <ctime>
using namespace std;
typedef long long LL;
#define For(i,a,b) for (int i = (a); i <= (b); i++)
#define Cor(i,a,b) for (int i = (a); i >= (b); i--)
#define rep(i,a) for (int i = 0; i < a; i++)
#define Fill(a,b) memset(a,b,sizeof(a))
#define LEN 16
int p[1000010], prime[100010], psize = 1000000;
LL a[1000100];
void sieve(){
	int i,j,tot,t1;
	for (i=1;i<=psize;i++) p[i]=i;
	for (i=2,tot=0;i<=psize;i++){
		if (p[i]==i) prime[++tot]=i;
		for (j=1;j<=tot && (t1=prime[j]*i)<=psize;j++){
			p[t1]=prime[j];
			if (i%prime[j]==0) break;
		}
	}
}
inline LL mul(LL a, LL b, LL p) 
{
	if (p <= 1000000000) 
		return a * b % p;
	else 
		if (p<=1000000000000LL) 
			return (((a * (b >> 20) % p) << 20) + (a * (b & ((1 << 20) - 1)))) % p;
		else 
		{
			LL d = (LL)floor(a * (long double)b / p + 0.5);
			LL ret = (a * b - d * p) % p;
			if (ret < 0) ret += p;
			return ret;
		}
}
LL fpow(LL a,LL n,LL p) 
{
	LL ans=1;
	for (; n; n >>= 1) 
	{
		if (n & 1) ans = mul(ans, a, p);
		a = mul(a, a, p);
	}
	return ans;
}
bool witness(LL a, LL n)  //二次探查
{
	int t = 0;
	LL u = n - 1;
	for (; ~u & 1; u >>= 1) t++;
	LL x = fpow(a, u, n), _x = 0;
	for (; t; t--) 
	{
		_x = mul(x, x, n);
		if (_x == 1 && x != 1 && x != n-1) return 1;
		x = _x;
	}
	return _x != 1;
}
bool miller(LL n) 
{
	if (n < 2) return 0;
	if (n < psize) return p[n] == n;
	if (~n & 1) return 0;
	for (int j = 0; j <= 7; j++) 
		if (witness(rand() % (n - 1) + 1, n)) 
			return 0;
	return 1;
}
LL gcd(LL a,LL b) 
{
	LL ret = 1;
	while (a != 0) 
	{
		if ((~a & 1) && (~b & 1)) 
			ret <<= 1,a >>= 1,b >>= 1;
		else 
			if (~a & 1) 
				a >>= 1; 
			else 
				if (~b & 1) 
					b >>= 1;
				else 
				{
					if (a < b) 
						swap(a, b);
					a -= b;
				}
	}
	return ret * b;
}
LL rho(LL n) 
{
	for (;;) 
	{
		LL X = rand() % n, Y, Z, T = 1, *lY = a, *lX = lY;
		int tmp = 20;
		LL C = rand() % 10 + 3;
		X = mul(X, X, n) + C;
		*(lY++) = X; lX++;
		Y = mul(X, X, n) + C;
		*(lY++) = Y;
		for(; X != Y;) 
		{
			LL t = X - Y + n;
			Z = mul(T, t, n);
			if(Z == 0) 
				return gcd(T, n);
			tmp--;
			if (tmp == 0) 
			{
				tmp = 20;
				Z = gcd(Z, n);
				if (Z != 1 && Z != n) 
					return Z;
			}
			T = Z;
			Y = *(lY++) = mul(Y, Y, n) + C;
			Y = *(lY++) = mul(Y, Y, n) + C;
			X = *(lX++);
		}
	}
}
bool t[LEN];
void init()
{
	srand(time(0));
	sieve();
	t[0] = t[LEN - 1] = 1;
}
inline LL change(int base)
{
	LL ret = 0;
	LL d = 1;
	for (int i = 0; i < LEN; i++)
	{
		ret += t[i] ? d : 0;
		d *= base;
	}
	return ret;
}
LL factor[100];
void solve()
{
	set<LL> s;
	while (1)
	{
		for (int i = 1; i < LEN - 1; i++)
			t[i] = rand() & 1;
		bool pd = 1;
		LL x;
		for (int i = 2; i <= 10; i++)
		{
			x = change(i);
			if (miller(x))
			{
				pd = 0;
				break;
			}
			LL d = x;
			while (d == x)
				d = rho(x);
			factor[i] = d;
			assert(x % d == 0);
			assert(d != 1 && d != x);
		}
		if (pd)
		{
			if (s.find(x) == s.end())
			{
				s.insert(x);
				for (int i = LEN - 1; i >= 0; i--)
					printf("%d", t[i]);
				for (int i = 2; i <= 10; i++)
					printf(" %lld", factor[i]);
				puts("");
				if (s.size() == 50)
					break;
			}
		}
	}
}
int main()
{
	freopen("c_small.out", "w", stdout);
	printf("Case #1:\n");
	init();
	solve();
}
