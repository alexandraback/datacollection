#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <iterator>
#include <list>
#include <set>
#include <queue>
#include <numeric>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

typedef long long lli;
typedef long li;

template <class T>
T Maximize (T &v, T nv) { if (nv > v) v = nv; return v; }

template <class T>
T Minimize (T &v, T nv) { if (nv < v) v = nv; return v; }

const lli INFLL = numeric_limits<lli>::max();
const li INF = numeric_limits<li>::max();

bool is_power_of_2 (lli x)
{
	return x > 0 && !(x & (x - 1));
}

void solve ()
{
	ios::sync_with_stdio(0);

	li tests;
	cin >> tests;

	for (li test = 1; test <= tests; ++ test)
	{
		lli a, b;
		char c;
		cin >> a >> c >> b;
		lli g = __gcd(a, b);
		a /= g;
		b /= g;

		cout << "Case #" << test << ": ";
		li gen = 0;
		for (; a < b; a *= 2, gen ++);
		if (!is_power_of_2(b) || gen > 40)
		{
			cout << "impossible";
		}
		else
		{
			cout << gen;
		}
		cout << "\n";
	}
}

void init ()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}

int main()
{
	init();
	solve();
	return 0;
}
