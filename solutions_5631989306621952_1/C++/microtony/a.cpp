#include <bits/stdc++.h>
using namespace std;
char s[1024], t[1024], u[1024], v[1024];
void solve() {
  memset(s, 0, sizeof s);
  memset(t, 0, sizeof t);
  memset(u, 0, sizeof u);
  memset(v, 0, sizeof v);
  
  scanf("%s", s);
  int n = strlen(s);
  for (int i = 0; i < n; i++) {
    u[0] = s[i];
    strcpy(u + 1, t);
    strcpy(v, t);
    v[i] = s[i];
    if (strcmp(u, v) > 0) {
      strcpy(t, u);
    } else {
      strcpy(t, v);
    }
  }
  printf("%s", t);
}
int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; t++) {
    printf("Case #%d: ", t);
    solve();
    printf("\n");
  }
  return 0;
}
