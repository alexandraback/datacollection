#include <cstdio>
#include <vector>
#include <algorithm>

int T, J, P, S, K;
const int MAX_V = 4;

int numBits(int v) {
  int count = 0;
  for (int i = 0; i < 31; ++i) {
    if (v & (1 << i)) count++;
  }
  return count;
}

int main() {
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    scanf("%d %d %d %d", &J, &P, &S, &K);
    int total = J * P * S;
    int best = 0;
    int bestidx = 0;
    for (int i = 0; i < (1 << total); ++i) {
      int jp[MAX_V][MAX_V] = {};
      int js[MAX_V][MAX_V] = {};
      int ps[MAX_V][MAX_V] = {};
      int nb = numBits(i);
      for (int j = 0; j < J; ++j) {
        for (int p = 0; p < P; ++p) {
          for (int s = 0; s < S; ++s) {
            int idx = j * S * P + p * S + s;
            if (i & (1 << idx)) {
              jp[j][p]++;
              js[j][s]++;
              ps[p][s]++;
              if (jp[j][p] > K) goto end;
              if (js[j][s] > K) goto end;
              if (ps[p][s] > K) goto end;
            }
          }
        }
      }
      if (nb > best) {
        best = nb;
        bestidx = i;
      }
      end:
      ;
    }
    printf("Case #%d: %d\n", t, best);
    for (int j = 0; j < J; ++j) {
        for (int p = 0; p < P; ++p) {
          for (int s = 0; s < S; ++s) {
            int idx = j * S * P + p * S + s;
            if (bestidx & (1 << idx)) {
              printf("%d %d %d\n", j + 1, p + 1, s + 1);
            }
          }
        }
      }
  }
}
