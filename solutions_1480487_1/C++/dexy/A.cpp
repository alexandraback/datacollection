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

using namespace std;

#define BIG
string PROBLEM = "A" ;

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(x) ((x) > 0 ? (x) : -(x))
#define REP(i, n) for (int i = 0 ; i < (n) ; i ++)
#define FOR(i, s, n) for (int i = (s) ; i < (n) ; i ++)

typedef long long int64 ;
typedef vector<int> vint ;


#ifdef BIG
ifstream in((PROBLEM + "-large.in").c_str()) ; ofstream out((PROBLEM + "-large.out").c_str()) ;
#endif

#ifndef BIG
ifstream in((PROBLEM + "-small.in").c_str()) ; ofstream out((PROBLEM + "-small.out").c_str()) ;
#endif

int n ;
double x [205], sum ;

int main() {
  ios_base::sync_with_stdio(false) ;

  int numTests ;
  in >> numTests ;

  for (int test = 1 ; test <= numTests ; test ++) {
    in >> n ;
    sum = 0.0 ;
    for (int i = 0 ; i < n ; i ++) { in >> x [i] ; sum += x [i] ; }
    out << "Case #" << test << ":" ;
    out << fixed << setprecision(10) ;
    for (int i = 0 ; i < n ; i ++) {
      double low = 0.0, high = 1.0, mid ;
      for (int iter = 0 ; iter < 600 ; iter ++) {
        mid = 0.5 * (low + high) ;
        double curValue = x [i] + mid * sum, total = mid ;
        bool ok = true ;
        for (int k = 0 ; k < n && total < 1.0 + 1e-10; k ++) if (k != i) {
          double percent = max(0.0, (curValue - x [k]) / sum) ;
          total += percent ;
        }
        //out << i << " " << low << " " << mid << " " << high << "    " << total << endl ;
        if (total < 1.0 + 1e-10) low = mid ; else high = mid ;
      }
      out << " " << (100.0 * low) ;
    }
    out << endl ;
  }

  in.close() ;
  out.close() ;

  return 0;
}
