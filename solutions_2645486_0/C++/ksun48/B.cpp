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
int maxans = 0;
int flip(int e, int r, int n, int *v, int *a, int k){
  if(k >= n){
    int cur = e;
    int ans = 0;
    int yes = 1;
    for(int i = 0; i < n; i++){
      ans += v[i]*a[i];
      cur -= a[i];
      if(cur < 0){
	yes = 0;
	break;
      }
      cur = min(cur+r, e);
    }
    if(yes) maxans = max(maxans,ans);
  } else {
    for(int i = 0; i <= e; i++){
      a[k] = i;
      flip(e, r, n, v, a, k+1);
    }
  }
}
main(int argc, char **argv) {
  FILE *fin = (argc>=2) ? freopen(argv[1], "r", stdin) :
    freopen("B1.in", "r", stdin);
  assert( fin!=NULL );
  DEBUG = (argc>=3) ? atoi(argv[2]) : 0;
  if(!DEBUG) freopen("B1.out", "w", stdout);
  
  int T;
  cin >> T;
  for(int ii = 0; ii < T; ii++){
    int e, r, n;
    int v[12000];
    cout << "Case #" << ii + 1 << ": ";
    cin >> e >> r >> n;
    if(r > e) r = e;
    for(int i = 0; i < n; i++) cin >> v[i];
    int a[n];
    maxans = 0;
    flip(e, r, n, v, a, 0);
    cout << maxans << endl;
  }
  exit(0);
}


