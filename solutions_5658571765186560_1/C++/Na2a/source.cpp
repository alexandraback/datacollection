#include <bits/stdc++.h>

using namespace std;

typedef vector<int> big;

const int MAXN = (int) 1e2 + 7;
const int INF = (int) 1e9 + 7;

int t;
int main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  freopen("outFORMULA","w",stdout);
  #endif
  
  scanf("%d", &t);
  for (int cases = 1; cases <= t; cases++) {
    int x, n, m;
    scanf("%d%d%d", &x, &n, &m);
    if (m < n) swap(n, m);
    printf("Case #%d: ", cases);
    bool lose = 0;
    if ((n * m) % x != 0) lose = 1;
    for (int N = 1; N <= x; N++) {
      int M = x - N + 1;
      if (M >= N) {
        if (N <= n && m >= M)
          continue;
        lose = true;
      }        
    }
    if (n + 2 <= x) lose = true;
    puts(lose ? "RICHARD" : "GABRIEL");
  }
  return 0;
}