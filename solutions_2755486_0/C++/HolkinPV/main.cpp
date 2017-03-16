#pragma comment(linker, "/stack:64000000")
#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES

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
#define X first
#define Y second
#define ft first
#define sc second

using namespace std;

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;
typedef pair<ld, ld> ptd;

const int INF = INT_MAX / 2;
const ld EPS = 1e-9;
const ld PI = 3.1415926535897932384626433832795;

const int N = 10 + 3;
const int MAXV = 676060 + 3;

int n;
int d[N], cnt[N], w[N], e[N], s[N], dd[N], dp[N], ds[N];

inline bool read()
{
	if (scanf("%d", &n) != 1)
		return false;
		
	forn(i, n)
	{
		assert(scanf("%d%d%d%d%d%d%d%d", &d[i], &cnt[i], &w[i], &e[i], &s[i], &dd[i], &dp[i], &ds[i]) == 8);
		w[i] *= 2;
		e[i] *= 2;
		dp[i] *= 2;
	}
		
	return true;
}

map<int, int> wall;
map<int, int> attack;

inline void update(int i)
{
	d[i] += dd[i];
	w[i] += dp[i];
	e[i] += dp[i];
	s[i] += ds[i];
	cnt[i]--;
}

inline void solve(int test)
{
	printf("Case #%d: ", test + 1);
	
	wall.clear();
	attack.clear();
	
	int ans = 0;
	
	forn(day, MAXV)
	{
		attack.clear();
		
		forn(i, n)
			if (d[i] == day && cnt[i] > 0)
			{
				map<int, int> cur;
				
				bool success = false;
				
				fore(x, w[i], e[i])
				{
					cur[x] = s[i];	
					
					if (cur[x] > wall[x])
						success = true;
				}
				
				if (success)
					ans++;
				
				//cerr << day << " " << i << " " << w[i] << " " << e[i] << " " << s[i] << " " << success << endl;
					
				update(i);
				
				for(map<int, int>:: iterator it = cur.begin(); it != cur.end(); it++)
					attack[ it->ft ] = max(attack[ it->ft ], it->sc);
			}
		
		for(map<int, int>:: iterator it = attack.begin(); it != attack.end(); it++)
			wall[ it->ft ] = max(wall[ it->ft ], it->sc);
	}
	
	printf("%d\n", ans);
}

int main()
{
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);

    int testCnt;

    assert(scanf("%d\n", &testCnt) == 1);

    forn(test, testCnt)
    {
    	assert(read());
		solve(test);
	}

    return 0;
}
