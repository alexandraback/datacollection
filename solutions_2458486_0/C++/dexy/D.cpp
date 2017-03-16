#include <iomanip>
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


typedef long long int64 ;
typedef pair<int, int> pint ;
typedef pair<int64, int64> pint64 ;
typedef vector<int> vint ;

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(x) ((x) > 0 ? (x) : -(x))

#define REP(i, n) for (int i = 0 ; i < (n) ; i ++)
#define REPD(i, n) for (int i = (n) ; i >= 0 ; i --)
#define FOR(i, a, b) for (int i = (a) ; i < (b) ; i ++)
#define FORD(i, a, b) for (int i = (a) ; i >= (b) ; i --)

#define MUL64(x, y) (((int64) (x)) * ((int64) (y)))
#define MULMOD(x, y, modul) (MUL64(x, y) % modul)
#define MUL(x, y) MULMOD(x, y, modul)
#define ADD(reg, val) { reg += val ; if (reg >= modul) reg -= modul ; }

#define SET(v, val) memset(v, val, sizeof(v)) ;

//#define BIG
string PROBLEM = "D" ;

#ifdef BIG
ifstream in((PROBLEM + "-large.in").c_str()) ; ofstream out((PROBLEM + "-large.out").c_str()) ;
#endif

#ifndef BIG
ifstream in((PROBLEM + "-small.in").c_str()) ; ofstream out((PROBLEM + "-small.out").c_str()) ;
#endif

#define MAXN 388
#define MAXK 888

int n, k, nk, init [MAXK], d2i [MAXK], i2d [MAXK], has [MAXN] [MAXK], door [MAXN], dp [1 << 23], next [1 << 23] ;
set<int> keys [MAXN] ;

int can(int mask) {
  int &ret = dp [mask] ;
  if (ret != -1) return ret ;
  ret = 0 ;
  int rem [38] ;
  REP(ik, nk) rem [ik] = init [i2d [ik]] ;
  REP(i, n) if (mask & (1 << i)) {
    rem [d2i [door [i]]] -- ;
    REP(ik, nk) rem [ik] += has [i] [i2d [ik]] ;
  }
  REP(i, n) if ((mask & (1 << i)) == 0 && rem [d2i [door [i]]] > 0) {
    if (can(mask | (1 << i))) {
      next [mask] = i ;
      return (ret = 1) ;
    }
  }
  return ret ;
}

void updateKey(int key) {
  if (d2i [key] == -1) {
    d2i [key] = nk ; i2d [nk] = key ; nk ++ ;
  }
}
int main() {
  ios_base::sync_with_stdio(false) ;

  int numTests ;
  in >> numTests ;
  FOR(test, 1, numTests + 1) {
    in >> k >> n ;
    REP(ik, MAXK) { d2i [ik] = -1 ; i2d [ik] = -1 ; init [ik] = 0 ; }
    nk = 0 ;
    REP(i, k) {
      int curK ;
      in >> curK ;
      init [curK] ++ ;
    }
    nk = 0 ;
    REP(i, n) {
      REP(ik, MAXK) has [i] [ik] = 0 ;
      keys [i].clear() ;

      int cnt, curDoor ;
      in >> door [i] >> cnt ;
      updateKey(door [i]) ;
      REP(ic, cnt)  {
        in >> curDoor ;
        has [i] [curDoor] ++ ;
      }
    }
    SET(dp, 0xffffffff) ;
    dp [(1 << n) - 1] = 1 ;
    int ret = can(0) ;
    out << "Case #" << test << ": " ;
    if (ret == 0) {
     out << "IMPOSSIBLE" << endl ;
    } else {
      int mask = 0 ;
      while (mask != ((1 << n) - 1)) {
        out << (next [mask] + 1) << " " ;
        mask |= (1 << next [mask]) ;
      }
      out << endl ;
    }

  }

  in.close() ;
  out.close() ;

  return 0;
}
