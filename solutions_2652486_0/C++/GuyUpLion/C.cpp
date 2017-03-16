#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>
#if __cplusplus > 201103L
#include <initializer_list>
#include <unordered_map>
#include <unordered_set>
#endif

using namespace std;

#ifndef ONLINE_JUDGE
#define DEBUG
#endif

#define oo 0x3F3F3F3F
#ifdef DEBUG
#define cvar(x) cerr << "<" << #x << ": " << x << ">"
#define evar(x) cvar (x) << endl
template<class T> void DISP(const char *s, T x, int n) {cerr << "[" << s << ": "; for (int i = 0; i < n; ++i) cerr << x[i] << " "; cerr << "]" << endl;}
#define disp(x,n) DISP(#x " to " #n, x, n)
#else
#define cvar(...) ({})
#define evar(...) ({})
#define disp(...) ({})
#endif
#define car first
#define cdr second
#define PB push_back
#define SZ(x) (int)((x).size())
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, a, b) for (int _end_ = (b), i = (a); i <= _end_; ++i)
#define ROF(i, a, b) for (int _end_ = (b), i = (a); i >= _end_; --i)

typedef unsigned int uint;
typedef long long int64;
typedef unsigned long long uint64;
typedef long double real;

int64 fpm(int64 b, int64 e, int64 m) { int64 t = 1; for (; e; e >>= 1, b = b * b % m) e & 1 ? t = t * b % m : 0; return t; }
template<class T> inline bool chkmin(T &a, T b) {return a > b ? a = b, true : false;}
template<class T> inline bool chkmax(T &a, T b) {return a < b ? a = b, true : false;}
template<class T> inline T sqr(T x) {return x * x;}
template <typename T> T gcd(T x, T y) {for (T t; x; t = x, x = y % x, y = t); return y; }

template<class edge> struct Graph
{
  vector<vector<edge> > adj;
  Graph(int n) {adj.clear (); adj.resize (n + 5);}
  Graph() {adj.clear (); }
  void resize(int n) {adj.resize (n + 5); }
  void add(int s, edge e){adj[s].push_back (e);}
  void del(int s, edge e) {adj[s].erase (find (iter (adj[s]), e)); }
  vector<edge>& operator [](int t) {return adj[t];}
};

int prod[300], p[300];

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
	freopen("C-small-1-attempt0.in" , "r", stdin);
	freopen("C.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);

	int T, R, n, m, K;

	cin >> T;
	FOR (tc, 1, T) {
		cin >> R >> n >> m >> K;
		cout << "Case #1:" << endl;
		FOR (i, 1, R) {

			int ans = -1, xa, xb, xc;
			FOR (j, 1, K) {
				cin >> prod[j];
			}
			FOR (a, 2, 5) {
				FOR (b, 2, 5) {
					FOR (c, 2, 5) {
						memset(p, 0, sizeof(p));
						++p[1];
						++p[a], ++p[b], ++p[c];
						++p[a * b], ++p[b * c], ++p[c * a];
						++p[a * b * c];
						int r = 1;
						FOR (i, 1, K)
							r *= p[prod[i]];
						if (r > ans) {
							ans = r;
							xa = a;
							xb = b;
							xc = c;
						}
					}
				}
			}
			cout << xa << xb << xc << endl;
		}
	}

	return 0; 
}
