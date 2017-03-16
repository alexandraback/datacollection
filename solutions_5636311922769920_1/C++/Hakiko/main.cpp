#include <bits/stdc++.h>

typedef unsigned long long UL;

UL get(UL from, UL pattLen, UL comp) {
  UL k = from + 1;
  for (UL i = 1; i < comp; ++i) {
    from *= pattLen;
    from += std::min(k, pattLen - 1);
    ++k;
  }
  return from;
}

int main() {
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; ++i) {
    int k, c, s;
    scanf("%d %d %d", &k, &c, &s);
    if (s * c < k) {
      printf("Case #%d: IMPOSSIBLE\n", i + 1);
    } else {
      printf("Case #%d: ", i + 1);
      for (int i = 0; i < k; i += c) {
        printf("%llu ", get(i, k, c) + 1);
      }
      printf("\n");
    }
  }
}
