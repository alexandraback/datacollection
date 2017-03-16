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

const int dr[] = {-1,0,1,0}, dc[] = {0,1,0,-1};
const int MAX = 101;
int H, R, C, top[MAX][MAX], bot[MAX][MAX];
int best[MAX][MAX];

bool check(int r, int c) { return r >= 0 && r < R && c >= 0 && c < C; }
bool can(int r1, int c1, int r2, int c2)
{
	return bot[r1][c1]+50 <= top[r2][c2] && bot[r2][c2]+50 <= top[r2][c2] && bot[r2][c2]+50 <= top[r1][c1];
}

void go()
{
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > manage;
	REP(r,R) REP(c,C)
		if (best[r][c] == 0)
			manage.push(make_pair(0, r*MAX+c));

	while (!manage.empty())
	{
		pair<int, int> temp = manage.top();
		manage.pop();
		int r = temp.second/MAX, c = temp.second%MAX, cost = temp.first;
		if (best[r][c] != cost) continue;

		REP(d, 4)
		{
			int rr = r+dr[d], cc = c+dc[d];
			if (check(rr, cc) && can(r,c,rr,cc) && H+50 <= top[rr][cc] && best[rr][cc] == -1)
			{
				best[rr][cc] = 0;
				manage.push(make_pair(0, rr*MAX+cc));
			}
		}
	}
}

void go2()
{
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > manage;
	REP(r,R) REP(c,C)
		if (best[r][c] == 0)
			manage.push(make_pair(0, r*MAX+c));

	while (!manage.empty())
	{
		pair<int, int> temp = manage.top();
		manage.pop();
		int r = temp.second/MAX, c = temp.second%MAX, cost = temp.first;
		if (best[r][c] != cost) continue;

		REP(d, 4)
		{
			int rr = r+dr[d], cc = c+dc[d];
			if (!check(rr, cc) || !can(r,c,rr,cc))
				continue;
			int needH = min(top[rr][cc]-50, H-cost);
			int cost2 = H-needH + (needH >= 20+bot[r][c] ? 10 : 100);
			if (best[rr][cc] == -1 || best[rr][cc] > cost2)
			{
				best[rr][cc] = cost2;
				manage.push(make_pair(cost2, rr*MAX+cc));
			}
		}
	}
}

void Solve(int tc)
{
	scanf("%d%d%d", &H, &R, &C);
	REP(r,R) REP(c,C) scanf("%d", &top[r][c]);
	REP(r,R) REP(c,C) scanf("%d", &bot[r][c]);
	memset(best, -1, sizeof(best));
	best[0][0] = 0;
	go();
	go2();

	printf("Case #%d: %.9lf\n", tc, best[R-1][C-1]/10.0);
}

int main()
{
	int T;
	scanf("%d\n", &T);
	FOR(tc,1,T) Solve(tc);

	return 0;
}