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
    freopen("1.in", "r", stdin);
  assert( fin!=NULL );
  DEBUG = (argc>=3) ? atoi(argv[2]) : 0;
  if(!DEBUG) freopen("1.out", "w", stdout);
  
  int T;
  cin >> T;
  for(int ii = 0; ii < T; ii++){
    cout << "Case #" << ii + 1 << ": ";
    char b[5][5];
    for(int i = 0; i < 4; i++){
      cin >> b[i];
    }
    int k = 0;
    for(int i = 0; i < 4; i++){
      int yes = 0;
      for(int j = 0; j < 4; j++){
	if(b[i][j] == 'O' || b[i][j] == '.'){
	  yes = -1;
	  break;
	} else if(b[i][j] == 'T') yes++;
      }
      if(yes == 0 || yes == 1){
	cout << "X won" << endl;
	k = 1;
	break;
      }
    }
    if(k) continue;
    for(int i = 0; i < 4; i++){
      int yes = 0;
      for(int j = 0; j < 4; j++){
	if(b[i][j] == 'X' || b[i][j] == '.'){
	  yes = -1;
	  break;
	} else if(b[i][j] == 'T') yes++;
      }
      if(yes == 0 || yes == 1){
	k = 1;
	cout << "O won" << endl;
	break;
      }
    }
    if(k) continue;
    for(int j = 0; j < 4; j++){
      int yes = 0;
      for(int i = 0; i < 4; i++){
	if(b[i][j] == 'X' || b[i][j] == '.'){
	  yes = -1;
	  break;
	} else if(b[i][j] == 'T') yes++;
      }
      if(yes == 0 || yes == 1){
	cout << "O won" << endl;
	k = 1;
	break;
      }
      if(k) continue;
    }
    if(k) continue;
    for(int j = 0; j < 4; j++){
      int yes = 0;
      for(int i = 0; i < 4; i++){
	if(b[i][j] == 'O' || b[i][j] == '.'){
	  yes = -1;
	  break;
	} else if(b[i][j] == 'T') yes++;
      }
      if(yes == 0 || yes == 1){
	k = 1;
	cout << "X won" << endl;
	break;
      }
      if(k) continue;
    }
    if(k) continue;
    for(int j = 0; j < 4; j++){
      int yes = 0;
      for(int i = 0; i < 4; i++){
	if(b[i][i] == 'O' || b[i][i] == '.'){
	  yes = -1;
	  break;
	} else if(b[i][i] == 'T') yes++;
      }
      if(yes == 0 || yes == 1){
	cout << "X won" << endl;
	k = 1;
	break;
      }
    }
    if(k) continue;
        for(int j = 0; j < 4; j++){
      int yes = 0;
      for(int i = 0; i < 4; i++){
	if(b[i][i] == 'X' || b[i][i] == '.'){
	  yes = -1;
	  break;
	} else if(b[i][i] == 'T') yes++;
      }
      if(yes == 0 || yes == 1){
	cout << "O won" << endl;
	k = 1;
	break;
      }
    }
    if(k) continue;
    for(int j = 0; j < 4; j++){
      int yes = 0;
      for(int i = 0; i < 4; i++){
	if(b[i][3-i] == 'X' || b[i][3-i] == '.'){
	  yes = -1;
	  break;
	} else if(b[i][3-i] == 'T') yes++;
      }
      if(yes == 0 || yes == 1){
	cout << "O won" << endl;
	k = 1;
	break;
      }
    }
    if(k) continue;    
    for(int j = 0; j < 4; j++){
      int yes = 0;
      for(int i = 0; i < 4; i++){
	if(b[i][3-i] == 'O' || b[i][3-i] == '.'){
	  yes = -1;
	  break;
	} else if(b[i][3-i] == 'T') yes++;
      }
      if(yes == 0 || yes == 1){
	cout << "X won" << endl;
	k = 1;
	break;
      }
    }
    if(k) continue; 
    int ans = 0;
    for(int i = 0; i < 4; i++){
      for(int j = 0; j < 4; j++){
	if(b[i][j] == '.'){
	  ans = -1;
	}
      }
    }
    if(ans == 0){
      cout << "Draw" << endl;
    } else {
      cout << "Game has not completed" << endl;
    }
  }
  exit(0);
}

// g++ -g start.cpp; ./a.out start.in 1

// cat ../../start.cpp | sed 's/start/newtask/g' > tmp.cpp



