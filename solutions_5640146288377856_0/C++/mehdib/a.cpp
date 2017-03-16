#include <cstdio>

using namespace std;

// vector<int> mins[21][20];

// int minScore(int c, int w, int st) {

//   int &res = mins[c-1][w-2][st];
//   if (res > 0)
//     return res;

//   int m = 999;

//   for (int i = 0; i < c; i++)
//     if (st & (1 << i) == 0)
//       m = min(m, minScore(c, w, st | (1 << i)));

// }

int minScore(int c, int w) {
  return ((c/w)+w)-(c%w==0);
}

int main(void) {

  // for (int c = 0; c <= 20; c++)
  //   for (int w = 0; w < 20; w++)
  //     mins[c][w] = vector<int>(1<<c);

  int T;

  scanf("%d", &T);

  for (int t = 1; t <= T; t++) {

    int R, C, W;
    scanf("%d%d%d", &R, &C, &W);

    int res;
    if (W == 1)
      res = R*C;
    else if (W == C)
      res = (R-1)+C;
    else
      res = (C/W)*(R-1) + minScore(C, W);
      
    printf("Case #%d: %d\n", t, res);
  }

  return 0;
}
