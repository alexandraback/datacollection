#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iomanip>
using namespace std;

#define INF 10000000

typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> pii; 
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define FOR(i,a,b) for(int i=(a); i<(b); ++i)
#define REP(i,n) FOR(i,0,n)

int C[100][100], F[100][100], W, H, L, T[100][100];

template<class T>
struct vec2_t
{
	T x, y;
	vec2_t(T x=T(), T y=T()) : x(x), y(y) {}
	bool operator < (const vec2_t& b) const { return b.x<x || (x==b.x && y<b.y); }
	bool operator == (const vec2_t& b) const { return b.x == x && b.y == y; }
	bool operator != (const vec2_t& b) const { return !(*this == b); }
};

typedef vec2_t<int> vec2;
int nb[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

int main()
{
	int TT;
	cin >> TT;
	REP(t,TT)
	{
		cin >> L >> H >> W;		
		REP(y,H) REP(x,W) cin >> C[y][x];
		REP(y,H) REP(x,W) cin >> F[y][x];
		REP(y,H) REP(x,W) T[y][x] = INF;

		typedef pair<int,vec2> piv;
		priority_queue<piv, vector<piv>, greater<piv> > q;
		q.push(make_pair(-INF,vec2(0,0)));
		while(q.size())
		{
			piv c = q.top(); q.pop();
			if(T[c.second.y][c.second.x] < INF) continue;
			else T[c.second.y][c.second.x] = c.first;
				
			int x = c.second.x;
			int y = c.second.y;
			REP(k,4)
			{
				int nx = x + nb[k][0];
				int ny = y + nb[k][1];

				if(nx < 0 || ny < 0 || nx >= W || ny >= H) continue;
				if(C[ny][nx] < F[y][x]+50 || C[ny][nx] < F[ny][nx]+50) continue;
				if(C[y][x] < F[ny][nx]+50) continue;

				int tmin = c.first;
				if( L > C[ny][nx] - 50 ) tmin = std::max(tmin, L - C[ny][nx] + 50);
				
				int t;
				if(L-std::max(0,tmin) >= F[y][x]+20)
					t = tmin + 10;
				else
					t = tmin + 100;

				q.push(make_pair(t,vec2(nx,ny)));
			}
		}
		cout << "Case #" << (t+1) <<": " << std::max(0,T[H-1][W-1]) / 10.0 << endl;
	}
	return 0;
}