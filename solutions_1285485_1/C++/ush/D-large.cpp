
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <list>
#include <cmath>
#include <complex>
#include <numeric>
#include <cassert>
using namespace std;

#define REP(i,n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i,s) for(__typeof((s).begin()) i = (s).begin(); i != (s).end(); ++i)
#define ALLOF(s) ((s).begin()), ((s).end())

typedef long long ll;

ll gcd(ll a, ll b) {
  return b == 0 ? a : gcd(b, a%b);
}
inline ll lcm(ll a, ll b) {
  return a / gcd(a, b) * b;
}

bool field[40][40];
bool go2(ll vx, ll vy, ll sx, ll sy, ll limit) {
  int cx = sx;
  int cy = sy;
  while(limit > 0){
    int nx = cx + vx;
    int ny = cy + vy;
    
    if(field[ny][nx]){
      // reflect to the same position
      vx = -vx;
      vy = -vy;
    }else{
      cx = nx;
      cy = ny;
    }
    if(cx == sx && cy == sy){
      return true;
    }
    
    --limit;
  }
  return false;
}
bool go(ll vx, ll vy, ll sx, ll sy, ll limit) {
//   cerr << "go(" << vx << "," << vy << ")" << endl;
  if(vx == 0 || vy == 0)
    return go2(vx, vy, sx, sy, limit);

  ll scale = lcm(llabs(vx), llabs(vy));
  ll sc2 = scale*2;
  ll limt = limit * limit * sc2 * sc2 / (vx*vx+vy*vy);
  sx = sx * sc2 + scale;
  sy = sy * sc2 + scale;
  ll px = sx;
  ll py = sy;
//   cerr << "scale=" << scale << ",sx=" << sx << ",sy=" << sy << endl;
  ll tt = 0;
  while(true) {
//     cerr << px << "," << py << "," << endl;
    ll t;
    if(vx < 0){
      t = (px - (px-1) / scale * scale) / -vx;
    }else{
      t = (px / scale * scale + scale - px) / vx;
    }
    if(vy < 0){
      t = min(t, (py - (py-1) / scale * scale) / -vy);
    }else{
      t = min(t, (py / scale * scale + scale - py) / vy);
    }
    
    assert(t > 0);
    ll dx = vx*t;
    ll dy = vy*t;
    tt += t;
    if(tt*tt > limt){
//       cerr << "over" << endl;
      return false;
    }

    px += dx;
    py += dy;
    if(px == sx && py == sy){
//       cerr << dx << "," << dy << endl;
//       cerr << "goal" << endl;
      return true;
    }
    
    int ci = vy > 0 ? (py-1)/sc2 : py/sc2;
    int cj = vx > 0 ? (px-1)/sc2 : px/sc2;
    int ni = vy > 0 ? py/sc2 : (py-1)/sc2;
    int nj = vx > 0 ? px/sc2 : (px-1)/sc2;
    if(px % scale == 0){
      if(py % scale == 0){ // bound LR && bound UD
	if(field[ni][nj] == false){ 
	  // .. #. .. #.
	  // /. /. /# /#
	  // go through
	}else if(field[ci][nj] == false && field[ni][cj] == false){
	  // .#
	  // /.
	  // disappear
//  	  cerr << "disappear" << endl;
	  return false;
	}else{
	  // ## .# ##
	  // /. /# /#
	  // reflect
	  if(field[ci][nj])
	    vx = -vx;
	  if(field[ni][cj])
	    vy = -vy;
	}
      }else{ // bound LR
	if(field[ni][nj])
	  vx = -vx;
      }
    }else if(py % scale == 0){ // bound UD
      if(field[ni][nj])
	vy = -vy;
    }
    
  }
  
  
}


int main(void) {
  int nCases;
  cin >> nCases;
  REP(iCase, nCases) {
//     cerr << endl;
    int nRows, nCols, limit;
    cin >> nRows >> nCols >> limit;
    int sy, sx;
    
    REP(i, nRows){
      string s;
      cin >> s;
      REP(j, nCols){
	field[i][j] = s[j] == '#';
	if(s[j] == 'X'){
	  sy = i;
	  sx = j;
	}
      }
    }

    int res = 0;
    set<pair<int,int> > visited;
    for(int x = -limit; x <= limit; ++x){
      for(int y = -limit; y <= limit; ++y){
	if(x*x+y*y <= limit*limit && (x != 0 || y != 0)){
	  int g = gcd(abs(x), abs(y));
	  pair<int,int> cur(x/g, y/g);
	  if(visited.count(cur))
	    continue;
	  visited.insert(cur);
	  
	  if(go(x/g, y/g, sx, sy, limit)){
//  	    cerr << cur.first << "," << cur.second << endl;
	    ++res;
	  }
	}
      }
    }
    
    cout << "Case #" << (iCase+1) << ": " << res << endl;
  }
  
  return 0;
}
