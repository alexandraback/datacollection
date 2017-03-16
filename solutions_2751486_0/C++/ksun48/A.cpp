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
int n;
int l;
int num[1001000];
char str[1001000];
int dp[1001000];
main(int argc, char **argv) {
  FILE *fin = (argc>=2) ? freopen(argv[1], "r", stdin) :
    freopen("A.in", "r", stdin);
  assert( fin!=NULL );
  DEBUG = (argc>=3) ? atoi(argv[2]) : 0;
  if(!DEBUG) freopen("A1.out", "w", stdout);

  int T;
  cin >> T;
  for(int ii = 0; ii < T; ii++){
    cout << "Case #" << ii + 1 << ": ";
    cin >> str;
    cin >> n;
    l = strlen(str);
    for(int i = 0; i < l; i++){
      if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u'){
	num[i] = 0;
      } else {
	num[i] = 1;
      }
    }
    int ans = 0;
    int last = -1;
    dp[0] = num[0];
    for(int i = 1; i < l; i++){
      dp[i] = (dp[i-1]+1)*num[i];
    }
    for(int i = 0; i < l; i++){
      if(dp[i] >= n){
	last = i-n+1;
      }
      ans += last + 1;
    }
    cout << ans << endl;
  }
  exit(0);
}

// g++ -g start.cpp; ./a.out start.in 1

// cat ../../start.cpp | sed 's/start/newtask/g' > tmp.cpp



