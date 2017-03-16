#include <stdio.h>
#include <string.h>

#define MAX 10000001

long long res[2][MAX];

long long getAns(int E, int R, int N) {
  long long ans = 0;
  long long v;
  memset(res, -1, sizeof(res));
  res[0][E] = 0;
  int idx = 0;
  for (int i = 0;i < N; ++i) {
    scanf("%lld", &v);
    if (R >= E) {
      res[1-idx][E] = res[idx][E] + v*E;
      idx = 1-idx;
      continue;
    }
    for (int j = 0;j <= E; ++j) {
      if (res[idx][j] < 0) continue;
      int s = R+j-E > 0? R+j-E: 0;
      for (int k = s;k <= j; ++k) {
        long long tmp = res[idx][j] + v * k;
        if (tmp > res[1-idx][j-k+R])
          res[1-idx][j-k+R] = tmp;
      } 
    }
    idx = 1-idx;
  }
  for (int i = 0;i <= E; ++i) {
    if (ans < res[idx][i]) ans = res[idx][i];
  }
  return ans;
}

int main() {
  int T, E, R, N ;
  scanf("%d",&T);
  for (int i = 1;i <= T; ++i) {
    scanf("%d %d %d", &E, &R, &N);
    printf("Case #%d: %lld\n", i, getAns(E, R, N));
  }
  return 0;
}

