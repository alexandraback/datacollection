#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <list>
#include <set>
#include <algorithm>
#include <utility>
#include <functional>
#include <numeric>
#include <cmath>
#include <string>
#include <cctype>
#include <cstdio>
#include <cstdlib>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef istringstream ISS;

#define ALL(x) ((x).begin()),((x).end())
#if __cplusplus >= 201103L
#define FOR(i,c) for(auto i=c.begin(); i!=c.end(); ++i)
#define REP(i,n) for(decltype(n) i=0; i<(n); ++i)
#else
#define FOR(i,c) for(typeof(c.begin()) i=c.begin(); i!=c.end(); ++i)
#define REP(i,n) for(typeof(n) i=0; i<(n); ++i)
#endif

const int infty = 999999999;

template<class T> void minimize(T &a, T b) { a = min(a,b); }
template<class T> void maximize(T &a, T b) { a = max(a,b); }

#define DEBUGGING 1

#if defined(DEBUGGING)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#else
#define debug(...)
#endif

int r,c,m;

const int dx[8] = { -1, 0, 1, 1, 1, 0,-1,-1 };
const int dy[8] = { -1,-1,-1, 0, 1, 1, 1, 0 };

struct pos {
	int i,j;
};

int check(vector<string> board)
{
	queue<pos> que;
	pos p;
	p.i = r-1;
	p.j = c-1;
	que.push(p);
	while ( !que.empty() ) {
		p = que.front(); que.pop();
		int d;
		for(d=0; d<8; d++) {
			int x = p.j + dx[d];
			int y = p.i + dy[d];
			if ( 0<=x && x<c && 0<=y && y<r &&
			     board[y][x]=='*' ) break;
		}
		if ( d>=8 ) {
			REP(d1,8) {
				int x = p.j + dx[d1];
				int y = p.i + dy[d1];
				if ( 0<=x && x<c && 0<=y && y<r &&
				     board[y][x]=='.' ) {
					pos q;
					q.i = y;
					q.j = x;
					que.push(q);
					board[y][x] = 'c';
				}
			}
		}
	}

	REP(y,r) REP(x,c) if ( board[y][x]=='.' ) return 0;
	return 1;
}

int main()
{
	int nruns;
	cin >> nruns;

	for(int run=1; run<=nruns; run++) {

		cin >> r >> c >> m;
		int m1 = m;

		vector<string> board(r,string(c,'.'));

		board[r-1][c-1] = 'c';
		bool possible = true;
		int fr = r*c - m;

		if ( r==1 || c==1 ) {
			REP(i,r) REP(j,c) {
				if ( m > 0 ) { board[i][j] = '*'; m--; }
			}
			goto solved;
		}

		board = vector<string>(r,string(c,'*'));

		if ( fr==1 ) {
			m = 0;
			goto solved;
		}
		if ( fr<4 ) {
			possible = false;
			goto solved;
		}

		for(int x=2; x<=c; x++) {
			for(int y=2; y<=r; y++) {
				if ( 2*(x+y)-4<=fr && fr<=x*y ) {
					m -= (r-y)*c + (c-x)*r - (r-y)*(c-x);
					debug("solving x=%d, y=%d, m = %d\n",x,y,m);
					for(int i=r-y; i<r; i++)
						for(int j=c-x; j<c; j++)
							board[i][j] = '.';
					for(int i=r-y; i<r; i++)
						for(int j=c-x; j<c-2; j++)
							if ( m > 0 ) { board[i][j] = '*'; m--; }
					goto solved;
				}
			}
		}

		possible = false;

	  solved:
		board[r-1][c-1] = 'c';

		if ( possible && m!=0 ) debug("error: m = %d\n",m);
		if ( possible && check(board)==0 ) debug("error: unfilled\n");

		cout << "Case #" << run << ":\n";
		if ( !possible ) {
			cout << "Impossible\n";
		} else {
			REP(i,r) cout << board[i] << endl;
		}

	}

	return 0;
}
