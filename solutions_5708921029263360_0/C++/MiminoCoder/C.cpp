#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std; 

#define DEBUG(x) cerr << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }

const int INF = 1<<29;
typedef long long ll;

inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return n & two(b); }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }

template<class T> void chmax(T & a, const T & b) { a = max(a, b); }
template<class T> void chmin(T & a, const T & b) { a = min(a, b); }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

int J, P, S, K;

struct rec {
	int j, p, s;
} cloth[50], act[50], best[50];
int N, seen[3][10][10];

int act_i, best_i;
void go(int n) {
	if (act_i + (N-n) <= best_i) return;
	if (n == N) {
		REP(i, act_i) best[i] = act[i];
		best_i = act_i;
		return;
	}

	rec & r = cloth[n];
	if (seen[0][r.j][r.p] < K && seen[1][r.j][r.s] < K && seen[2][r.p][r.s] < K) {
		++seen[0][r.j][r.p];
		++seen[1][r.j][r.s];
		++seen[2][r.p][r.s];
		act[act_i++] = cloth[n];
		go(n+1);
		--act_i;
		--seen[0][r.j][r.p];
		--seen[1][r.j][r.s];
		--seen[2][r.p][r.s];
	}
	go(n+1);
}

void Solve(int tc) {
	scanf("%d%d%d%d", &J, &P, &S, &K);
	N = 0;
	REP(j, J) REP(p, P) REP(s, S) {
		cloth[N].j = j;
		cloth[N].p = p;
		cloth[N].s = s;
		++N;
	}
	act_i = best_i = 0;
	go(0);
	printf("Case #%d: %d\n", tc, best_i);
	REP(i, best_i)
		printf("%d %d %d\n", best[i].j+1, best[i].p+1, best[i].s+1);
}

int main()
{
	int T;
	scanf("%d\n", &T);
	FOR(tc,1,T) {
		cerr << "Test case: " << tc << endl;
		Solve(tc);
	}

	return 0;
}