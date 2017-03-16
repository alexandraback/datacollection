#include <iostream>
#include <string>
#include <cmath>
#include <set>
using namespace std;

const int mxnum = 10000 + 10;
int num[mxnum];

int kgcd(int a, int b)
{
	if (a == 0) return b;
	if (b == 0) return a;
	if (!(a & 1) && !(b & 1)) return kgcd(a>>1, b>>1) << 1;
	else if (!(b & 1)) return kgcd(a, b>>1);
	else if (!(a & 1)) return kgcd(a>>1, b);
	else return kgcd(abs(a - b), min(a, b));
}


int CC(int a, int b)
{
	//a * a-1 * a-2 .. a-b+1 / b * b-1 *...1
	int u = 1, d = 1;
	for (int i = a, j = 1; j <= b; i--, j++)
	{
		u *= i, d *= j;
		int gcd = kgcd(u, d);	
		u /= gcd;	d /= gcd;
	}
	return u / d;
}

double C(int a, int b, int x)
{
	double ret = 0;
	int mxi = x+1;	if(a < x)	mxi = a;
	for (int i = b; i <= a; i++)
		ret += CC(a, i) * pow(0.5, i) * pow(0.5, a-i);
	return ret;
}

int main ()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	for (int i = 0; i < mxnum; i++)	num[i] = 2 * i * i - i;

	int tc;		scanf("%d", &tc);
	for (int T = 1; T <= tc; T++)
	{
		double ans;
		int n, x, y;	scanf("%d%d%d", &n, &x, &y);
		if (x < 0)	x = -x;
		if (x == 0 && y == 0)
		{
			ans = 1;	
		}
		else if(x == 0)
		{
			int n0 = num[(x+y)/2 + 1];
			if (n >= n0)	ans = 1;
			else ans = 0;
		}
		else
		{
			int d = (x + y) / 2, n0 = num[d], dn = y + 1;
			if (n < n0 + dn)	ans = 0;
			else if(n >= n0 + 2 * d + 1 - 1 + dn)	ans = 1;
			else
			{
				int _n = n - n0, _dn = dn;
				ans = C(_n, _dn, 2 * d);
			}
		}
		printf("Case #%d: %.6lf\n", T, ans);
	}
}