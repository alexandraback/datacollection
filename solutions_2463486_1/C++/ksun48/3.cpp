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
#define MAXM 20
int ispal(LL k){
  LL stuff[120];
  int a =0;
  LL c = k;
  while(c > 0){
    stuff[a++] = c % 10;
    c = (c - c  % 10)/10;
  }
  for(int i = 0; i < a; i++){
    if(stuff[i] != stuff[a-1-i]) return 0;
  }
  return 1;
}
int square(int *a, int *sq){
  for(int i = 0; i < MAXM; i++){
    sq[i] = 0;
  }
  for(int i = 0; i < MAXM-2; i++){
    for(int j = 0; j < MAXM-2-i; j++){
      sq[i+j] += a[i]*a[j];
    }
  }
  int last = 0;
  for(int i = 0; i < MAXM-2; i++){
    if(sq[i] > 0) last = i;
    sq[i+1] += (sq[i] - sq[i] % 10)/10;
    sq[i] = sq[i] % 10;
  }
  return last;
}
int pal(int *a){
  int last = 0;
  for(int i = 0; i < MAXM-2; i++){
    if(a[i] > 0) last = i;
  }
  for(int i = 0; i <= last; i++){
    if(a[i] != a[last-i]){
      return 0;
    }
  }
  return 1;
}

main(int argc, char **argv) {
  FILE *fin = (argc>=2) ? freopen(argv[1], "r", stdin) :
    freopen("3.in", "r", stdin);
  assert( fin!=NULL );
  DEBUG = (argc>=3) ? atoi(argv[2]) : 0;
  if(!DEBUG) freopen("3.out", "w", stdout);
  LL array1[39];
  array1[0] = 1;
  array1[1] = 4;
  array1[2] = 9;
  array1[3] = 121;
  array1[4] = 484;
  array1[5] = 10201;
  array1[6] = 12321;
  array1[7] = 14641;
  array1[8] = 40804;
  array1[9] = 44944;
  array1[10] = 1002001;
  array1[11] = 1234321;
  array1[12] = 4008004;
  array1[13] = 100020001;
  array1[14] = 102030201;
  array1[15] = 104060401;
  array1[16] = 121242121;
  array1[17] = 123454321;
  array1[18] = 125686521;
  array1[19] = 400080004;
  array1[20] = 404090404;
  array1[21] = 10000200001;
  array1[22] = 10221412201;
  array1[23] = 12102420121;
  array1[24] = 12345654321;
  array1[25] = 40000800004;
  array1[26] = 1000002000001;
  array1[27] = 1002003002001;
  array1[28] = 1004006004001;
  array1[29] = 1020304030201;
  array1[30] = 1022325232201;
  array1[31] = 1024348434201;
  array1[32] = 1210024200121;
  array1[33] = 1212225222121;
  array1[34] = 1214428244121;
  array1[35] = 1232346432321;
  array1[36] = 1234567654321;
  array1[37] = 4000008000004;
  array1[38] = 4004009004004;
  /*int ans = 0;
  for(LL i = 1; i < 10000000; i++){
    LL k = i;
    int a[MAXM];
    int sq[MAXM];
    for(int m = 0; m < MAXM; m++){
      a[m] = sq[m] = 0;
    }
    int c = 0;
    while (k > 0){
      a[c++] = k % 10;
      k = (k - k % 10) / 10;
    }
    int last = square(a, sq);
    if(pal(a) && pal(sq)){
      ans ++;
      cout << "array[" << ans << "] = ";
      //cout << i << " ";
      for(int m = last; m >= 0; m--){
	cout << sq[m];
      }
      cout << endl;
      }
    if(ispal(i) && ispal(i*i)){
      cout << "array[" << ans << "] = " << i*i;
      ans++;
      cout << endl;
    }
  }
  cout << ans << endl;
  */
  int T;
  cin >> T;
  for(int ii = 0; ii < T; ii++){
    cout << "Case #" << ii + 1 << ": ";
    LL a;
    LL b;
    cin >> a >> b;
    int ans = 0;
    for(int i = 0; i < 39; i++){
      if(a <= array1[i] && array1[i] <= b){
	ans ++;
      }
    }
    cout << ans << endl;
  }
}

// g++ -g start.cpp; ./a.out start.in 1

// cat ../../start.cpp | sed 's/start/newtask/g' > tmp.cpp



