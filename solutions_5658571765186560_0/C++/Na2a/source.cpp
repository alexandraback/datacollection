#include <bits/stdc++.h>

using namespace std;

typedef vector<int> big;

const int MAXN = (int) 1e2 + 7;
const int INF = (int) 1e9 + 7;

int t;
int main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  freopen("outN","w",stdout);
  #endif
  
  scanf("%d", &t);
  for (int cases = 1; cases <= t; cases++) {
    int x, n, m;
    scanf("%d%d%d", &x, &n, &m);
    if (m < n) swap(n, m);
    printf("Case #%d: ", cases);
    if ((n * m) % x != 0) puts("RICHARD"); // 100 pudovo
    else if (x == 1) puts("GABRIEL"); // 100 pudovo
    else if (x == 2) puts("GABRIEL"); // 100 pudovo
    else if (x == 3) {
      if (m < 3 || n < 2) puts("RICHARD");
      else puts("GABRIEL");
    }
    else if (x == 4) {
      if (n < 3 || m < 4) puts("RICHARD");
      else puts("GABRIEL");
    }
  }

  return 0;
}