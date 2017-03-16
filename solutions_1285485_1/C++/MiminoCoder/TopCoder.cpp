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

int R, C, D, sr, sc;
char board[2][31][31];

int gcd(int a, int b)
{
	if (!b) return a;
	return gcd(b, a%b);
}

bool Simulate(int sr, int sc, int dr, int dc, int mr, int mc, char board[31][31]) // dr <= dc
{
	int steps = 1;

	dr *= 2;
	dc *= 2;
	int r = sr, c = sc, ar = dc/2;
	while (steps*steps*(dr*dr+dc*dc)/4 <= D*D)
	{
		REP(step, dc/2)
		{
			int aar = (2*dc-(ar+dr))%dc, rr = r+(ar+dr)/dc*mr, cc = c+mc;
			if (ar+dr < dc) // no row shift
			{
				if (board[rr][cc] == '#')
					mc = -mc;
				else c = cc;
			}
			else if (ar == aar) // through the corner
			{
				if (board[rr][cc] == '#')
				{
					if (board[rr-mr][cc] == '#' && board[rr][cc-mc] == '#')
					{
						mr = -mr;
						mc = -mc;
					}
					else if (board[rr-mr][cc] == '#')
					{
						mc = -mc;
						r = rr;
					}
					else if (board[rr][cc-mc] == '#')
					{
						mr = -mr;
						c = cc;
					}
					else return false;
				}
				else
				{
					r = rr;
					c = cc;
				}
			}
			else if (ar < aar) // row first
			{
				if (board[rr][c] == '#')
					mr = -mr;
				else r = rr;
				if (board[r][cc] == '#')
					mc = -mc;
				else c = cc;
			}
			else // col first
			{
				if (board[r][cc] == '#')
					mc = -mc;
				else c = cc;
				if (board[rr][c] == '#')
					mr = -mr;
				else r = rr;
			}

			ar = (ar+dr)%dc;
		}
		if (r == sr && c == sc)
			return true;
		++steps;
	}
	return false;
}

void Solve(int tc)
{
	scanf("%d%d%d", &R, &C, &D);
	REP(i, R)
	{
		scanf("%s", board[0][i]);
		REP(j, C)
		{
			if (board[0][i][j] == 'X')
			{
				sr = i;
				sc = j;
				board[0][i][j] = '.';
			}
			board[1][j][i] = board[0][i][j];
		}
	}

	int res = 0;
	FOR(dc, 1, D) FOR(dr, 0, dc)
		if (gcd(dr, dc) == 1)
		{
			res += Simulate(sr, sc, dr, dc, 1, 1, board[0]);
			res += Simulate(sr, sc, dr, dc, 1, -1, board[0]);
			if (dr)
			{
				res += Simulate(sr, sc, dr, dc, -1, 1, board[0]);
				res += Simulate(sr, sc, dr, dc, -1, -1, board[0]);
			}
			if (dr < dc)
			{
				res += Simulate(sc, sr, dr, dc, 1, 1, board[1]);
				res += Simulate(sc, sr, dr, dc, 1, -1, board[1]);
				if (dr)
				{
					res += Simulate(sc, sr, dr, dc, -1, 1, board[1]);
					res += Simulate(sc, sr, dr, dc, -1, -1, board[1]);
				}
			}
		}
	printf("Case #%d: %d\n", tc, res);
}

int main()
{
	int T;
	scanf("%d\n", &T);
	FOR(tc,1,T) Solve(tc);

	return 0;
}

/*
1
3 10 20
##########
#X.......#
##########
*/