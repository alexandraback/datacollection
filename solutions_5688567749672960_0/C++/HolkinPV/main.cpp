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

const int N = 1000 * 1000 + 3;

int d[N];
int k;

inline void precalc()
{
	memset(d, 63, sizeof(d));

	queue<int> q;
	q.push(0);
	d[0] = 0;

	while(!q.empty())
	{
		int n = q.front();
		q.pop();

		int dv = d[n];
		
		{
			int to = n + 1;

			if (to < N && to > n && d[to] > dv + 1)
			{
				d[to] = dv + 1;
				q.push(to);
			}
		}

		{
			int to = 0;

			while(n > 0)
			{
				int dig = n % 10;
				n /= 10;
				to = (to * 10) + dig;
			}

			if (to < N && to > n && d[to] > dv + 1)
			{
				d[to] = dv + 1;
				q.push(to);
			}
		}
	}
}

inline bool read()
{
	if (scanf("%d", &k) != 1)
		return false;

    return true;
}

inline void Solve(int test)
{
	printf("Case #%d: ", test + 1);

	int ans = d[k];
	cout << ans << endl;
}

int main()
{
#ifdef HP
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

	int testCnt;
	assert(scanf("%d", &testCnt) == 1);

	precalc();

	forn(test, testCnt)
	{
	    assert(read());
    	Solve(test);
	}

    return 0;
}

