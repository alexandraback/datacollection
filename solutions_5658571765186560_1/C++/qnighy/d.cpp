// C++11
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
  int T; scanf("%d", &T);
  for(int tci = 0; tci < T; ++tci) {
    int X, R, C; scanf("%d%d%d", &X, &R, &C);
    if(R > C) swap(R, C);
    bool gabriel = false;
    if(X == 1) {
      gabriel = true;
    } else if(X == 2) {
      gabriel = (R*C%2 == 0);
    } else if(X == 3) {
      gabriel = (R*C%3 == 0) && R >= 2;
    } else if(X == 4) {
      gabriel = (R*C%4 == 0) && R >= 3;
    } else if(X == 5) {
      gabriel = (R*C%5 == 0) && R >= 4;
    } else if(X == 6) {
      gabriel = (R*C%6 == 0) && R >= 4;
    }
    printf("Case #%d: %s\n", tci+1, gabriel ? "GABRIEL" : "RICHARD");
  }
  return 0;
}
