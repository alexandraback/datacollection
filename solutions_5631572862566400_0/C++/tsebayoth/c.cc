#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int b[1010];
int s[1010];

int main() {
  int T;

  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
      scanf("%d", &b[i]), s[i] = i;

    int best = 0;

    do {
      for (int i = 1; i <= n; ++i) {
        bool ok = true;
        for (int j = 1; ok && j <= i; ++j) {
          ok &= (b[s[j]] == s[(i+j-2)%i+1] || b[s[j]] == s[(i+j)%i+1]);
        }
        if (ok && i > best) best = i;
      }
    } while (next_permutation(s+1, s+n+1));

    printf("Case #%d: %d\n", t, best);
  }
  return 0;
}
