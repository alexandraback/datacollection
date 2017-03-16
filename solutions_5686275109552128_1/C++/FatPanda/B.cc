#include <cstdio>
#include <vector>

using namespace std;

int main() {
  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);

  int N = 0;
  scanf("%d", &N);
  for (int i = 0; i < N; ++i) {
    int n = 0;
    int Max = 0;
    int ans = 0;
    vector<int> pancakes;
    scanf("%d", &n);
    pancakes.resize(n);
    for (int j = 0; j < n; ++j) {
      int t = 0;
      scanf("%d", &t);
      pancakes[j] = t;
      Max = max(t, Max);
    }
    ans = Max;
    for (int j = Max - 1; j > 0; --j) {
      int c = 0;
      for (int k = 0; k < n; ++k) {
        if (pancakes[k] > j) {
          c += ((pancakes[k] - 1) / j);
        }
      }
      ans = min(ans, c + j);
    }
    printf("Case #%d: %d\n", i + 1, ans);
  }
  return 0;
}
