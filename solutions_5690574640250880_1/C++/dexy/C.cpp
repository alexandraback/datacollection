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
string PROBLEM = "C" ;

#ifdef BIG
ifstream in((PROBLEM + "-large.in").c_str()) ; ofstream out((PROBLEM + "-large.out").c_str()) ;
#endif

#ifndef BIG
ifstream in((PROBLEM + "-small.in").c_str()) ; ofstream out((PROBLEM + "-small.out").c_str()) ;
#endif

int r, c, m;
string t [88] ;

int main() {
  ios_base::sync_with_stdio(false) ;

  int numTests ;
  in >> numTests ;
  FOR(test, 1, numTests + 1) {
    in >> r >> c >> m ;
    int rem = r * c - m;
    out << "Case #" << test << ": " << endl ;
    if (rem == 1) {
      REP(ir, r) { REP(ic, c) out << ((ir + ic == 0) ? "c" : "*") ; out << endl ; }
    } else {
      if (r == 1) {
        out << "c";
        FOR(ic, 1, c) if (ic + 1 <= rem) out << "." ; else out << "*" ;
        out << endl;
      } else {
        if (c == 1) {
          out << "c" << endl;
          FOR(ir,1, r) if (ir + 1 <= rem) out << "." << endl ; else out << "*" << endl ;
        } else {
          bool ok = false;
          for (int h = 2 ; h <= r && !ok ; h ++) for (int l = 2 ; l <= c && !ok ; l ++) {
            if (h * l >= rem && rem >= 2 * (h + l) - 4) {
              ok = true ;
              REP(ir, r) t [ir] = string(c, '*');
              REP(ic, 2) REP(ir, h) t [ir] [ic] = '.';
              REP(ir, 2) REP(ic, l) t [ir] [ic] = '.';
              int cnt = rem - (2 * (h + l) - 4) ;
              int cr = 2, cc = 2;
              while (cnt > 0) {
                if (cr >= h) { cr = 2 ; cc ++;}
                t [cr] [cc] = '.';
                cr ++;
                cnt--;
              }
              t [0] [0] = 'c';
            }
          }
          if (ok) {
            REP(ir, r) out << t [ir] << endl;
          } else out << "Impossible" << endl ;
        }
      }
    }
  }

  in.close() ;
  out.close() ;

  return 0;
}
