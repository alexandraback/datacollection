#include <bits/stdc++.h>

using namespace std;

typedef vector<int> big;

const int MAXN = (int) 2e3 + 7;
const int INF = (int) 1e9 + 7;

int t, n;
int c[MAXN];

char s[MAXN];

int main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  #endif

  scanf("%d", &t);
  for (int cases = 1; cases <= t; cases++) {
    scanf("%d %s", &n, &s);

    memset(c, 0, sizeof c);
    for (int i = 0; i <= n; i++)
      c[i] = s[i] - '0';

    int clapping = 0, ans = 0;
    for (int i = 0; i <= n; i++) {
      if (!c[i]) continue;

      if (clapping >= i) clapping += c[i];
      else {
        ans += i - clapping;
        clapping = i + c[i];
      }  
    }
    printf("Case #%d: %d\n", cases, ans);
  }  
  return 0;
}