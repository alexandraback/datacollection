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
string PROBLEM = "A" ;

#ifdef BIG
ifstream in((PROBLEM + "-large.in").c_str()) ; ofstream out((PROBLEM + "-large.out").c_str()) ;
#endif

#ifndef BIG
ifstream in((PROBLEM + "-small.in").c_str()) ; ofstream out((PROBLEM + "-small.out").c_str()) ;
#endif

int64 r, t ;

int main() {
  ios_base::sync_with_stdio(false) ;

  int numTests ;
  in >> numTests ;
  FOR(test, 1, numTests + 1) {
    in >> r >> t ;
    int64 low = 0, high = 1000000001, mid, ret = 0, tmp ;
    double tmpD ;
    while (low <= high) {
      mid = low + (high - low) / 2 ;
      tmpD = 2.0 * mid * r + (double) mid + 2.0 * (mid - 1.0) * mid ;
      if (tmpD < t + 1e5) {
        tmp = 2 * mid * r + mid + 2 * (mid - 1) * mid ;
        if (tmp <= t) { ret = MAX(ret, mid) ; low = mid + 1 ; } else high = mid - 1 ;
      } else high = mid - 1 ;
    }
    out << "Case #" << test << ": " << ret << endl ;
  }
  in.close() ;
  out.close() ;

  return 0;
}
