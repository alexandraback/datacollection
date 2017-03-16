#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void output(int* s, int l, int state) {
  bool first = true;
  for (int i = 0; i < l; ++i)
    if ((1 << i) & state) {
      if (first) {
        first = false;
      } else {
        printf(" ");
      }
      printf("%d", s[i]);
    }
  printf("\n");
}

void solve() {
  int N;
  const int MAXN = 500;
  int s[MAXN];
  scanf("%d", &N);
  for (int i = 0; i < N; ++i)
    scanf("%d", &s[i]);
  map<int, int> m;
  bool exists = false;
  for (int i = 1; i < (1 << N); ++i) {
    int sum = 0;
    for (int k = 0; k < N; ++k)
      if ((1 << k) & i) sum += s[k];
    if (int t = m[sum]) {
      output(s, N, t);
      output(s, N, i);
      exists = true;
      break;
    } else {
      m[sum] = i;
    }
  }
  if (!exists) {
    printf("Impossible\n");
  }
}

int main() {
  int runs;
  scanf("%d", &runs);
  for (int i = 1; i <= runs; ++i) {
    printf("Case #%d:\n", i);
    solve();
  }
  return 0;
}
