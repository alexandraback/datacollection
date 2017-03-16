#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;


const int C = 32;
const int MAXW = C*2+1;
const int MAXH = 31;

int N, X, Y;
int G[MAXH][MAXW];

double rec(int k, int x, int y) {
  if(k == N) {
    return 0.0;
  }
  if(y == 0) {
    if(x == X && y == Y) return 1.0;
    G[y][x] = 1;
    double res = rec(k+1, C, MAXH-1);
    G[y][x] = 0;
    return res;
  } else {
    int left  = G[y-1][x-1];
    int right = G[y-1][x+1];
    int down  = G[y-2][x];
    if(left && right) {
      if(x == X && y == Y) return 1.0;
      G[y][x] = 1;
      double res = rec(k+1, C, MAXH-1);
      G[y][x] = 0;
      return res;
    } else if(left) {
      return rec(k, x+1, y-1);
    } else if(right) {
      return rec(k, x-1, y-1);
    } else if(down) {
      return ( 0.5 * rec(k, x+1, y-1)
	       + 0.5 * rec(k, x-1, y-1) );
    } else {
      return rec(k, x, y-1);
    }
  }
  return 0.0;
}

int main() {
  int Tc;
  cin >> Tc;
  for(int tc = 0; tc < Tc; ++tc) {
    cin >> N >> X >> Y;
    X += C;
    fill(G[0], G[MAXH], 0);
    printf("Case #%d: %.10f\n", tc+1, rec(0, C, MAXH-1));
  }
  return 0;
}
