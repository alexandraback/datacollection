#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define forsn(i, s, n) for (int i = s; i < n; i++)
#define forn(i, n) forsn(i, 0, n)
#define fore(i, n) forn(i, n.size())

typedef pair <int, int> pii;
#define y first
#define x second

#define popcount __builtin_popcount

struct IncreaseMap
{
	unordered_map <string, int> h;
	int num(const string &s)
	{
		if (h.find(s) == h.end())
		{
			int e = h.size();
			h[s] = e;
		}

		return h[s];
	}
};

bool copied(const vector <pii> &good, const vector <pii> &bad)
{
	unordered_set <int> f, s;
	for (auto &k : good)
	{
		f.insert(k.y);
		s.insert(k.x);
	}

	for (auto &k : bad)
	{
		if (f.find(k.y) == f.end() || s.find(k.x) == s.end())
			return false;
	}

	return true;
}

int solve(const vector <pii> &w)
{
	int n = w.size();

	int r = 0;
	for (unsigned long b = 0; b < (1 << n); b++)
	{
		if (popcount(b) <= r)
			continue;

		vector <pii> good, bad;

		for (unsigned long g = 1, i = 0; g < (1 << n); g <<= 1, i++)
			(b & g ? bad : good).push_back(w[i]);

		if (copied(good, bad))
			r = popcount(b);
	}

	return r;
}

int main()
{
	int t;
	cin >> t;

	forsn(z, 1, t + 1)
	{
		int n;
		cin >> n;

		IncreaseMap H;
		vector <pii> W;
		forn(i, n)
		{
			string a, b;
			cin >> a >> b;

			W.push_back(pii(H.num(a), H.num(b)));
		}

		printf("Case #%d: %d\n", z, solve(W));
	}

	return 0;
}
