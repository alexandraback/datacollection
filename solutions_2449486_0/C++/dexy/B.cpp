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
string PROBLEM = "B" ;

#ifdef BIG
ifstream in((PROBLEM + "-large.in").c_str()) ; ofstream out((PROBLEM + "-large.out").c_str()) ;
#endif

#ifndef BIG
ifstream in((PROBLEM + "-small.in").c_str()) ; ofstream out((PROBLEM + "-small.out").c_str()) ;
#endif

#define MAXR 888
#define MAXC 888

int nr, nc, a [MAXR] [MAXC], cr [MAXR], cc [MAXC], minR [MAXR], minC [MAXR] ;
multiset<int> dr [MAXR], dc [MAXC] ;

void remove_row(int r) {
  REP(c, nc) {
    if (a [r] [c] != 0) {
      dr [r].erase(dr [r].find(a [r] [c])) ;
      dc [c].erase(dc [c].find(a [r] [c])) ;
      a [r] [c] = 0 ;
    }
  }
}

void remove_col(int c) {
  REP(r, nr) {
    if (a [r] [c] != 0) {
      dr [r].erase(dr [r].find(a [r] [c])) ;
      dc [c].erase(dc [c].find(a [r] [c])) ;
      a [r] [c] = 0 ;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false) ;

  int numTests ;
  in >> numTests ;
  FOR(test, 1, numTests + 1) {
    cout << "TEST " << test << "/" << numTests << endl ;
    in >> nr >> nc ;
    SET(cr, 0) ; SET(cc, 0) ;
    REP(r, nr) { dr [r].clear() ; minR [r] = 0 ; }
    REP(c, nc) { dc [c].clear() ; minC [c] = 0 ; }
    REP(r, nr) REP(c, nc) {
      in >> a [r] [c] ;
      dr [r].insert(a [r] [c]) ; dc [c].insert(a [r] [c]) ;
      minR [r] = max(minR [r], a [r] [c]) ; minC [c] = max(minC [c], a [r] [c]) ;
    }

    bool ok = true, empty = false ;
    while (ok && !empty) {
          empty = true ;
      int found = -1 ;
      REP(r, nr) if (dr [r].size() != 0) {
        empty = false ;
        if (*dr [r].begin() == *dr [r].rbegin() && (*dr [r].begin() >= minR [r])) {
          found = r ;
          break ;
        } ;
      }
      if (found != -1) remove_row(found) ;
      else {
        REP(c, nc) if (dc [c].size() != 0) {
          empty = false ;
          if (*dc [c].begin() == *dc [c].rbegin() && (*dc [c].begin() >= minC [c])) {
            found = c ;
            break ;
          } ;
        }
        if (found != -1) remove_col(found) ;
      }
      if (!empty && found == -1) ok = false ;
    }
    out << "Case #" << test << ": " << (ok ? "YES" : "NO") << endl ;
  }

  in.close() ;
  out.close() ;

  return 0;
}
