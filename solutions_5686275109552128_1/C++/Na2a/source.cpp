#include <bits/stdc++.h>

using namespace std;

typedef vector<int> big;

const int MAXN = (int) 2e3 + 7;
const int INF = (int) 1e9 + 7;

int t, n;
int a[MAXN];

int main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  freopen("outFast2", "w", stdout);
  #endif

  scanf("%d", &t);
  for (int cases = 1; cases <= t; cases++) {
    scanf("%d", &n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      ans = max(ans, a[i]);
    }
    for (int up = 1; up <= ans; up++) {
      int res = 0;
      for (int i = 0; i < n; i++) {
        int cur = a[i] / up;
        if (a[i] % up == 0) 
          --cur;
        
        res += cur;
      }
      ans = min(ans, res + up);
    }
    printf("Case #%d: %d\n", cases, ans);
  }
  return 0;
}