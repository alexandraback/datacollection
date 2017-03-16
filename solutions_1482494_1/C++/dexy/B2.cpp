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
vector<pint> s ;
bool used [1005] [2] ;

int main() {
  ios_base::sync_with_stdio(false) ;

  int numTests ;
  in >> numTests ;
  for (int test = 1 ; test <= numTests ; test ++) {
    cout << test << "/" << numTests << endl ;
    in >> n ;
    memset(used, false, sizeof(used)) ;
    for (int i = 0 ; i < n ; i ++) in >> p [i].x >> p [i].y ;
    int left = n, stars = 0, ret = 0 ;
    bool can = true ;
    while (can && left > 0) {
      can = false ;
      bool changed = true ;
      while (changed) {
        changed = false ;
        for (int i = 0 ; i < n ; i ++) {
          if (!used [i] [1]) {
            if (stars >= p [i].y) {
              if (used [i] [0]) stars ++ ;
              else stars += 2 ;
              used [i] [1] = used [i] [0] = true ;
              ret ++ ;
              left -- ;
              changed = true ;
            }
          }
        }
      }
      int best = -1, bi = -1 ;
      for (int i = 0 ; i < n ; i ++)
        if (!used [i] [0] && !used [i] [1] && p [i].x <= stars && p [i].y > best) {
          best = p [i].y ;
          bi = i ;
          can = true ;
        }
      if (bi != -1) {
        stars ++ ;
        ret ++ ;
        used [bi] [0] = true ;
      }
    }
    out << "Case #" << test << ": " ;

    if (left > 0) out << "Too Bad" ;
    else {
      out << ret ;
    }
    out << endl ;
  }

  in.close() ;
  out.close() ;

  return 0;
}
