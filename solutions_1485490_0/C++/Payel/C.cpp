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
#define i64 __int64
#define ld long double
#define pii pair< int, int >
#define psi pair< string, int >

const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;

typedef pair< i64, int > item;
typedef pair< i64, i64 > state;

vector< item > Line1, Line2;
map< state, i64 > :: iterator it;
map< state, i64 > M;
i64 ti, tj;

int getPos(vector< item > &v, i64 pos) {
	int i, sz = SZ(v);
	for(i = 0; i < sz; i++) {
		if(pos < v[i].first) return i;
	}
	return sz;
}

i64 solve(i64 i, i64 j) {
	if(i == ti || j == tj) return 0;
	it = M.find(state(i, j));
	if(it != M.end()) return it->second;
	int pi = getPos(Line1, i);
	int pj = getPos(Line2, j);
	i64 ret = 0, cnt;
	if(Line1[pi].second == Line2[pj].second) {
		cnt = _min(Line1[pi].first - i, Line2[pj].first - j);
		ret = cnt + solve(i + cnt, j + cnt);
	}
	else {
		ret = max(solve(Line1[pi].first, j), solve(i, Line2[pj].first));
	}
	M.insert(MP(state(i, j), ret));
	return ret;
}

int main() {
	READ("C-small-attempt0.in");
	WRITE("C-small-attempt0.out");
	int test, cs, n, m, i, type;
	i64 cnt;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d", &n, &m);
		Line1.clear();
		Line2.clear();
		M.clear();
		ti = tj = 0;
		for(i = 0; i < n; i++) {
			scanf("%I64d %d", &cnt, &type);
			ti += cnt;
			Line1.PB(MP(ti, type));
		}
		for(i = 0; i < m; i++) {
			scanf("%I64d %d", &cnt, &type);
			tj += cnt;
			Line2.PB(MP(tj, type));
		}
		printf("Case #%d: %I64d\n", cs, solve(0, 0));
	}
	return 0;
}