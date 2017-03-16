#pragma comment(linker, "/stack:128000000")

#include <algorithm>
#include <iostream>
#include <cassert>
#include <iomanip>
#include <climits>
#include <utility>
#include <iomanip>
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

const int M = 100 + 13;
const int A = 26;

struct node {
	map<int, int> next;
	map<int, int> go;
	int c;
	int end;
	int par;
	int link;
};

node t[M];
int szt;

inline int get_next(int v, int c) {
	return t[v].next.count(c) ? t[v].next[c] : -1;
}

inline int get_go(int v, int c) {
	return t[v].go.count(c) ? t[v].go[c] : -1;
}

inline void clear(int v) {
	t[v].next.clear();
	t[v].go.clear();
	t[v].link = -1;
	t[v].end = -1;
}

inline void init() {
	szt = 1;
	clear(0);
	t[0].par = -1;
}

inline void add(const string& s, const int& id) {
	int v = 0;
	forn(i, sz(s)) {
		int c = s[i] - 'A';
		if (get_next(v, c) == -1) {
			clear(szt);
			t[szt].par = v;
			t[szt].c = c;
			t[v].next[c] = szt;
			szt++;
			assert(szt < M);
		}
		v = t[v].next[c];
	}
	t[v].end = id;
}

int go(int v, int c);
int link(int v);

int go(int v, int c) {
	if (get_go(v, c) != -1)
		return t[v].go[c];
	if (get_next(v, c) != -1)
		return t[v].go[c] = t[v].next[c];	
	if (v == 0)
		return t[v].go[c] = 0;
	return t[v].go[c] = go(link(v), c);
}

int link(int v) {
	if (t[v].link != -1)
		return t[v].link;
		
	if (v == 0 || t[v].par == 0)
		return t[v].link = 0;
	
	return t[v].link = go(link(t[v].par), t[v].c);
}

int get_add(int v) {
	return (v == szt - 1);
}

int k, l, len;
string keyb, targ;
int cnt[A];

inline bool read()
{
	if (scanf("%d%d%d", &k, &l, &len) != 3)
		return false;

	assert(cin >> keyb >> targ);

    return true;
}

const int N = 100 + 3;

ld z[M][N][N];
int can[M][N][N];

inline void solve(int test)
{
	printf("Case #%d: ", test + 1);

	init();
	add(targ, 0);

	memset(cnt, 0, sizeof(cnt));

	forn(i, sz(keyb))
		cnt[ keyb[i] - 'A' ]++;

	forn(v, szt + 1)
		forn(i, len + 1)
			forn(c, len + 1)
				z[v][i][c] = 0.0;
	memset(can, 0, sizeof(can));

	z[0][0][0] = 1.0;
	can[0][0][0] = true;

	forn(i, len)
		forn(v, szt + 1)
			forn(c, len)
			{
				ld& dv = z[v][i][c];
				if (!can[v][i][c])
					continue;

				forn(next, A)
				{
					if (cnt[next] == 0)
						continue;

					ld p = ld(cnt[next]) / ld(sz(keyb));
					int nv = go(v, next);
					int ni = i + 1;
					int nc = c + get_add(nv);

					z[nv][ni][nc] += dv * p; 
					can[nv][ni][nc] = true;
				}
			}

	ld ans = 0.0;
	ld maxv = 0.0;
	forn(c, len + 1)
	{
		ld val = 0.0;
		bool ok = false;
		forn(v, szt + 1)
		{
			val += ld(c) * z[v][len][c];
			ok |= can[v][len][c];
		}
		ans += val;
		if (ok)
			maxv = ld(c);
	}

	cerr << maxv << endl;
	cout << setprecision(9) << fixed;
	cout << maxv - ans << endl;
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

