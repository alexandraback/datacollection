#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;

ll GCD(ll a, ll b)
{
	if (a < b)
		swap(a, b);
	while (b != 0)
	{
		ll t = b;
		b = a % b;
		a = t;
	}
	return a;
}

struct Frac
{
	ll num, denum;
	Frac(ll n, ll d)
	{
		num = n;
		denum = d;
		norm();
	}
	Frac(ll a)
	{
		num = a;
		denum = 1;
	}
	void norm()
	{
		if (num != 0)
		{
			ll gcd = GCD(num, denum);
			num /= gcd;
			denum /= gcd;
			if (denum < 0 && num > 0)
			{
				num *= -1;
				denum *= -1;
			}
		}
	}
	bool operator==(const Frac& fr) const
	{
		return num * fr.denum - denum * fr.num == 0;
	}
	bool operator<(const Frac& fr) const
	{
		return num * fr.denum - denum * fr.num < 0;
	}
	bool operator>(const Frac& fr) const
	{
		return num * fr.denum - denum * fr.num > 0;
	}
	bool operator>=(const Frac& fr) const
	{
		return num * fr.denum - denum * fr.num >= 0;
	}
	Frac operator-(const Frac& fr)
	{
		Frac res(num * fr.denum - denum * fr.num, denum * fr.denum);
		res.norm();
		return res;
	}
};

bool check(Frac f, ll l)
{
	Frac z = Frac(0, 1);
	ll p2 = 1;
	for ( l = 1; l <= 40; ++l)
	{
		p2 *= 2;
		Frac t(1, p2); 
		Frac d = f - t;
		if ( d >= z)
			f = d;
		if (f == z)
			return true;
	}
	return false;
}

void solve()
{
	ll p, q, l, p2 = 1;
	char c;

	cin >> p >> c >> q;
	Frac pq = Frac(p, q);
	Frac z = Frac(0, 1);
	for (l = 1; l <= 40; ++l)
	{
		p2 *= 2;
		Frac t = pq - Frac(1, p2); 
		if (t == z)
			break;
		if (t >= z /*&& Frac(1) - Frac(1, p2)*/)
		{
			if (check(t, l))
				break;
		}
	}
	if (l == 41)
		cout << "impossible" << endl; 
	else
		cout << l << endl;
}

int main()
{
	int t;
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		cout << "Case #" << i + 1 << ": ";
		solve();
	}	
	return 0;
}