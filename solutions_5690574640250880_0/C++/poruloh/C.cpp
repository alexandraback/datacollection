#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <numeric>
#include <utility>

using namespace std;

int main(void) {
  
  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    int R, C, M; cin >> R >> C >> M;
    int empty = R*C-M;
    bool trans = false;
    if (R > C) {
      swap(R, C);
      trans = true;
    }
    vector <string> ans(R, string(C, '*'));
    bool good = true;
    if (R == 1) {
      for (int c = 0; c < empty; c++)
	ans[0][c] = '.';
    }
    else if (R == 2) {
      if (empty == 1) ;
      else if (empty % 2 || empty == 2)
	good = false;
      else {
	for (int c = 0; c < empty/2; c++)
	  ans[0][c] = ans[1][c] = '.';
      }
    }
    else {
      if (empty == 1) ;
      else if (empty == 2 || empty == 3 || empty == 5 || empty == 7)
	good = false;
      else if (empty == 4 || empty == 6) {
	for (int c = 0; c < empty/2; c++)
	  ans[0][c] = ans[1][c] = '.';	
      }
      else {
	for (int R0 = 3; R0 <= R; R0++)
	  for (int C0 = 3; C0 <= C; C0++)
	    if (R0*C0 >= empty && empty >= (R0-1)*(C0-1)+4) {
	      for (int r = 0; r < R0-1; r++)
		for (int c = 0; c < C0-1; c++) {
		  ans[r][c] = '.';
		  empty--;
		}
	      ans[R0-1][0] = ans[R0-1][1] = ans[0][C0-1] = ans[1][C0-1] = '.';
	      empty -= 4;
	      for (int r = 0; r < R0; r++)
		for (int c = 0; c < C0; c++)
		  if (empty && ans[r][c] == '*') {
		    ans[r][c] = '.';
		    empty--;
		  }
	      goto out;
	    }
      out:;
      }
    }
    ans[0][0] = 'c';
    printf("Case #%d:\n", t);
    if (good) {
      if (trans) swap(R, C);
      for (int r = 0; r < R; r++) {
	for (int c = 0; c < C; c++)
	  printf("%c", trans ? ans[c][r] : ans[r][c]);
	printf("\n");
      }
    }
    else {
      printf("Impossible\n");
    }
  }
}
