#pragma comment(linker, "/stack:128000000")

#include <algorithm>
#include <iostream>
#include <cassert>
#include <iomanip>
#include <climits>
#include <utility>
#include <cstring>
#include <complex>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <bitset>
#include <string>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <set>
#include <map>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define forl(i, n) for (int i = 1; i <= int(n); i++)
#define fore(i, l, r) for (int i = int(l); i <= int(r); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(a, b) make_pair((a), (b))
#define x first
#define y second
#define ft first
#define sc second

using namespace std;

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

const int INF = INT_MAX / 2;
const ld EPS = 1e-9;
const ld PI = 3.1415926535897932384626433832795;

const int D = 100 + 3;

int c, d, v;
int a[D];

inline bool read()
{
	if (!(cin >> c >> d >> v))
		return false;

	forn(i, d)
		assert(cin >> a[i]);

    return true;
}

inline void solve(int test)
{
	printf("Case #%d: ", test + 1);

	sort(a, a + d);

	int ans = 0;
	assert(d > 0);
	if (a[0] != 1)
		ans++;

	int cur = c;
	int it = 0;
	if (a[0] == 1)
		it++;

	while(true)
	{
		while(it < d && a[it] <= cur + 1)
		{
			cur += a[it];
			cur = min(cur, v);
			it++;
		}

		if (cur >= v)
			break;

		cur += (cur + 1);
		cur = min(cur, v);
		ans++;
	}

	cout << ans << endl;
}

int main()
{
#ifdef HP
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

	int testCnt;
	assert(cin >> testCnt);

	forn(test, testCnt)
	{
    	assert(read());
    	solve(test);
	}

    return 0;
}

