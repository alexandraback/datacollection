#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
 
using namespace std;
 
#define PB push_back
#define SZ size()
#define ALL(x) x.begin(),x.end()
#define SORT(x) sort(ALL(x))
#define UNIQUE(x) x.erase(unique(ALL(x)),x.end())
#define REP(x, hi) for (int x=0; x<(hi); x++)
#define REPD(x, hi) for (int x=((hi)-1); x>=0; x--)
#define FOR(x, lo, hi) for (int x=(lo); x<(hi); x++)
#define FORD(x, lo, hi) for (int x=((hi)-1); x>=(lo); x--)

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<VVI> VVVI;
typedef long long LL;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;
typedef vector<double> VD;
typedef vector<VD> VVD;
typedef vector<string> VS;

const int inf = 999999999;

const int dy[4] = {-1,1,0,0};
const int dx[4] = {0,0,-1,1};

////////////////////////////////////////////////////////////

set<vector<string>> pieces;

void gen(int n, vector<string> b) {
  if (n == 0) {
    int minx=99, maxx=0, miny=99, maxy=0;
    REP(y,b.size()) REP(x,b.size()) {
      if (b[y][x]=='#') {
	minx = min(minx, x);
	maxx = max(maxx, x);
	miny = min(miny, y);
	maxy = max(maxy, y);
      }
    }      
    vector<string> piece;
    FOR(y,miny,maxy+1) piece.PB(b[y].substr(minx, maxx-minx+1));
    pieces.insert(piece);
    return;
  }
  if (b.size() == 0) {
    b = vector<string>(n, string(n, '.'));
    REP(y,n) REP(x,n) {
      b[y][x] = '#';
      gen(n-1, b);
      b[y][x] = '.';
    }
  } else {
    REP(y,b.size()) REP(x,b.size()) {
      if (b[y][x]=='#') continue;
      bool ok=false;
      REP(d,4) {
	int ny=y+dy[d], nx=x+dx[d];
	if (ny<0 || ny>=b.size() || nx<0 || nx>=b.size()) continue;
	if (b[ny][nx] == '#') { ok=true; break; }
      }
      if (ok) {
	b[y][x] = '#';
	gen(n-1, b);
	b[y][x] = '.';
      }
    }
  }
}

int fill(vector<string>& b, int y, int x) {
  if (y<0 || y>=b.size() || x<0 || x>=b[0].size()) return 0;
  if (b[y][x] == '#') return 0;
  int res = 1;
  b[y][x] = '#';
  REP(d,4) {
    int ny=y+dy[d], nx=x+dx[d];
    res += fill(b, ny, nx);
  }
  return res;
}

bool possible(vector<string> piece, int R, int C, int X) {
  REP(y0, R-(int)piece.size()+1) {
    REP(x0, C-(int)piece[0].size()+1) {
      vector<string> b(R, string(C, '.'));
      REP(y, piece.size()) {
	REP(x, piece[0].size()) {
	  b[y0+y][x0+x] = piece[y][x];
	}
      }
      bool ok = true;
      REP(y,R) REP(x,C) {
	if (b[y][x] == '.') {
	  int n = fill(b, y, x);
	  if (n % X != 0) ok = false;
	  break;
	}
      }
      if (ok) return true;
    }
  }
  return false;
}

bool solve () {
  int X,R,C;
  cin >> X >> R >> C;
  if (R*C % X != 0) return false;
  if (X >= 7) return false;
  pieces.clear();
  gen(X, vector<string>());
  for (auto piece : pieces) {
    if (!possible(piece, R, C, X) && !possible(piece, C, R, X)) return false;
  }
  return true;
}

int main () {

  int runs;
  cin >> runs;

  for (int run=1; run<=runs; run++) {
    cout << "Case #" << run << ": ";
    cout << (solve() ? "GABRIEL" : "RICHARD") << endl;
  }

  return 0;
}
