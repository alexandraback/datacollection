#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <sstream>
#include <set>
#include <cmath>
#include <map>
#include <iomanip>

using namespace std;

//#define BIG
string PROBLEM = "B" ;

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(x) ((x) > 0 ? (x) : -(x))
#define REP(i, n) for (int i = 0 ; i < (n) ; i ++)
#define FOR(i, s, n) for (int i = (s) ; i < (n) ; i ++)
#define x first
#define y second

typedef long long int64 ;
typedef vector<int> vint ;
typedef pair<int, int> pint ;
typedef pair<int64, pint> conf ;

#ifdef BIG
ifstream in((PROBLEM + "-large.in").c_str()) ; ofstream out((PROBLEM + "-large.out").c_str()) ;
#endif

#ifndef BIG
ifstream in((PROBLEM + "-small.in").c_str()) ; ofstream out((PROBLEM + "-small.out").c_str()) ;
#endif

int dr [4] = {0, 0, 1, -1}, dc [4] = {1, -1, 0, 0} ;
int h, nr, nc, hc [105] [105], hf [105] [105], inf = 100000000 ;
int64 d [105] [105] ;

int move(int way, int curTime, int cr, int cc, int &xr, int &xc) {
  xr = cr + dr [way] ; xc = cc + dc [way] ;
  if (xr < 0 || xc < 0 || xr >= nr || xc >= nc) return inf ;
  int curLevel = max(hf [cr] [cc], h - curTime) ;
  if (hc [xr] [xc] - curLevel >= 50 && hc [xr] [xc] - hf [xr] [xc] >= 50 && hc [cr] [cc] - hf [xr] [xc] >= 50) {
    if (h - curTime >= hf [cr] [cc] + 20) return 10 ;
    return 100 ;
  }
  else return inf ;
}

int minTime(int way, int curTime, int cr, int cc, int &xr, int &xc) {
  xr = cr + dr [way] ; xc = cc + dc [way] ;
  if (xr < 0 || xc < 0 || xr >= nr || xc >= nc) return inf ;
  int curLevel = max(hf [cr] [cc], h - curTime) ;
  if (hc [xr] [xc] - hf [xr] [xc] >= 50 && hc [cr] [cc] - hf [xr] [xc] >= 50 && hc [xr] [xc] - hf [cr] [cc] >= 50) {
    int nextTime = 50 + h - hc [xr] [xc] ;
    if (nextTime <= curTime) nextTime = curTime ;
    if (h - nextTime >= hf [cr] [cc] + 20) return (nextTime - curTime) + 10 ;
    return (nextTime - curTime) + 100 ;
  }
  else return inf ;
}

int main() {
  ios_base::sync_with_stdio(false) ;

  int numTests ;
  in >> numTests ;
  for (int test = 1 ; test <= numTests ; test ++) {
    in >> h >> nr >> nc ;
    for (int r = 0 ; r < nr ; r ++) for (int c = 0 ; c < nc ; c ++) in >> hc [r] [c] ;
    for (int r = 0 ; r < nr ; r ++) for (int c = 0 ; c < nc ; c ++) in >> hf [r] [c] ;
    priority_queue<conf> q ;
    for (int r = 0 ; r < nr ; r ++) for (int c = 0 ; c < nc ; c ++) d [r] [c] = inf ;
    d [0] [0] = 0 ;
    q.push(conf(0, pint(0, 0))) ;
    while (!q.empty()) {
      conf cur = q.top() ;
      int curTime = -cur.x, cr = cur.y.x, cc = cur.y.y, xr, xc, cost ;
      if (curTime > 0) break ;
      q.pop() ;
      for (int way = 0 ; way < 4 ; way ++) {
        cost = move(way, curTime, cr, cc, xr, xc) ;
        if (cost < inf) {
          if (d [xr] [xc] == inf) {
            d [xr] [xc] = 0 ;
            q.push(conf(-d [xr] [xc], pint(xr, xc))) ;
          }
        } else {
          cost = minTime(way, curTime, cr, cc, xr, xc) ;
          if (cost < inf) {
            if (d [xr] [xc] > cost) {
              d [xr] [xc] = cost ;
              q.push(conf(-cost, pint(xr, xc))) ;
            }
          }
        }
      }
    }
    while (!q.empty()) {
      conf cur = q.top() ; q.pop() ;
      int curTime = -cur.x, cr = cur.y.x, cc = cur.y.y, xr, xc, cost ;
      if (cr == nr - 1 && cc == nc - 1) break ;
      for (int way = 0 ; way < 4 ; way ++) {
        cost = minTime(way, curTime, cr, cc, xr, xc) ;
        if (cost < inf) {
          cost += curTime ;
          if (d [xr] [xc] > cost) {
            d [xr] [xc] = cost ;
            q.push(conf(-cost, pint(xr, xc))) ;
          }
        }
      }
    }
    cout << "Case #" << test << ": " << 0.1 * d [nr - 1] [nc - 1] << endl ;
    out << fixed << setprecision(10) ;
    out << "Case #" << test << ": " << (double) 0.1 * d [nr - 1] [nc - 1] << endl ;
  }

  in.close() ;
  out.close() ;

  return 0;
}
