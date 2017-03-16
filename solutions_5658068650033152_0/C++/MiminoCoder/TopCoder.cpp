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
inline bool EQ(double a, double b) { return fabs(a - b) < 1e-9; }

const int INF = 1 << 29;
typedef long long ll;

inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return n & two(b); }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while (n && ++res) n -= n&(-n); return res; }

template<class T> void chmax(T & a, const T & b) { a = max(a, b); }
template<class T> void chmin(T & a, const T & b) { a = min(a, b); }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

const int MAX = 20;
const int dr[] = { -1, 0, 1, 0 }, dc[] = { 0, 1, 0, -1 };
int R, C, K;

int board[MAX][MAX];

inline bool check(int r, int c) {
	return r >= 0 && r < R && c >= 0 && c < C;
}

void Solve(int tc)
{
	scanf("%d%d%d", &R, &C, &K);

	int res = K;
	REP(state, two(R*C))
	{
		int on = ones(state);
		if (on >= res) continue;
		memset(board, 0, sizeof(board));
		queue<pair<int, int> > manage;
		int index = 0, good = 0;
		REP(r, R) REP(c, C)
		{
			if (test(state, index))
			{
				board[r][c] = 1;
				++good;
			}
			else if (r == 0 || r == R - 1 || c == 0 || c == C - 1)
			{
				board[r][c] = 1;
				manage.push(make_pair(r, c));
			}
			++index;
		}
		while (!manage.empty())
		{
			pair<int, int> temp = manage.front();
			manage.pop();
			int r = temp.first, c = temp.second;
			REP(d, 4)
			{
				int rr = r + dr[d], cc = c + dc[d];
				if (check(rr, cc) && !board[rr][cc])
				{
					board[rr][cc] = 1;
					manage.push(make_pair(rr, cc));
				}
			}
		}
		REP(r, R) REP(c, C)
		{
			if (!board[r][c])
				++good;
		}
		if (good >= K)
			res = on;
	}
	printf("Case #%d: %d\n", tc, res);
}

int main()
{
	int T;
	scanf("%d\n", &T);
	FOR(tc, 1, T) Solve(tc);

	return 0;
}