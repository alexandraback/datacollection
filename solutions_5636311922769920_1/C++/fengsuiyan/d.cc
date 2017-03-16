#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  for (int _ = 1, k, c, s; _ <= t; ++_) {
    scanf("%d%d%d", &k, &c, &s);
    printf("Case #%d:", _);
    if (c * s < k) {
      puts(" IMPOSSIBLE");
    }
    else {
      int m = k / c + !!(k % c);
      for (int i = 0; i < m; ++i) {
        vector<int> v;
        for (int j = i * c; j < i * c + c && j < k; ++j) {
          v.push_back(j);
        }
        while (v.size() < c) {
          v.push_back(0);
        }
        long long ps = 0;
        for (int i = 0; i < v.size(); ++i) {
          ps = ps * k + v[i];
        }
        printf(" %lld", ps + 1);
      }
      putchar('\n');
    }
  }
  return 0;
}
