#include <cstdio>
#include <vector>

using namespace std;

int main() {
  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);

  int N = 0;
  scanf("%d", &N);
  for (int i = 0; i < N; ++i) {
    int n = 0;
    int ans = 0;
    int count = 0;
    char shy[1001];
    scanf("%d", &n);
    scanf("%s", shy);
    for (int j = 0; j <= n; ++j) {
      if (count < j) {
        int delta = j - count;
        ans += delta;
        count += delta;
      }
      count += (shy[j] - '0');
    }
    printf("Case #%d: %d\n", i + 1, ans);
  }
  return 0;
}
