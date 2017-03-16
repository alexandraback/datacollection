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

#define REP(i, n) for (__typeof(n) i = 0 ; i < (n) ; i ++)
#define REPD(i, n) for (__typeof(n) i = (n) ; i >= 0 ; i --)
#define FOR(i, a, b) for (__typeof(a) i = (a) ; i < (b) ; i ++)
#define FORD(i, a, b) for (__typeof(a) i = (a) ; i >= (b) ; i --)

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

#define MAXN 10888

int64 E, R, n ;
vector<pint64> v ;
int64 have [MAXN], leave [MAXN] ;

int main() {
  ios_base::sync_with_stdio(false) ;

  int numTests ;
  in >> numTests ;
  FOR(test, 1, numTests + 1) {
    in >> E >> R >> n ;
    v.clear() ;
    REP(i, n) { int64 val ; in >> val ; v.push_back(pint(-val, i)) ; }
    sort(v.begin(), v.end()) ;
    REP(i, n) { have [i] = E ; leave [i] = 0 ; }
    int64 ret = 0 ;
    cout << "TEST #" << test << endl ;
    REP(i, n) {
      int64 curVal = -v [i].first, pos = v [i].second ;
      int pi = -1, ni = n + 1 ;
      REP(j, i) {
        if (v [j].second < pos) pi = MAX(pi, v [j].second) ;
        else ni = MIN(ni, v [j].second) ;
      }
      int64 curHave = E, curLeave = 0 ;
      if (pi != -1) {
        curHave = MIN(E, leave [pi] + R * (pos - pi)) ;
      }
      if (ni != n + 1) {
        curLeave = MAX(0, have [ni] - R * (ni - pos)) ;
      }
      have [pos] = curHave ; leave [pos] = curLeave ;
      ret += (have [pos] - leave [pos]) * curVal ;
    }
    out << "Case #" << test << ": " << ret << endl ;
  }
  in.close() ;
  out.close() ;

  return 0;
}
