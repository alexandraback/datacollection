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
int ispal(LL k){
  int stuff[120];
  int a =0;
  int c = k;
  while(c > 0){
    stuff[a++] = c % 10;
    c = (c - c  % 10)/10;
  }
  for(int i = 0; i < a; i++){
    if(stuff[i] != stuff[a-1-i]) return 0;
  }
  return 1;
}
main(int argc, char **argv) {
  FILE *fin = (argc>=2) ? freopen(argv[1], "r", stdin) :
    freopen("3.in", "r", stdin);
  assert( fin!=NULL );
  DEBUG = (argc>=3) ? atoi(argv[2]) : 0;
  if(!DEBUG) freopen("3.out", "w", stdout);
  
  int T;
  cin >> T;
  if(1){  
    for(int ii = 0; ii < T; ii++){
      cout << "Case #" << ii + 1 << ": ";
      
      LL a, b;
      cin >> a >> b;
      int k = 0;
      for(LL i = 1; i*i <= b; i++){
	if(i*i >= a && ispal(i) && ispal(i*i)){
	  k++;
	}
      }
      cout << k << endl;
    }
    exit(0);
  } else {
    for(int ii = 0; ii < T; ii++){
      cout << "Case #" << ii + 1 << ": ";
      char a[300];
      char b[300];
      cin >> a >> b;
      
    }
  }
}

// g++ -g start.cpp; ./a.out start.in 1

// cat ../../start.cpp | sed 's/start/newtask/g' > tmp.cpp



