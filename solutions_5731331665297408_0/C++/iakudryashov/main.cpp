#undef NDEBUG
#ifdef SU2_PROJ
#define _GLIBCXX_DEBUG
#endif

#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

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
inline ostream& operator<< (ostream& out, const pt& p) { return out << '(' << p.x << ", " << p.y << ')'; }

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;

const int N = 10 + 3;

int n, m;
char buf[N];
string s[N];
int g[N][N];

inline bool read()
{
	if (scanf("%d%d", &n, &m) != 2) return false;
	
	forn(i, n)
	{
		assert(scanf("%s", buf) == 1);
		s[i] = string(buf);
	}
	
	memset(g, 0, sizeof(g));
	
	forn(i, m)
	{
		int a, b;
		assert(scanf("%d%d", &a, &b) == 2);
		--a, --b;
		g[a][b] = g[b][a] = true;
	}
	
	return true;
}

int pr[N];

inline bool check (const vector <int>& perm)
{
	int v = perm[0];
	pr[v] = -1;
	
	forl(i, sz(perm) - 1)
	{
		int to = perm[i];
		
		while (v != -1 && !g[v][to])
			v = pr[v];
			
		if (v == -1) return false;
		
		pr[to] = v;
		v = to;
	}
	
	return true;
}

inline void solve(int test)
{
	printf("Case #%d: ", test);
	
	vector <int> perm;
	forn(i, n) perm.pb(i);
	
	string ans = string(5 * n, '9');
	
	do
	{
		string cur = "";
		
		forn(i, sz(perm)) cur += s[perm[i]];
		
		if (cur >= ans) continue;
		
		if (!check(perm)) continue;
		
		ans = cur;
	
	} while (next_permutation(all(perm)));
	
	puts(ans.c_str());
}

int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	cout << setprecision(10) << fixed;
	cerr << setprecision(5) << fixed;
	
	int testCount;
	cin >> testCount;
	
	forl(test, testCount)
	{
		assert(read());
		solve(test);
#ifdef SU2_PROJ
		cerr << test << ' ' << clock() << endl;
#endif
	}
	
	return 0;
}
