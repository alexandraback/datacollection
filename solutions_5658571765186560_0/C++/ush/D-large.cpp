
#include <cassert>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, c) for(__typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
using namespace std;
typedef long long ll;

bool RichardWins(int X, int R, int C) {
  if(R > C)
    return RichardWins(X, C, R);
  if(X == 1){
    return false;
  }else if(X == 2){
    return R*C%X != 0;
  }else if(X == 3){
    if(R == 1){
      return true;
    }else{
      return R*C%X != 0;
    }
  }else if(X == 4){
    if(R <= 2){
      return true;
    }else{
      return R*C%X != 0;
    }
  }else if(X == 5){
    if(R <= 2 || (R == 3 && C == 5)){
      return true;
    }else{
      return R*C%X != 0;
    }
  }else if(X == 6){
    if(R <= 3){
      return true;
    }else{
      return R*C%X != 0;
    }
  }else{
    return true;
  }
}

int main(void) {
  int nCase;
  scanf("%d", &nCase);
  REP(iCase, nCase){
    int X, R, C;
    scanf("%d%d%d", &X, &R, &C);
    
    printf("Case #%d: %s\n", iCase+1, RichardWins(X, R, C) ? "RICHARD" : "GABRIEL");
  }
  return 0;
}
