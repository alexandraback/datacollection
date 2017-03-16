#include<cstdio>
#include<algorithm>

using namespace std;

bool richardWins(int X, int L, int l) {
  return (X - 1 > l) || (X >= 7) || ((L * l) % X != 0);
}

int main() {
  
  int T;
  
  scanf("%d", &T);

  for (int t = 1; t <= T; t++) {

    int X, R, C;
    scanf("%d%d%d", &X, &R, &C);

    printf("Case #%d: ", t);
    if (richardWins(X, max(R, C), min(R, C)))
      puts("RICHARD");
    else
      puts("GABRIEL");
  }

  return 0;
}
