#include <cstdio>
#include <cstring>

void solve() {
  char s[1001];
  gets(s);
  int cnt = (s[strlen(s) - 1] != '+');
  for (int i = 0; s[i + 1]; i++)
    cnt += s[i] != s[i + 1];
  printf("%d\n", cnt);
}

int main() {
  int t;
  scanf("%d ", &t);
  for (int i = 1; i <= t; i++) {
    printf("Case #%d: ", i);
    solve();
  }
}
