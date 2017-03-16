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
string chars [8] = {"1", "i", "j", "k", "-1", "-i", "-j", "-k"},
          base [4] [4] = {{"1", "i", "j", "k"},
                               {"i", "-1", "k", "-j"},
                               {"j", "-k", "-1", "i"},
                               {"k", "j", "-i", "-1"}};
int op [8] [8], lv [11888], rv [11888];
int64 L, X, minI, maxK;
map<string, int> c2i;
string s;

int mp(int n, int64 deg) {
  if (deg == 0) return 0;
  int tmp = mp(n, deg / 2);
  tmp = op [tmp] [tmp];
  if (deg % 2 == 1) tmp = op [tmp] [n];
  return tmp;
}

int main() {
  ios_base::sync_with_stdio(false) ;

  REP(i, 8) c2i [chars [i]] = i;
  REP(i, 8) REP(j, 8) {
    string a = chars [i], b = chars [j], na = a, nb = b;
    int ret = 1;
    if (a [0] == '-') { na = a.substr(1, 1); ret *= -1; }
    if (b [0] == '-') { nb = b.substr(1, 1); ret *= -1; }
    string c = base [c2i [na]] [c2i [nb]];
    string res = (ret == -1 ? (c [0] == '-' ? c.substr(1, 1) : "-" + c) : c);
    op [i] [j] = c2i [res];
  }


  int numTests ;
  in >> numTests ;
  FOR(test, 1, numTests + 1) {
    in >> L >> X >> s;
    lv [0] = 0;
    cout << "test #" << test << endl;
    int64 l = 0, r = X * L;
    int64 li = 0, ri = MIN(9LL * (int64) SIZE(s), r - 1), lk = MAX(0LL, r - 9LL * (int64) SIZE(s)), rk = r - 1;
    minI = -1; maxK = -1;
    int cur = 0;
    for (int64 idx = li; idx < ri ; idx ++) {
      cur = op [cur] [c2i [s.substr(idx % L, 1)]];
      if (cur == 1) { minI = idx ; break ; }
    }
    cur = 0;
    for (int64 idx = rk; idx >= lk; idx --) {
      cur = op [c2i [s.substr(idx % L, 1)]] [cur];
      if (cur == 3) { maxK = idx; break ; }
    }
    REP(i, SIZE(s)) {
      lv [i + 1] = op [lv [i]] [c2i [s.substr(i, 1)]];
    }
    int total = mp(lv [SIZE(s)], X);
    bool ret = (total == 4 && minI != -1 && maxK != -1 && minI < maxK);
    out << "Case #" << test << ": " << (ret ? "YES" : "NO") << endl ;
  }

  in.close() ;
  out.close() ;

  return 0;
}
