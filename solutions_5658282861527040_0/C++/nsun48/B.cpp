#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <iostream>
#include <string.h>
#include <deque>
#include <set>
#include <queue>
#include <complex>
#include <deque>
#include <map>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
#define LL int64_t

int DEBUG = 0;
#define MAXM 50

main(int argc, char **argv) {
  FILE *fin = (argc>=2) ? freopen(argv[1], "r", stdin) :
    freopen("B.in", "r", stdin);
  assert( fin!=NULL );
  DEBUG = (argc>=3) ? atoi(argv[2]) : 0;
  if(!DEBUG) freopen("B.out", "w", stdout);

  int T;
  cin >> T;
  for(int ii = 0; ii < T; ii++){
    int A, B, K;
    cin >> A >> B >> K;
    int ans=0;
    for (int i=0; i<A; i++) {
      for (int j=0; j<B; j++) {
	if ((i & j) < K) {
	  ans++;
	}
      }
    }
    cout << "Case #" << ii + 1 << ": ";
    cout << ans << endl;
  }
  exit(0);
}

// g++ -g B.cpp; ./a.out B.in 1

// cat ../../B.cpp | sed 's/B/newtask/g' > tmp.cpp



