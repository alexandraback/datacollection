/*
USER: zobayer
TASK:
ALGO:
*/
#define _CRT_SECURE_NO_WARNINGS 1
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <iterator>
#include <utility>
using namespace std;

template< class T > T _abs(T n) { return (n < 0 ? -n : n); }
template< class T > T _max(T a, T b) { return (!(a < b) ? a : b); }
template< class T > T _min(T a, T b) { return (a < b ? a : b); }
template< class T > T sq(T x) { return x * x; }
template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
template< class T > bool inside(T a, T b, T c) { return a<=b && b<=c; }

#define MP(x, y) make_pair(x, y)
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define MEM(p, v) memset(p, v, sizeof(p))
#define CPY(d, s) memcpy(d, s, sizeof(s))
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define SZ(c) (int)c.size()
#define PB(x) push_back(x)
#define ff first
#define ss second
#define i64 long long
#define ld long double
#define pii pair< int, int >
#define psi pair< string, int >

const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
const int MAX = 1024;

vector< int > G[MAX];
bool vis[MAX];

bool dfs(int u) {
	bool ret = false;
	vis[u] = true;
	for(int i = 0, v; i < SZ(G[u]); i++) {
		v = G[u][i];
		if(!vis[v]) ret |= dfs(v);
		else return true;
	}
	return ret;
}

int main() {
	READ("A-small-attempt0.in");
	WRITE("A-small-attempt0.out");
	int test, cs, n, u, v, e;
	bool ret;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d", &n);
		for(u = 1; u <= n; u++) G[u].clear();
		for(u = 1; u <= n; u++) {
			scanf("%d", &e);
			while(e--) {
				scanf("%d", &v);
				G[u].PB(v);
			}
		}
		ret = false;
		for(u = 1; u <= n; u++) {
			memset(vis, 0, sizeof vis);
			if(!vis[u]) {
				ret = dfs(u);
				if(ret) break;
			}
		}
		if(ret) printf("Case #%d: Yes\n", cs);
		else printf("Case #%d: No\n", cs);
	}
	return 0;
}