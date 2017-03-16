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

//#define BIG
string PROBLEM = "C" ;

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(x) ((x) > 0 ? (x) : -(x))
#define REP(i, n) for (int i = 0 ; i < (n) ; i ++)
#define FOR(i, s, n) for (int i = (s) ; i < (n) ; i ++)


#ifdef BIG
ifstream in((PROBLEM + "-large.in").c_str()) ; ofstream out((PROBLEM + "-large.out").c_str()) ;
#endif

#ifndef BIG
ifstream in((PROBLEM + "-small.in").c_str()) ; ofstream out((PROBLEM + "-small.out").c_str()) ;
#endif

int n, a [505] ;
map<int, int> d ;

int main() {
  ios_base::sync_with_stdio(false) ;
  int numTests ;
  in >> numTests ;
  for (int test = 1 ; test <= numTests ; test ++) {
    in >> n ;
    for (int i = 0 ; i < n ; i ++) in >> a [i] ;
    d.clear() ;
    bool found = false ;
    int setA = 0, setB = 0 ;
    out << "Case #" << test << ":" << endl ;
    for (int mask = 1 ; mask < (1 << n) && !found ; mask ++) {
      int sum = 0 ;
      for (int i = 0 ; i < n ; i ++) if (mask & (1 << i)) sum += a [i] ;
      if (d.count(sum) > 0) {
        found = true ;
        setA = d [sum] ; setB = mask ;
      }
      d [sum] = mask ;
    }
    bool space = false ;
    for (int i = 0 ; i < n ; i ++) if (setA & (1 << i)) {
      if (space) out << " " ; else space = true ;
      out << a [i] ;
    }
    out << endl ;
    space = false ;
    for (int i = 0 ; i < n ; i ++) if (setB & (1 << i)) {
      if (space) out << " " ; else space = true ;
      out << a [i] ;
    }
    out << endl ;
  }

  in.close() ;
  out.close() ;

  return 0;
}
