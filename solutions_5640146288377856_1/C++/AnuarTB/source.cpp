#include <bits/stdc++.h>

#define pii pair<int, int>

#define pb push_back
#define mp make_pair

#define f first
#define s second

using namespace std;

typedef long long ll;
typedef vector<int> big;

const double EPS = 1e-9;
const double PI = acos(-1);

const int MAXN = (int) 1e5 + 7;
const int INF = (int) 1e9 + 7;

int t, n, m, w;

int main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  freopen("outNew", "w", stdout);
  #endif

  scanf("%d", &t);
  for (int cases = 1; cases <= t; cases++) {
    printf("Case #%d: ", cases);
    scanf("%d%d%d", &n, &m, &w);
    int res = 0;
    res += (n - 1) * (m / w);
    while (m > w) {
      m -= w;
      res++;
    }    
    if (m > w) res += w + 1;
    else res += w;
    printf("%d\n", res);
  }
  return 0;
}
