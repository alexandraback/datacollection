#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>

using namespace std;

int tab[20][20];


int main() {
  int T;
  int R, C, W;
  int res;

  scanf("%d", &T);
  for(int caso = 1; caso <= T; caso++) {
    scanf("%d %d %d", &R, &C, &W);
    res = (R-1)*(C/W);
    res += C/W + W-1;
    if(C%W != 0) res++;
    printf("Case #%d: %d\n", caso, res);
  }

  return 0;
}
