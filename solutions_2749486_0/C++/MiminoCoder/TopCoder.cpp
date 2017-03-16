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

const int dr[] = {1,0,-1,0}, dc[] = {0,1,0,-1};
const string dir = "NESW";
int X, Y;
map<pair<int, int>, int> dp, step;

int get(int r, int c)
{
	map<pair<int, int>, int>::iterator iter = dp.find(make_pair(r, c));
	if (iter == dp.end())
		return INF;
	return iter->second;
}

void Solve(int tc)
{
	DEBUG(tc)

	scanf("%d%d", &X, &Y);
	/*dp.clear();
	step.clear();

	queue<pair<int, int> > manage;
	manage.push(make_pair(0, 0));
	dp[make_pair(0, 0)] = 0;
	while (get(X, Y) == INF)
	{
		pair<int, int> temp = manage.front();
		manage.pop();

		int jump = dp[temp]+1;
		REP(d, 4)
		{
			int r = temp.first+dr[d]*jump, c = temp.second+dc[d]*jump;
			if (get(r, c) == INF)
			{
				pair<int, int> next(r, c);
				dp[next] = jump;
				step[next] = d;
				manage.push(next);
			}
		}
	}
	
	string result;
	while (get(X, Y))
	{
		pair<int, int> temp(X, Y);
		int d = step[temp], jump = dp[temp];
		result += dir[d];
		X -= dr[d] * jump;
		Y -= dc[d] * jump;
	}
	reverse(result.begin(), result.end());*/
	string result;
	if (X < 0)
		REP(i, abs(X)) result += "EW";
	else
		REP(i, abs(X)) result += "WE";
	if (Y < 0)
		REP(i, abs(Y)) result += "NS";
	else
		REP(i, abs(Y)) result += "SN";
	printf("Case #%d: %s\n", tc, result.c_str());
}

int main()
{
	int T;
	scanf("%d\n", &T);
	FOR(tc,1,T) Solve(tc);

	return 0;
}