#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <map>

using namespace std;

#define BIG
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(x) ((x) > 0 ? (x) : -(x))

#ifdef BIG
ifstream in("B-large.in") ; ofstream out("B-large.out") ;
#endif

#ifndef BIG
ifstream in("B-small.in") ; ofstream out("B-small.out") ;
#endif

int sur [1005], lib [1005] ;

int main() {
  for (int i = 0 ; i < 1005 ; i ++) { sur [i] = -1 ; lib [i] = -1 ; }
  for (int i = 0 ; i < 11 ; i ++) for (int j = MAX(0, i - 2) ; j <= i ; j ++) for (int k = MAX(0, i - 2) ; k <= j ; k ++) {
    int sum = i + j + k ;
    if (i - k == 2) sur [sum] = i ; else lib [sum] = i ;
  }
  int numTests ;
  in >> numTests ;
  for (int test = 1 ; test <= numTests ; test ++) {
    int N, S, p, score ;
    in >> N >> S >> p ;
    int ok = 0, nok = 0 ;
    for (int i = 0 ; i < N ; i ++) {
      in >> score ;
      if (lib [score] >= p) ok ++ ;
      else  if (sur [score] >= p) nok ++ ;
    }
    if (nok > S) nok = S ;
    out << "Case #" << test << ": " << (ok + nok) << endl ;
  }
  in.close() ;
  out.close() ;

  return 0;
}
