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

main(int argc, char **argv) {
  FILE *fin = (argc>=2) ? freopen(argv[1], "r", stdin) :
    freopen("2.in", "r", stdin);
  assert( fin!=NULL );
  DEBUG = (argc>=3) ? atoi(argv[2]) : 0;
  if(!DEBUG) freopen("2.out", "w", stdout);

  int T;
  cin >> T;
  for(int ii = 0; ii < T; ii++){
    cout << "Case #" << ii + 1 << ": ";
    int n, m;
    cin >> n >> m;
    int stuff[n][m];
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
	cin >> stuff[i][j];
      }
    }
    int no = 0;
    for(int cur = 1; cur <= 100; cur++){
      int stuff1[n];
      int stuff2[m];
      for(int i = 0; i < n; i++) stuff1[i] = 1;
      for(int i = 0; i < m; i++) stuff2[i] = 1;
      for(int i = 0; i < n; i++){
	for(int j = 0; j < m; j++){
	  if(stuff[i][j] != cur){
	    stuff1[i] = 0;
	    stuff2[j] = 0;
	  }
	}
      }
      for(int i = 0; i < n; i++){
	for(int j = 0; j < m; j++){
	  if(stuff[i][j] == cur){
	    if(stuff1[i] == 0 && stuff2[j] == 0){
	      cout << "NO" << endl;
	      no = 1;
	      break;
	    } else {
	      stuff[i][j]++;
	    }
	  }
	}
	if(no) break;
      }
      if(no) break;
    }
    if(no == 0){
      cout << "YES" << endl;
    }
  }
  exit(0);
}

// g++ -g start.cpp; ./a.out start.in 1

// cat ../../start.cpp | sed 's/start/newtask/g' > tmp.cpp



