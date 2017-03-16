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
int moves[1001][1001];
main(int argc, char **argv) {
  FILE *fin = (argc>=2) ? freopen(argv[1], "r", stdin) :
    freopen("B.in", "r", stdin);
  assert( fin!=NULL );
  DEBUG = (argc>=3) ? atoi(argv[2]) : 0;
  if(!DEBUG) freopen("Bsmall.out", "w", stdout);

  int T;
  cin >> T;
  for(int ii = 0; ii < T; ii++){
    cout << "Case #" << ii + 1 << ": ";
    int x, y;
    cin >> x >> y;
    if(x >= 0){
      for(int i = 0; i < x; i++){
	cout << "WE";
      }   
    } else {
      for(int i = 0; i < -x; i++){
	cout << "EW";
      }
    }
    if(y >= 0){
      for(int i = 0; i < y; i++){
	cout << "SN";
      }   
    } else {
      for(int i = 0; i < -y; i++){
	cout << "NS";
      }
    }
    cout << endl;
  }
  exit(0);
}

// g++ -g start.cpp; ./a.out start.in 1

// cat ../../start.cpp | sed 's/start/newtask/g' > tmp.cpp



