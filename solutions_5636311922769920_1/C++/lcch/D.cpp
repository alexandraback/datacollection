#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
using namespace std;

int K, C, S;

const int maxn = 100 + 10;
unsigned long long kc[maxn], ans[maxn];

int main() {
  freopen("D-large.in", "r", stdin);
  freopen("D-large.out", "w", stdout);

  int TextN;
  scanf("%d", &TextN);
  for (int TT = 1; TT <= TextN; TT++) {
    scanf("%d%d%d", &K, &C, &S);
    kc[0] = 1;
    for (int i = 1; i <= C; i++) {
      kc[i] = kc[i-1] * K;
    }
    int cur = 0;
    int ans_l = 0;
    for (int i = 1; i <= S && cur < K; i++) {
      ans[++ans_l] = 1;
      for (int j = 1; j <= C; j++) {
        cur++;
        if (cur <= K) {
          ans[ans_l] += kc[C - j] * (cur - 1);
        }
      }
    }
    printf("Case #%d:", TT);
    if (cur < K) {
      printf(" IMPOSSIBLE\n");
    } else {
      for (int i = 1; i <= ans_l; i++) {
        printf(" %lld", ans[i]);
      }
      printf("\n");
    }
  }
  return 0;
}