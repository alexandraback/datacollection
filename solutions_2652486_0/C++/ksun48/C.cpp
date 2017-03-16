/*
ID: ksun482
LANG: C++
TASK: start
*/
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

// cout << "numeric_limits<long long>::min()= " << numeric_limits<long long>::min() << endl;
// cout << "numeric_limits<long long>::max()= " << numeric_limits<long long>::max() << endl;

int DEBUG = 0;
#define MAXM 50
int a[200];
int is(int m, int *a){
  if(m == a[0] || m == a[1] || m == a[2] || m == a[3] || m == a[4] || m == a[5] || m == a[6]){
    return 1;
  } else {
    return 0;
  }
}
main(int argc, char **argv) {
  FILE *fin = (argc>=2) ? freopen(argv[1], "r", stdin) :
    freopen("C1.in", "r", stdin);
  assert( fin!=NULL );
  DEBUG = (argc>=3) ? atoi(argv[2]) : 0;
  if(!DEBUG) freopen("C1.out", "w", stdout);

  int T;
  cin >> T;
  int r, n, m, k;
  cin >> r >> n >> m >> k;
  for(int ii = 0; ii < T; ii++){
    cout << "Case #" << ii + 1 << ": ";
    for(int i = 0; i < r; i++){
      cout << endl;
      int a[k];
      for(int i = 0; i < k; i++) cin >> a[i];
      int num = 0;
      int ans[n];
      int yes = 0;
      for(int i = 2; i <= 5; i++){
	for(int j = 3; j <= 5; j++){
	  for(int q = 3; q <= 5; q++){
	    if(is(i*j*q,a)){
	      cout << i << j << q;
	      yes = 1;
	      break;
	    }
	    if(yes) break;
	  }
	  if(yes) break;
	}
	if(yes) break;
      }
      if(!yes){
	if(is(20,a)){
	  cout << 524;
	} else {
	  cout << 233;
	}
      }
    }
  }
  cout << endl;
  exit(0);
}

// g++ -g start.cpp; ./a.out start.in 1

// cat ../../start.cpp | sed 's/start/newtask/g' > tmp.cpp



