#include <cstdio>
#include <set>
using std::set;

typedef unsigned long long ULL;
bool find;
ULL answer;

void solve(ULL ans, int n2, int n3, int n5, int n7, int digit) {
  if (find) return;
  if (digit == 12) {
    if (n2 <= 0 && n3 <= 0 && n5 <= 0 && n7 <= 0) {
      find = 1;
      answer = ans;
    }
    return;
  }
  if (n5 > 0) {
    solve(ans * 10 + 5, n2, n3, n5 - 1, n7, digit + 1);
  } else if (n7 > 0) {
    solve(ans * 10, n2, n3, n5, n7 - 1, digit + 1);
  } else {
    if (n2 > 0) solve(ans * 10 + 2, n2 - 1, n3, n5, n7, digit + 1);
    if (n2 > 1) solve(ans * 10 + 4, n2 - 2, n3, n5, n7, digit + 1);
    if (n2 > 2) solve(ans * 10 + 8, n2 - 3, n3, n5, n7, digit + 1);
    if (n3 > 0) solve(ans * 10 + 3, n2, n3 - 1, n5, n7, digit + 1);
    if (n2 > 0 && n3 > 0) solve(ans * 10 + 6, n2 - 1, n3 - 1, n5, n7, digit + 1);
  }
}
int main() {
  int T;
  scanf("%d", &T);
  puts("Case #1:");
  while (T--) {
    int R, N, M, K;
    scanf("%d%d%d%d", &R, &N, &M, &K);
    int rec = 0;
    while (R--) {
      int need[8] = {}, p[4] = {2, 3, 5, 7};
      for (int i = 0; i < K; i++) {
        int factor[8] = {};
        ULL j;
        scanf("%d", &j);
        if (j != 1)
          for (int k = 0; k < 4; k++)
            while (!(j % p[k])) {
              j /= p[k];
              factor[p[k]]++;
              if (factor[p[k]] > need[p[k]]) need[p[k]] = factor[p[k]];
            }
      }
      find = 0;
      solve(0, need[2], need[3], need[5], need[7], 0);
      rec += find;
      printf("%llu\n", answer);
    }
  }
  return 0;
}
