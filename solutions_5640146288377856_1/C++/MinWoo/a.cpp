
/*********************************
 * Google Codejam 2015: Round 1C
 * Author: MinWoo Byeon 
 *********************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <numeric>
using namespace std;

int solve1(int R, int C, int W) {
  int res = C / W * R;
  res += W - 1 + (C % W > 0);
  return res;
}

int main() {
  /*
  for ( int i=1 ; i<=10 ; ++i ) {
    for ( int j=1 ; j<=i ; ++j ) {
      printf("%d %d %d --> %d\n", 1, i, j, solve1(1, i, j));
    }
  }
  */

  int TC;
  cin >> TC;
  for ( int tc=1 ; tc<=TC ; ++tc ) {
    int R, C, W;
    cin >> R >> C >> W;
    printf("Case #%d: %d\n", tc, solve1(R, C, W));
  }
}

