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

const int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int MAX = 4;

char in[MAX][MAX+1];

inline bool check(int r, int c)
{
	return r >= 0 && r < MAX && c >= 0 && c < MAX;
}

int count(int r, int c, int d, char s)
{
	int res = 0;
	while (check(r, c))
	{
		if (in[r][c] != 'T' && in[r][c] != s) break;
		++res;
		r += dr[d];
		c += dc[d];
	}
	return res;
}

void Solve(int tc)
{
	REP(r, 4) scanf("%s", in[r]);

	char result = 0;
	int full = 1;
	REP(r, MAX) REP(c, MAX)
	{
		if (in[r][c] == '.') full = 0;
		REP(d, 8)
			if ((in[r][c] == 'X' || in[r][c] == 'O') && count(r, c, d, in[r][c]) == 4)
				result = in[r][c];
	}

	printf("Case #%d: ", tc);
	if (result) printf("%c won\n", result);
	else if (full) printf("Draw\n");
	else printf("Game has not completed\n");
}

int main()
{
	int T;
	scanf("%d\n", &T);
	FOR(tc,1,T) Solve(tc);

	return 0;
}