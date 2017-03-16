#include <bits/stdc++.h>
using namespace std;

int T, B, M, v[60], ans[60][60], f;

int dfs(int k) {
  if (k == B) return 1;
  int s = 0;
  for (int i = 1; i <= B; i++) {
    if (ans[k][i]) s += dfs(i);
  }
  return s;
}

int main() {
  freopen("B-small-attempt4.in", "r", stdin);
  freopen("B-small-attempt4.out", "w+", stdout);
  scanf("%d", &T);
  for (int t = 1; t <= T; t++) {
    scanf("%d%d", &B, &M);
    for (int i = 1; i <= B; i++) {
      v[i] = 0;
      for (int j = 1; j <= B; j++) {
        ans[i][j] = 0;
      }
    }
    f = M <= (1 << (B-2));
    printf("Case #%d: %s\n", t, f ? "POSSIBLE" : "IMPOSSIBLE");
    if (f) {
      v[1] = M;
      for (int i = 2, j = M; i <= B; i++) {
        v[i] = (j+1)/2;
        j = j/2;
      }
      v[B] = 1;
      /*
      for (int i = 1; i <= B; i++) {
        printf("%d ", v[i]);
      }
      printf("\n");
      */
      for (int i = 1; i < B; i++) {
        for (int j = i+1; j <= B && v[i]; j++) {
          ans[i][j] = 1;
          v[i] -= v[j];
        }
      }
      /*
      for (int i = 1; i <= B; i++) v[i] = 0;
      v[1] = 1;
      int check = dfs(1);
      printf("check: %d %c= %d\n", check, check==M?'=':'!', M);
      */
      for (int i = 1; i <= B; i++) {
        for (int j = 1; j <= B; j++) {
          printf("%d", ans[i][j]);
        }
        printf("\n");
      }
    }
  }
  return 0;
}

