#pragma comment(linker, "/stack:64000000")
#include <algorithm>
#include <iostream>
#include <cassert>
#include <climits>
#include <utility>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <memory.h>
#include <vector>
#include <bitset>
#include <string>
#include <deque>
#include <queue>
#include <ctime>
#include <set>
#include <map>
#include <deque>
#include <stack>
#include <cmath>
using namespace std;

typedef long long ll;
typedef long double ld;
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define for1(i, n) for (int i = 1; i <= int(n); i++)
#define fore(i, l, r) for (int i = int(l); i < int(r); i++)
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define pb push_back
#define pii pair <int, int>
#define vi vector <int>
#define mp make_pair

template <typename X> inline X abs (const X &a) {return a < 0? -a: a;}
template <typename X> inline X sqr (const X &a) {return a * a;}

const int INF = INT_MAX / 2;
const ll INF64 = LLONG_MAX / 2LL;
const ld EPS = 1E-9, PI = 3.1415926535897932384626433832795;

const int N = 10 + 3;

int n;
pii a[N];
vector <pii> v[2];

int z[N][N][3 * N][(1 << 10) + 3];

int lazy (int i, int j, int have, int used)
{
	int &ans = z[i][j][have][used];
	if (ans != -1)
		return ans;

	if (j == n)
		return ans = 0;

	ans = INF;

	if (i < n)
	{
		ans = min (ans, lazy (i + 1, j, have, used));
		if (!(used & (1 << v[0][i].second)) && v[0][i].first == have)
			ans = min (ans, 1 + lazy (i + 1, j, have + 1, used | (1 << v[0][i].second)));
	}

	if (v[1][j].first <= have)
	{
		int add = (used & (1 << v[1][j].second))? 1: 2;
		
		ans = min (ans, 1 + lazy (i, j + 1, have + add, used | (1 << v[1][j].second)));
	}

	return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif

	int tests;
	
	cin >> tests;
	forn (test, tests)
	{
		cin >> n;

		forn (i, 2)
			v[i].clear();

		forn (i, n)
		{
			int x, y;
			scanf ("%d%d", &x, &y);
			
			v[0].pb (mp (x, i));
			v[1].pb (mp (y, i));
		}

		sort (all (v[0]));
		sort (all (v[1]));

		memset (z, -1, sizeof z);
		int ans = lazy (0, 0, 0, 0);

		if (ans < INF / 2)
			printf ("Case #%d: %d\n", test + 1, ans);
		else
			printf ("Case #%d: Too Bad\n", test + 1);
	}

	return 0;
}