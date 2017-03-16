#include <stdio.h>
#include <string.h>

bool check(int N, int M, int p) {
  if (p == 1) {
    return N == 0;
  }
  for (int i = 2; i <= M;  ++i) {
    if (p % i == 0) 
      if (check(N-1, M, p/i)) {
        printf("%d", i);
        return true;
      }
  }
}

void getAns(int N, int M, int K) {
  int p[10];
  bool res = false;
  int flag[10][10];
  memset(flag, 0, sizeof(flag));
  for (int i = 0;i < K; ++i) {
    scanf ("%d", &p[i]);
    if (!res && check(N,M,p[i])) {
      res = true;
    }
    int tmp = p[i];
    int pos = 1;
    while (tmp %3 ==0)  {
      flag[3][pos++] = 1;
      tmp /= 3;
    }
    pos = 1;
    while (tmp %5 == 0) {
      flag[5][pos++] = 1;
      tmp /= 5;
    }
    
  }
  if (res) return;
  for (int i = 2;i <= M; ++i) {
    for (int j = 1;j <= 10; ++j) { 
      if (flag[i][j] == 1) {
        printf("%d", i);
        --N;
      }
    }
  }
  for (int i = 0;i < N; ++i) {
    printf("2");
  }
}

int main() {
  int T, R, N, M, K;
  scanf("%d",&T);
  for (int i = 1;i <= T; ++i) {
    scanf("%d %d %d %d", &R, &N, &M, &K);
    printf("Case #%d:\n", i);
    for (int j = 0;j < R; ++j) {
      getAns(N, M, K);
      printf("\n");
    }
  }
  return 0;
}

