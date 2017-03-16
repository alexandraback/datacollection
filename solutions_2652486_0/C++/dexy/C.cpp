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
string PROBLEM = "C" ;

#ifdef BIG
ifstream in((PROBLEM + "-large.in").c_str()) ; ofstream out((PROBLEM + "-large.out").c_str()) ;
#endif

#ifndef BIG
ifstream in((PROBLEM + "-small.in").c_str()) ; ofstream out((PROBLEM + "-small.out").c_str()) ;
#endif

double prob [6] [6] [6] [6 * 6 * 6] ;

int N = 3, M = 5, K = 7, R = 3, a [12], prod [12] ;

double getProb(int a0, int a1, int a2) {
  double ret = 1.0 ;
  REP(i, K) { ret *= prob [a0] [a1] [a2] [prod [i]] ; cout << prod [i] << ": " << a0 << "," << a1 << "," << a2 << ":" << prob [a0] [a1] [a2] [prod [i]] << endl ; }
  cout << "getProb " << a0 << "," << a1 << "," << a2 << ":" << ret << endl ;
  return ret ;
}
int main() {
  ios_base::sync_with_stdio(false) ;
  int numTests ;
  in >> numTests ;
  out << "Case #" << numTests << ":" << endl ;
  in >> R >> N >> M >> K ;
  memset(prob, 0, sizeof(prob)) ;
  for (a [0] = 2 ; a [0] <= M ; a [0] ++) {
    for (a [1] = 2 ; a [1] <= M ; a [1] ++) {
      for (a [2] = 2 ; a [2] <= M ; a [2] ++) {
        double p = 1.0 / 8 ;
        REP(mask, 8) {
          int curProd = 1 ;
          REP(i, 3) if (mask & (1 << i)) curProd *= a [i] ;
          prob [a [0]] [a [1]] [a [2]] [curProd] += p ;
        }
      }
    }
  }
  /*
  for (a [0] = 2 ; a [0] <= M ; a [0] ++) {
    for (a [1] = 2 ; a [1] <= M ; a [1] ++) {
      for (a [2] = 2 ; a [2] <= M ; a [2] ++) {
          REP(prod, 126) if (prob [a [0]] [a [1]] [a [2]] [prod] > 1e-9) cout << a [0] << "," << a [1] << "," << a [2] << "," << prod << ":" << prob [a [0]] [a [1]] [a [2]] [prod] << endl ;
      }
    }
  }
*/
  FOR(test, 1, R + 1) {
    cout << "test #" << test << endl ;
    REP(i, K) in >> prod [i] ;
    int a0 = 2, a1 = 2, a2 = 2 ;
    double bestProb = getProb(a0, a1, a2) ;
    cout << "bestProb = " << bestProb << endl ;
    for (a [0] = 2 ; a [0] <= M ; a [0] ++) {
      for (a [1] = 2 ; a [1] <= M ; a [1] ++) {
        for (a [2] = 2 ; a [2] <= M ; a [2] ++) {
          double curProb = getProb(a [0], a [1], a [2]) ;
          if (curProb > bestProb) {
            bestProb = curProb ;
            a0 = a [0] ; a1 = a [1] ; a2 = a [2] ;
          }
        }
      }
    }
    out << a0 << a1 << a2 << endl ;
  }
  in.close() ;
  out.close() ;

  return 0;
}
