#include <bits/stdc++.h>
using namespace std;

char s[2][19];
char best[2][19];
int ans;

void f(int t, int p) {
  if(s[t][p] == '\0') {
    if(t == 0)
      f(1, 0);
    else {
      int cur = abs(atoi(s[0]) - atoi(s[1]));
      if(cur < ans) {
	ans = cur;
	strcpy(best[0], s[0]);
	strcpy(best[1], s[1]);
      }
    }
    return;
  }
  if(s[t][p] != '?') {
    f(t, p + 1);
    return;
  }
  for(int i = '0'; i <= '9'; i++) {
    s[t][p] = i;
    f(t, p + 1);
  }
  s[t][p] = '?';
}

int main() {
  int tc, cn;
  scanf("%d", &tc);
  for(cn = 1; cn <= tc; cn++) {
    printf("Case #%d:", cn);
    scanf("%s%s", s[0], s[1]);
    ans = INT_MAX;
    f(0, 0);
    printf(" %s %s\n", best[0], best[1]);
  }
}
