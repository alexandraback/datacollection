#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

#define forsn(i, s, n) for (int i = s; i < n; i++)
#define forn(i, n) forsn(i, 0, n)

typedef pair <int, int> pii;
#define y first
#define x second

bool match(const string &s, int n)
{
	for (int i = s.size() - 1; i >= 0; i--)
	{
		if (s[i] != '?' && s[i] - '0' != n % 10)
			return false;

		n /= 10;
	}

	return n == 0;
}

pii best(pii a, pii b)
{
	if (abs(a.y - a.x) < abs(b.y - b.x))
		return a;
	
	if (abs(a.y - a.x) > abs(b.y - b.x))
		return b;
	
	if (a.y < b.y)
		return a;
	
	if (a.y > b.y)
		return b;
	
	if (a.x < b.x)
		return a;
	
	return b;
}

pii solve(const string &a, const string &b)
{
	pii r = pii(2000, 0);
	forn(i, 1000)
	{
		if (match(a, i))
		{
			forn(j, 1000)
			{
				if (match(b, j))
					r = best(r, pii(i, j));
			}
		}
	}

	return r;
}

string pad(int s, int n)
{
	string g = to_string(s);
	return string(max(0, n - int(g.size())), '0') + g;
}

int main()
{
	int t;
	cin >> t;

	forsn(z, 1, t + 1)
	{
		string a, b;
		cin >> a >> b;

		pii r = solve(a, b);
		printf("Case #%d: ", z);
		cout << pad(r.first, a.size()) << " " << pad(r.second, b.size()) << endl;
	}

	return 0;
}
