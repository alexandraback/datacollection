#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <list>
#include <stack>
#include <bitset>
#include <algorithm>
#include <iomanip>

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); i++)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i,l,r) for (int i = int(l); i <= int(r); i++)
#define all(a) a.begin(), a.end()
#define sz(a) int(a.size())
#define mp make_pair
#define pb push_back
#define ft first
#define sc second
#define x first
#define y second

template<typename X> inline X abs(const X& a) { return a < 0 ? -a : a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9;
const ld PI = acosl(ld(-1));

const int N = 1000 + 13;
int n;
char buf[N];

map<string, int> name1, name2;

inline int getName (const string& s, map<string, int>& q)
{
	if (!q.count(s))
	{
		int sz = sz(q);
		q[s] = sz;
	}
	
	return q[s];
}

pt a[N];

inline bool read()
{
	if (scanf ("%d", &n) != 1)
		return false;
		
	name1.clear();
	name2.clear();
		
	forn (i, n)
	{
		int id1, id2;
		assert(scanf ("%s", buf) == 1);
		id1 = getName(string(buf), name1);
		
		assert(scanf ("%s", buf) == 1);
		id2 = getName(string(buf), name2);
		
		a[i] = mp(id1, id2);
	}
	
	return true;
}

int used1[N], used2[N];

inline int calc (pt a[N])
{
	forn (i, n)
		used1[i] = used2[i] = 0;
		
	int ans = 0;
	forn (i, n)
	{
		if (used1[ a[i].ft ] && used2[ a[i].sc ])
			ans++;
			
		used1[ a[i].ft ] = 1;
		used2[ a[i].sc ] = 1;
	}
	
	return ans;
}

inline int naive()
{
	sort(a, a + n);
	
	int ans = 0;
	do
	{
		ans = max(ans, calc(a));
	}
	while (next_permutation(a, a + n));
	
	return ans;
}

inline bool cmp (const pt& a, const pt& b)
{
	if (a.sc != b.sc)
		return a.sc < b.sc;
		
	return a.ft < b.ft;
}

vector<int> g[N];
pt b[N];
int szb;
int used[N];

void dfs (int v)
{
	used[v] = 1;
	
	forn (i, sz(g[v]))
	{
		int to = g[v][i];
		
		if (used[to])
			continue;
		
		dfs(to);
	}
	
	b[szb++] = a[v];
}

inline void solve(int test)
{
	printf ("Case #%d: ", test + 1);
	
	//n = 9;
	//forn (i, n)
	//	a[i] = mp(rand() % 3, rand() % 3);
	
/*	forn (i, n)
		g[i].clear();
		
	forn (i, n)
		forn (j, n)
			if (i != j && (a[i].ft == a[j].ft || a[i].sc == a[j].sc))
				g[i].pb(j);
				
	szb = 0;
	forn (i, n)
		used[i] = 0;
		
	forn (i, n)
		if (!used[i])
			dfs(i);
			
	reverse(b, b + szb);*/
			
	int ans = 0;
	forn (mask, (1 << n))
	{
		szb = 0;
		forn (i, n)
			if ((mask >> i) & 1)
				b[szb++] = a[i];
		forn (i, n)
			if (!((mask >> i) & 1))
				b[szb++] = a[i];
				
		ans = max(ans, calc(b));
	}
	
	//assert(ans == naive());
	
	printf ("%d\n", ans);
	
	//cerr << "OK" << endl;
}

int main()
{
#ifdef SU2_PROJ
	assert(freopen("input.txt", "r", stdin));
	assert(freopen("output.txt", "w", stdout));
#endif

	cout << setprecision(25) << fixed;
	cerr << setprecision(10) << fixed;

	srand(int(time(NULL)));
	
	int testCnt;
	assert(scanf ("%d", &testCnt) == 1);

	forn (test, testCnt)
	{
		assert(read());
		solve(test);
	}

#ifdef SU2_PROJ
	cerr << "TIME: " << clock() << endl;
#endif

	return 0;
}
