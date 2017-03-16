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
string PROBLEM = "B" ;

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(x) ((x) > 0 ? (x) : -(x))
#define REP(i, n) for (int i = 0 ; i < (n) ; i ++)
#define FOR(i, s, n) for (int i = (s) ; i < (n) ; i ++)
#define x first
#define y second

typedef long long int64 ;
typedef vector<int> vint ;
typedef pair<int, int> pint ;

#ifdef BIG
ifstream in((PROBLEM + "-large.in").c_str()) ; ofstream out((PROBLEM + "-large.out").c_str()) ;
#endif

#ifndef BIG
ifstream in((PROBLEM + "-small.in").c_str()) ; ofstream out((PROBLEM + "-small.out").c_str()) ;
#endif

int n, ret ;
pint p [1005] ;
vector<int> s1, s2 ;
int a [15], b [15] ;

void go(int i) {
  if (i == n) {

    vector<int> v ;
    for (int i = 1 ; i <= a [0]; i ++) { v.push_back(p [a [i]].y) ; v.push_back(p [a [i]].y) ; }
    for (int i = 1 ; i <= b [0]; i ++) { v.push_back(p [b [i]].x) ; v.push_back(p [b [i]].y) ; }
    int stars = 0 ;
    bool ok = true ;
    sort(v.begin(), v.end()) ;
    for (int i = 0 ; i < v.size() && ok ; i ++) {
      ok = stars >= v [i] ;
      stars ++ ;
    }
    cout << "OK " << ok << endl ;
    if (ok) ret = min(ret, a [0] + 2 * b [0]) ;
  } else {
    a [++ a[0]] = i ; go(i + 1) ; -- a [0] ;
    b [++ b[0]] = i ; go(i + 1) ; -- b [0] ;

  }
}

int main() {
  ios_base::sync_with_stdio(false) ;

  int numTests ;
  in >> numTests ;
  for (int test = 1 ; test <= numTests ; test ++) {
    in >> n ;
    s1.clear() ; s2.clear() ;
    for (int i = 0 ; i < n ; i ++) {
      in >> p [i].x >> p [i].y ;
      s1.push_back(p [i].x) ; s2.push_back(p [i].y) ;
    }
    sort(s1.begin(), s1.end()) ; sort(s2.begin(), s2.end()) ;
    bool ok = false ;
    ret = 0 ;
    for (int i = 0 ; i <= s1.size() && !ok ; i ++) {
      vector<int> v ;
      v = s2 ;
      for (int j = 0 ; j < s2.size() ; j ++) v.push_back(s2 [j]) ;
      for (int j = 0 ; j < i ; j ++) v.push_back(s1 [j]) ;
      sort(v.begin(), v.end()) ;

      ok = true ;
      int stars = 0 ;
      for (int j = 0 ; j < v.size() && ok ; j ++) {
        ok = stars >= v [j] ;
        stars ++ ;
      }
      if (ok) ret = n + i ;
    }

    out << "Case #" << test << ": " ;
    ret = 10000 ;
      a [0] = b [0] = 0 ;
      go(0) ;
    //if (!ok) out << "Too bad" ;
    if (ret == 10000) out << "Too Bad" ;
    else {
      out << ret ;
    }
    out << endl ;
  }

  in.close() ;
  out.close() ;

  return 0;
}
