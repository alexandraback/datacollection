using namespace std;
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
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef istringstream ISS;

#define PB push_back
#define ALL(x) ((x).begin()),((x).end())
#define FOR(i,c) for(typeof(c.begin()) i=c.begin(); i!=c.end(); ++i)
#define REP(i,n) for(typeof(n) i=0; i<(n); ++i)

const int infty = 999999999;

//#define DEBUGGING 1

#if defined(DEBUGGING)
#define debug(...) printf(__VA_ARGS__)
#else
#define debug(...)
#endif

const int maxs = 35;

int H,W,D, sx, sy;
char grid[maxs][maxs];

int sign(int x)
{
	if ( x==0 ) return 0;
	return x<0 ? -1 : 1;
}

// vertical < 0, horizontal > 0, diagonal = 0
int cross(int dx, int dy, int cx, int cy)
{
	dx = 2*abs(dx);
	dy = 2*abs(dy);
	cx = 2*abs(cx)+1;
	cy = 2*abs(cy)+1;

	return dx*cy - dy*cx;
}

int valid(int dx, int dy)
{
	int flipx = 1, flipy = 1;
	int x = sx, y = sy;
	int cx = 0, cy = 0;

	debug("valid(%d,%d)\n",dx,dy);

	while ( 1 ) {

		int c = cross(dx,dy,cx,cy);
		debug("%d,%d %d,%d  cross = %d\n",x,y,cx,cy,c);

		if ( c<0 ) { // vertical
			cy += sign(dy);
			int newy = y + flipy*sign(dy);
			if ( grid[x][newy]=='#' ) {
				flipy *= -1;
				debug("flip Y\n");
			} else {
				y = newy;
			}
		} else if ( c>0 ) { // horizonal
			cx += sign(dx);
			int newx = x + flipx*sign(dx);
			if ( grid[newx][y]=='#' ) {
				flipx *= -1;
				debug("flip X\n");
		} else {
				x = newx;
			}
		} else { // diagonal
			cx += sign(dx);
			cy += sign(dy);
			int newx = x + flipx*sign(dx);
			int newy = y + flipy*sign(dy);
			if ( grid[newx][newy]=='#' ) {
				if ( grid[newx][y]!='#' && grid[x][newy]!='#' ) {
					debug("ray destroyed\n");
					return 0; // ray destroyed on corner
				} else {
					if ( grid[newx][y]=='#' && grid[x][newy]=='#') {
						flipx *= -1;
						flipy *= -1;
						debug("flip both\n");
					} else {
						if ( grid[newx][y]=='#' ) {
							flipx *= -1;
							y = newy;
							debug("flip corner Y\n");
						} else {
							flipy *= -1;
							x = newx;
							debug("flip corner X\n");
						}
					}
				}
			} else {
				// nothing special here: ray passes (through)
				x = newx;
				y = newy;
				debug("ray passes\n");
			}
		}

		if ( cx==dx && cy==dy ) break;

		// Check if we'd pass through ourselves
		if ( x==sx && y==sy && cx*dy==cy*dx ) {
			debug("passing through ourselves\n");
			return 0;
		}
	}

	debug("%d,%d ?= %d,%d   %d,%d\n",x,y,sx,sy,cx,cy);
	if ( x==sx && y==sy ) {
		debug("found solution\n");
		return 1;
	}
	return 0;
}

int main()
{
	int run, nruns;

	cin >> nruns;

	for(run=1; run<=nruns; run++) {

		cin >> H >> W >> D;
		REP(y,H) REP(x,W) {
			cin >> grid[x][y];
			if ( grid[x][y]=='X' ) {
				sx = x;
				sy = y;
			}
		}

		int res = 0;
		for(int dx=-D; dx<=D; dx++)
			for(int dy=-D; dy<=D; dy++) {
				if ( dx*dx+dy*dy>D*D || (dx==0 && dy==0) ) continue;
				if ( valid(dx,dy) ) res++;
			}

		cout << "Case #" << run << ": ";
		cout << res << endl;
	}

	return 0;
}
