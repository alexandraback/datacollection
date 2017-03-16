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
typedef unsigned long long uint64 ;
typedef pair<int, int> pint ;
typedef pair<int64, int64> pint64 ;
typedef vector<int> vint ;

#define px first
#define py second

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
#define SIZE(v) ((int) (v).size())
#define ALL(v) (v).begin(), (v).end()
#define SORT(v) { sort(ALL(v)) ; }
#define RSORT(v) { SORT(v) ; REVERSE(v) ; }
#define REVERSE(v) { reverse(ALL(v)) ; }
#define UNIQUE(v) unique((v).begin(), (v).end())
#define RUNIQUE(v) { SORT(v) ; (v).resize(UNIQUE(v) - (v).begin()) ; }

#define BIG
string PROBLEM = "D" ;

#ifdef BIG
ifstream in((PROBLEM + "-large.in").c_str()) ; ofstream out((PROBLEM + "-large.out").c_str()) ;
#endif

#ifndef BIG
ifstream in((PROBLEM + "-small.in").c_str()) ; ofstream out((PROBLEM + "-small.out").c_str()) ;
#endif

int n, a [1888], b [1888];

int main() {
  ios_base::sync_with_stdio(false) ;

  int numTests ;
  in >> numTests ;
  FOR(test, 1, numTests + 1) {
    in >> n ;
    double tmp;
    REP(i, n) { in >> tmp ; a [i] = (int) (1000000.0 * tmp + 1e-9) ; }
    sort(a, a + n) ;
    REP(i, n) { in >> tmp ; b [i] = (int) (1000000.0 * tmp + 1e-9) ; }
    sort(b, b + n) ;


    int y = 0, z = 0 ;
    int ia = 0, ib = 0, remb = 0;
    while (ib < n) {
      while (ib < n && a [ia] > b [ib]) ib ++;
      if (ib < n) {
        remb ++;
        ib ++;
        ia ++;
      }
    }
    z = n - remb;
    ia = n - 1, ib = n - 1;
    y = 0;
    while (ia >= 0 && ib >= 0) {
      while (ib >= 0 && b [ib] > a [ia]) ib --;
      if (ib >= 0) { ib -- ; ia --; y ++ ;}
    }

    out << "Case #" << test << ": " << y << " " << z << endl ;
  }

  in.close() ;
  out.close() ;

  return 0;
}
