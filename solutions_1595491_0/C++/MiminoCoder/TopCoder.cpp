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

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
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

int best[31][2];

const int MAX = 101;
int N, S, P, in[MAX], dp[MAX][MAX];

int go(int n, int s)
{
	if (n == N) return s==S?0:-INF;
	if (s > S) return -INF;
	int & res = dp[n][s];
	if (res != -1) return res;
	return res = max(go(n+1,s)+(best[in[n]][0]>=P), go(n+1,s+1)+(best[in[n]][1]>=P));
}

void Solve(int tc)
{
	scanf("%d%d%d", &N, &S, &P);
	REP(i, N) scanf("%d", &in[i]);
	memset(dp, -1, sizeof(dp));
	printf("Case #%d: %d\n", tc, go(0, 0));
}

int main()
{
	FOR(a, 0, 10) FOR(b, 0, 10) FOR(c, 0, 10)
	{
		int M = max(a,max(b,c)), m = min(a,min(b,c));
		if (M-m > 2) continue;
		chmax(best[a+b+c][M-m==2], M);
	}

	int T;
	scanf("%d\n", &T);
	FOR(tc,1,T) Solve(tc);

	return 0;
}