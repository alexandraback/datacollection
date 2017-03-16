
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <iostream>
#include <string.h>
#include <set>
#include <queue>
#include <complex>
#include <deque>
#include <map>
using namespace std;
#define LL int64_t

int DEBUG = 0;
#define MAXM 50

main(int argc, char **argv) {
  FILE *fin = (argc>=2) ? freopen(argv[1], "r", stdin) :
    freopen("start.in", "r", stdin);
  assert( fin!=NULL );
  DEBUG = (argc>=3) ? atoi(argv[2]) : 0;
  if(!DEBUG) freopen("A1.out", "w", stdout);

  int T;
  cin >> T;
  for(int ii = 0; ii < T; ii++){
    cout << "Case #" << ii + 1 << ": ";
    double r, t;
    cin >> r >> t;
    double k = 1000*1000*1000;
    /*for(LL i = 1; i < k; i++){
      if((2*r+2*i-1)*i > t){
	//cout << i-1 << endl;
	break;
      }
      }*/
    LL s1 = -1;
    LL e1 = 10000000000;
    while(e1-s1 > 1){
      LL m1 = (s1+e1)/2;
      double m, s, e;
      m = (double)(m1);
      s = (double)(s1);
      e = (double)(e1);
      LL ans = (2*r+2*m - 1)*m;
      //cout << s << " " << m << " " << e << " " << ans << endl;
      if((2*r+2*m - 1)*m > t){
	e1 = m1;
      } else {
	s1 = m1;
      }
    }
    cout << s1 << endl;
  }
  exit(0);
}

// g++ -g start.cpp; ./a.out start.in 1

// cat ../../start.cpp | sed 's/start/newtask/g' > tmp.cpp



