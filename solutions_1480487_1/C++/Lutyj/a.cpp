#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAXN = 200;

int N, s[MAXN], X;

void solve()
{
  for (int i = 0; i < N; ++i) {
    double l = 0.0, r = 1.0;

    while (r-l > 1e-8) {
      double m = (l+r)*0.5, sum = m, bn = s[i]+m*X;

      for (int j = 0; j < N; ++j) {
        if (j == i) continue;
        sum += max(0.0, (bn-s[j]) / X);
      }

      if (sum > 1.0) r = m; else l = m;
    }

    printf(" %.6lf", (l+r)*50);
  }

  printf("\n");
}

int main()
{
  int T; scanf("%d", &T);

  for (int t = 0; t < T; ++t) {
    scanf("%d", &N); X = 0;
    for (int i = 0; i < N; ++i) { scanf("%d", &s[i]); X += s[i]; }

    printf("Case #%d:", t+1);
    solve();
  }

  return 0;
}
