#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long lglg;

int main()
{
  int T;
  scanf("%d", &T);

  for(int t = 0; t < T; ++t) {
    printf("Case #%d: ", t+1);

    int X, R, C;
    scanf("%d%d%d", &X, &R, &C);
    if(R < C) swap(R, C);
    if(X > R || ((R * C) % X) != 0 || X >= 7) {
      printf("RICHARD\n");
      continue;
    }

    if(X == 3) {
      if(C < 2) {
        printf("RICHARD\n");
        continue;
      }
    } else if(X == 4) {
      if(C <= 2) {
        printf("RICHARD\n");
        continue;
      }
    } else if(X == 5) {
      if(C <= 2) {
        printf("RICHARD\n");
        continue;
      }
    } else if(X == 6) {
      if(C <= 3) {
        printf("RICHARD\n");
        continue;
      }
    }

    printf("GABRIEL\n");
  }

  return 0;
}
