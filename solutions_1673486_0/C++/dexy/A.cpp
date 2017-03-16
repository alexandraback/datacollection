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

//#define BIG
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

int A, B ;
double prob [100005], corr [100005] ;

int main() {
  ios_base::sync_with_stdio(false) ;

  int numTests ;
  in >> numTests ;
  out << fixed << setprecision(10) ;
  for (int test = 1 ; test <= numTests ; test ++) {
    in >> A >> B ;
    corr [0] = 1.0 ;
    for (int i = 1 ; i <= A ; i ++) {
      in >> prob [i] ;
      corr [i] = corr [i - 1] * prob [i] ;
    }
    double ex = 2 + B ;
    ex = min(ex, corr [A] * (B - A + 1)  + (1.0 - corr [A]) * (2 * B - A + 2)) ;
    for (int del = 0 ; del <= A ; del ++) {
      ex = min(ex, (corr [A - del] * (2 * del + B - A + 1) + (1.0 - corr [A - del]) * (2 * del + B - A + 1 + B + 1))) ;
    }
    out << "Case #" << test << ": " << ex << endl ;
  }

  in.close() ;
  out.close() ;

  return 0;
}
