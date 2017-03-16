#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <stack>
#include <cstdlib>
#include <algorithm>
#include <list>
#include <cassert>
#include <ctime>
#include <sstream>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
using namespace std;

#define sc(x) scanf("%d", &x)
#define sc2(x, y) scanf("%d%d", &x, &y)
#define pr(x) printf("%d ", x)
#define nl() printf("\n")
#define mp(x, y) make_pair(x, y)
#define forn(i, a, b) for(int i=a; i<b; ++i)
#define ford(i, a, b) for(int i=b-1; i>=a; --i)
#define pb(x) push_back(x)
#define sz(x) (int)x.size()
#define X first
#define Y second

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld EPS = 1e-9;

int n, j;
vector<bool> digits;

ll isPrime(ll x)
{
	if (x == 1) return false;
	for (ll i = 2; i*i <= x; ++i)
		if (x%i == 0) return i;
	return -1;
}

ll translateDigits(int base)
{
	ll k = 1;
	ll res = 0;
	for (int i = digits.size()-1; i >= 0; --i, k *= base)
		if (digits[i]) res += k;
	return res;
}

void rec(int pos)
{
	if (pos == 0 || pos == digits.size() - 1)
	{
		digits[pos] = true;
		rec(pos + 1);
	}
	else if (pos == digits.size())
	{
		bool isAnyPrime = false;
		vector<ll> dels(11);
		for (int base = 2; base <= 10; ++base)
			if ((dels[base] = isPrime(translateDigits(base))) == -1)
				isAnyPrime = true;
		if (!isAnyPrime)
		{
			for (int i = 0; i < digits.size(); ++i)
				cout << (digits[i] ? 1 : 0);
			for (int base = 2; base <= 10; ++base)
				cout << ' ' << dels[base];
			cout << '\n';
			j--;
			if (j == 0) exit(0);
		}
	}
	else
	{
		digits[pos] = false;
		rec(pos + 1);
		digits[pos] = true;
		rec(pos + 1);
	}
}

void solve()
{
	int t;
	cin >> t >> n >> j;
	digits.resize(n);
	rec(0);
}

int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
#endif
	solve();

	return 0;
}