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

#define BIG
string PROBLEM = "A" ;

#ifdef BIG
ifstream in((PROBLEM + "-large.in").c_str()) ; ofstream out((PROBLEM + "-large.out").c_str()) ;
#endif

#ifndef BIG
ifstream in((PROBLEM + "-small.in").c_str()) ; ofstream out((PROBLEM + "-small.out").c_str()) ;
#endif


string row [4] ;

bool isWin(char ch) {
  string test = "." + string(1, (ch == 'X'? 'O' : 'X')) ;
  REP(r, 4)
    if (row [r].find_first_of(test) == string::npos) return true ;
  REP(c, 4) {
    string col = "" ;
    REP(r, 4) col += string(1, row [r] [c]) ;
    if (col.find_first_of(test) == string::npos) return true ;
  }
  string diag = "" ;
  REP(r, 4) diag += string(1, row [r] [r]) ;
  if (diag.find_first_of(test) == string::npos) return true ;

  diag = "" ;
  REP(r, 4) diag += string(1, row [r] [3 - r]) ;
  if (diag.find_first_of(test) == string::npos) return true ;

  return false ;
}

bool isFull() {
  REP(r, 4) if (row [r].find(".") != string::npos) return false ;
  return true ;
}

int main() {
  ios_base::sync_with_stdio(false) ;

  int numTests ;
  in >> numTests ;
  cout << numTests << endl ;
  FOR(test, 1, numTests + 1) {

    REP(r, 4) in >> row [r] ;
    string ret = "Game has not completed" ;
    if (isWin('X')) ret = "X won" ;
    else
    if (isWin('O')) ret = "O won" ;
    else
    if (isFull()) ret = "Draw" ;
    out << "Case #" << test << ": " << ret << endl ;
  }

  in.close() ;
  out.close() ;

  return 0;
}
