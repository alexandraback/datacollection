#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

typedef long long int LL;

LL gcd (LL a, LL b)
{
	if (!b) return a;
	return gcd(b, a%b);
}

struct Frac
{	
	LL n, d;

	Frac () {}
	Frac (LL a, LL b) { 
		n = a, d = b; 
		LL g = gcd(a, b);
		n /= g;
		d /= g;
	}

	Frac operator+ (Frac b) const {
		return Frac(b.d*n + d*b.n, d*b.d);
	}

	Frac operator- (Frac b) const {
		return Frac(b.d*n - d*b.n, d*b.d);
	}
	
	Frac operator* (Frac b) const {
		return Frac(n*b.n, d*b.d);
	}

	bool operator<= (Frac b) const {
		return n*b.d <= d*b.n;
	}

	Frac operator/ (LL b) const {
		return Frac (n, d*b);
	}

	Frac operator* (LL b) const {
		return Frac(n*b, d);
	}

	bool isElf ()
	{
		return n == 1 and d == 1;
	}

	void print() {
		printf("%lld/%lld ", n, d);
	}
};	


int main (void)
{
	int T, caso = 1;
	cin >> T;
	while (T--)
	{
		LL p, q;
		int res;
		scanf("%lld/%lld", &p, &q);
		LL g = gcd(p, q);
		p /= g;
		q /= g;
		Frac in (p, q);

		printf("Case #%d: ", caso++);
		if (__builtin_popcount(q) > 1) printf("impossible\n");
		else {
			Frac f (1, 2);
			int res;
			for (int x = 1; x <= 40; ++x)
			{
				if (f <= in) { 
					res = x;
					break;
				}
				f = f/2;
			}
			printf("%d\n", res);
		} 
	}}