#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <algorithm>

using namespace std;

#define BIG
#define MAXN 100005
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(x) ((x) > 0 ? (x) : -(x))

#ifdef BIG
ifstream in("C-large.in") ;
ofstream out("C-large.out") ;
#endif

#ifndef BIG
ifstream in("C-small.in") ;
ofstream out("C-small.out") ;
#endif

vector<int> v [2000001] ;

int main() {
  for (int a = 1 ; a <= 2000000 ; a ++) {
    int n = a, ten = 1 ;
    while (a / (10 * ten) != 0) ten *= 10 ;
    do {
      n = 10 * (n % ten) + (n / ten) ;
      if (n > a) v [a].push_back(n) ;
    } while (n != a) ;
    sort(v [a].begin(), v [a].end()) ;
  }
  int numTests ;
  in >> numTests ;
  for (int test = 1 ; test <= numTests ; test ++) {
    int L, R ;
    in >> L >> R ;
    int cnt = 0 ;
    for (int a = L ; a <= R ; a ++) {
      for (int i = 0 ; i < v [a].size() ; i ++) {
        if (v [a] [i] >= L && v [a] [i] <= R) cnt ++ ;
      }
    }
    out << "Case #" << test << ": " << cnt << endl ;
  }
  in.close() ;
  out.close() ;

  return 0;
}
