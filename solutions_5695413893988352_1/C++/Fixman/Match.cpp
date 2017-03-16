#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

#define forsn(i, s, n) for (int i = s; i < n; i++)
#define forn(i, n) forsn(i, 0, n)
#define fore(i, n) forn(i, n.size())

typedef pair <string, string> pss;
typedef pair <long, long> pll;
#define y first
#define x second

template <typename P>
P flip(P x)
{
	return P(x.second, x.first);
}

bool flipped = false; // Eww
pss best(pss a, pss b)
{
	if (b == pss("", ""))
		return a;

	if (a == pss("", ""))
		return b;

	pll f = pll(stol(a.first), stol(a.second));
	pll g = pll(stol(b.first), stol(b.second));

	if (abs(f.y - f.x) < abs(g.y - g.x))
		return a;
	
	if (abs(f.y - f.x) > abs(g.y - g.x))
		return b;
	
	if (flipped) // Ewwwwww
	{
		f = flip(f);
		g = flip(g);
	}

	if (f.y < g.y)
		return a;
	
	if (f.y > g.y)
		return b;
	
	if (f.x < g.x)
		return a;
	
	return b;
}

bool equal(char &a, char &b)
{
	if (a == '?' && b == '?')
		a = b = '0';
	else if (a == '?' && b != '?')
		a = b;
	else if (a != '?' && b == '?')
		b = a;
	else if (a != b)
		return false;
	
	return true;
}

pss minq(string a, string b, int h)
{
	forn(i, h)
	{
		if (!equal(a[i], b[i]))
			return pss("", "");
	}

	if (h == a.size())
		return pss(a, b);

	if (a[h] == '?' && b[h] == '?')
	{
		a[h] = '0';
		b[h] = '1';
	}
	else if (a[h] == '?')
	{
		if (b[h] == '0')
			return pss("", "");

		a[h] = b[h] - 1;
	}
	else if (b[h] == '?')
	{
		if (a[h] == '9')
			return pss("", "");

		b[h] = a[h] + 1;
	}
	else if (a >= b)
		return pss("", "");

	forsn(i, h + 1, a.size())
	{
		if (a[i] == '?')
			a[i] = '9';

		if (b[i] == '?')
			b[i] = '0';
	}

	return pss(a, b);
}

pss go(const string &a, const string &b)
{
	pss r = pss("", "");
	fore(i, a)
		r = best(r, minq(a, b, i));

	return r;
}

pss solve(const string &a, const string &b)
{
	flipped = false;
	pss n = go(a, b);
	
	flipped = true;
	pss m = flip(go(b, a));

	flipped = false;
	return best(best(n, m), minq(a, b, a.size()));
}

int main()
{
	int t;
	cin >> t;

	forsn(z, 1, t + 1)
	{
		string a, b;
		cin >> a >> b;

		pss r = solve(a, b);
		printf("Case #%d: %s %s\n", z, r.first.c_str(), r.second.c_str());
	}

	return 0;
}
