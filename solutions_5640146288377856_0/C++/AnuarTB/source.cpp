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

int calc(int len) {
  if (len < w) return 0;
  if (len == w) return w;
  return max(w + 1, calc(len - w) + 1);
}

int main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  #endif

  scanf("%d", &t);
  for (int cases = 1; cases <= t; cases++) {
    printf("Case #%d: ", cases);
    scanf("%d%d%d", &n, &m, &w);
    printf("%d\n", calc(m));
  }
  return 0;
}