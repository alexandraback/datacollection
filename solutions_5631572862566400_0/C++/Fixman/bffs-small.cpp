#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cassert>
#include <set>
#include <cstring>

using namespace std;

#define forsn(i, s, n) for (int i = s; i < n; i++)
#define forn(i, n) forsn(i, 0, n)
#define fore(i, n) forn(i, n.size())
#define all(n) n.begin(), n.end()

vector <int> F;

bool go(const vector <int> &v)
{
	fore(i, v)
	{
		if (v[(i + 1) % v.size()] != F[v[i]] && v[(i - 1 + v.size()) % v.size()] != F[v[i]])
			return false;
	}

	return true;
}

int test(unsigned int b)
{
	vector <int> v;
	for (int i = 0; b > 0; i++, b >>= 1)
	{
		if (b & 1)
			v.push_back(i);
	}

	sort(all(v));

	do
	{
		if (go(v))
			return v.size();
	}
	while (next_permutation(all(v)));

	return 0;
}

int main()
{
	int t; cin >> t;

	forsn(z, 1, t + 1)
	{
		int n; cin >> n;
		F = vector <int> (n);

		fore(i, F)
		{
			cin >> F[i];
			F[i] -= 1;
		}

		int r = 0;
		for (unsigned int b = 1; b < (1 << n); b++)
			r = max(r, test(b));

		printf("Case #%d: %d\n", z, r);
	}

	return 0;
}
