#include <iostream>
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

#define PB push_back
#define ALL(x) ((x).begin()),((x).end())
#define FOR(i,c) for(typeof(c.begin()) i=c.begin(); i!=c.end(); ++i)
#define REP(i,n) for(int i=0; i<(n); ++i)
#define MAX(a,b) a = max((a),(b))
#define MIN(a,b) a = min((a),(b))

const int infty = 999999999;

#define DEBUGGING 1

#if defined(DEBUGGING)
#define debug(...) printf(__VA_ARGS__)
#else
#define debug(...)
#endif

const char player[3] = "XO";

int main()
{
	int nruns;
	cin >> nruns;

	VS board(4);

	for(int run=1; run<=nruns; run++) {

		bool complete = true;
		char win = '.';
		REP(y,4) {
			cin >> board[y];
			if ( board[y].find('.')!=string::npos ) complete = false;
		}

		REP(p,2) {
			REP(y,4) {
				int x;
				for(x=0; x<4; x++) if ( board[y][x]!=player[p] &&
				                        board[y][x]!='T' ) break;
				if ( x>=4 ) { win = player[p]; goto done; }
			}
			REP(x,4) {
				int y;
				for(y=0; y<4; y++) if ( board[y][x]!=player[p] &&
				                        board[y][x]!='T' ) break;
				if ( y>=4 ) { win = player[p]; goto done; }
			}
			int x;
			for(x=0; x<4; x++) if ( board[x][x]!=player[p] &&
			                        board[x][x]!='T' ) break;
			if ( x>=4 ) { win = player[p]; goto done; }
			for(x=0; x<4; x++) if ( board[3-x][x]!=player[p] &&
			                        board[3-x][x]!='T' ) break;
			if ( x>=4 ) { win = player[p]; goto done; }
		}

	  done:
		cout << "Case #" << run << ": ";

		if ( win!='.' ) {
			cout << win << " won\n";
		} else {
			if ( complete ) {
				cout << "Draw\n";
			} else {
				cout << "Game has not completed\n";
			}
		}
	}

	return 0;
}
