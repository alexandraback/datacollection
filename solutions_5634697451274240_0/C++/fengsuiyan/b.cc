#include <bits/stdc++.h>

using namespace std;

const int N = 110;

char s[N];
int n;

int main() {
  int t;
  scanf("%d", &t);
  for (int _ = 1; _ <= t; ++_) {
    scanf("%s", s);
    n = strlen(s);
    s[n] = '+';
    s[n + 1] = 0;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] != s[i + 1])
        ++cnt;
    }
    printf("Case #%d: ", _);
    printf("%d\n", cnt);
  }
  return 0;
}
