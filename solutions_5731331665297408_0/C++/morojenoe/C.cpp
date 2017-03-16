#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <vector>
#include <memory.h>
#include <map>
#include <set>
#include <bitset>
#include <algorithm>
#include <cmath>
#include <stack>
#include <string>
#include <cstring>
#include <string.h>
#include <sstream>
#include <cmath>
#include <math.h>
#include <queue>
#include <deque>
#include <cassert>
#include <time.h>

#define forn(i,n) for (int i = 0; i < (int)n; i++)
#define fornd(i, n) for (int i = (int)n - 1; i >= 0; i--)
#define forab(i,a,b) for (int i = (int)a; i <= (int)b; i++)
#define forabd(i, b, a) for (int i = (int)(b); i >= (int)(a); i--)
#define forit(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define zero(a) memset (a, 0, sizeof (a))
#define last(v) (int)v.size() - 1
#define _(a, val) memset (a, val, sizeof (a))
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()

#ifdef _DEBUG
#define dbg(...) {fprintf(stderr, __VA_ARGS__); fflush(stderr);}
#define dbgx(x) {cerr << #x << " = " << x << endl;}
#define dbgv(v) {cerr << #v << " = {"; for (typeof(v.begin()) it = v.begin(); it != v.end(); it ++) cerr << *it << ", "; cerr << "}"; cerr << endl;}
#else
#define dbg(...) { }
#define dbgx(x) { }
#define dbgv(v) { }
#endif

typedef long long lint;
typedef unsigned long long ull;
typedef long double ld;

const lint LINF = 1000000000000000000LL;
const int INF = 1000000000;
const long double eps = 1e-9;
const long double PI = 3.1415926535897932384626433832795l;

using namespace std;

void prepare (string s)
{
#ifdef _DEBUG
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#else
	if (s.length() != 0)
	{
		freopen ((s + ".in").c_str(), "r", stdin);
		freopen ((s + ".out").c_str(), "w", stdout);
	}
#endif
}

const int NMAX = 55;
int n, m;
int a[NMAX][NMAX];
int zip[NMAX];
int was[NMAX];
int used[NMAX];

void read()
{
	_(a, 0);
	scanf("%d %d", &n, &m);
	forn(i, n) scanf("%d", &zip[i]);
	forn(i, m)
	{
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		t1 --; t2 --;
		a[t1][t2] = a[t2][t1] = 1;
	}
}

string result;

void addToResult(int n)
{
	string tmp;
	stringstream ss;
	ss << n;
	ss >> tmp;
	result += tmp;
}

void check_dfs(int v)
{
	used[v] = true;
	forn(i, n)
		if (used[i] == 0 && a[v][i] > 0 && was[i] < 2)
			check_dfs( i );
}

bool check()
{
	_(used, 0);
	forn(i, n)
		if (was[i] == 1)
			check_dfs( i );
	
	forn(i, n)
		if (used[i] == 0 && was[i] < 2)
			return false;
	return true;
}

struct state
{
	int cost, v, u;
	state(){}
	state(int c, int a, int b)
	{
		cost = c;
		v = a;
		u = b;
	}
};

bool operator<(const state &s1, const state &s2)
{
	if (s1.cost == s2.cost)
		return s1.v < s2.v;
	return s1.cost < s2.cost;
}

void del_shlak(set<state> &s)
{
	set<state> ::iterator it = s.begin();
	for(; it != s.end(); ++it)
	{
		if (was[it->u] != 0)
		{
			s.erase( it );
			del_shlak(s);
			return;
		}
	}
}

void dfs(int v, set<state> &q)
{
	addToResult( zip[v] );
	was[v] = 1;
	forn(i, n)
	{
		if (a[v][i] > 0)
		{
			if (was[i] == 0)
			{
				q.insert( state(zip[i], v, i ));
			}
		}
	}
	
	while( 1 )
	{
		del_shlak( q );
		was[v] = 2;
		if (!check())
		{
			was[v] = 1;
			set<state> :: iterator it = q.begin();
			for(; it != q.end(); ++it)
			{
				if (it->v == v )
				{
					if (was[it->u] == 0)
					{
						dfs( it->u, q );
						break;
					}
				}
			}
		}
		else
		{
			was[v] = 1;
			int mincost = q.begin()->cost;
			set<state> :: iterator it = q.begin();
			bool ok = false;
			for(; it != q.end(); ++it)
			{
				if (it->v == v && it->cost == mincost)
				{
					if (was[it->u] == 0)
					{
						dfs( it->u, q );
						ok = true;
						break;
					}
				}
			}
			
			if (!ok)
				break;
		}
		
	}
	
	was[v] = 2;
}

string get(int st_v)
{
	_(was, 0);
	set<state> q;
	result = "";
	dfs( st_v, q );
	return result;
}

void solve()
{
	string ans;
	forn(i, n)
	{
		string res = get( i );
		if (sz(ans) == 0 || res < ans)
			ans = res;
	}
	assert( sz(ans) % 5 == 0 );
	assert( sz(ans) / 5 == n );
	printf("%s\n", ans.c_str());
}

int main ()
{
	prepare ("");
	
	int t;
	scanf("%d", &t);
	forn(i, t)
	{
		printf("Case #%d: ", i + 1);
		read();
		solve();
	}

	return 0;
}
