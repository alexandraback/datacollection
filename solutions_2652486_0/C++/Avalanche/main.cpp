#include <windows.h>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <cstring>
#include <ctime>
#include <cmath>
#include <cassert>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <utility>
#include <numeric>
#include <functional>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define forl(i, n) for (int i = 1; i <= int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i, l, r) for (int i = int(l); i <= int(r); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(x, y) make_pair((x), (y))
#define ft first
#define sc second
#define x first
#define y second

using namespace std;

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;

int r, n, m, k;

inline bool read()
{
	return scanf("%d%d%d%d", &r, &n, &m, &k) == 4;
}

const int M = 1000 * 1000 + 3;

set<vector<int> > ans[M];

int a[3];

inline void prepare()
{
	for (a[0] = 2; a[0] <= m; a[0]++)
	for (a[1] = 2; a[1] <= a[0]; a[1]++)
	for (a[2] = 2; a[2] <= a[1]; a[2]++)
	{
		forn(mask, 1 << 3)
		{
			int cur = 1;
			
			forn(i, 3)
				if (mask & (1 << i))
					cur *= a[i];
					
			ans[cur].insert(vector<int> (a, a + 3));
		}
	}
}

inline void cross(set<vector<int> >& cur, const set <vector<int> >& add)
{	
	set<vector<int> > next;

	for(set<vector<int> >::iterator it = cur.begin(); it != cur.end(); it++)
		if (add.count(*it))
			next.insert(*it);

	cur = next;
}

inline void solve(int test)
{
	prepare();
	
	printf("Case #%d:\n", test + 1);
	
	forn(i, r)
	{
		set<vector<int> > cur;
		
		forn(j, k)
		{
			int x;
			assert(scanf("%d", &x) == 1);
			
			if (j == 0) cur = ans[x];
			else cross(cur, ans[x]);
		}
		
		vector<vector<int> > res(all(cur));
		cerr << sz(res) << endl;
		
		if (res.empty()) forn(i, n) putchar('2');
		else
		{
			int pos = rand() % sz(res);
			forn(i, n) printf("%d", res[pos][i]);			
		}
		
		puts("");
	}
}

int main()
{
#ifdef SU2_PROJ
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
        
	cout << setprecision(10) << fixed;
	cerr << setprecision(5) << fixed;
	
	srand(GetTickCount());
	
	int testCount;
	cin >> testCount;
	
	forn(test, testCount)
	{        
		assert(read());
		solve(test);
	}
        
	return 0;
}