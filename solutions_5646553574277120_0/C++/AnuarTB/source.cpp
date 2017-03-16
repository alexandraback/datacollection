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

int t;
int c, d, v;

bool can[222];

int ans;

void go(int added) {
  int bits = 0;
  for (int i = 1; i <= v; i++)
    if (can[i]) ++bits;

  if (bits == v) {
    ans = min(ans, added);
    return;
  }
  if (added < 5) {
    for (int val = 1; val <= v; val++) {
      bool newCan[31];
      for (int cur = 0; cur <= v; cur++)
        newCan[cur] = can[cur];

      for (int cur = v - val; cur >= 0; cur--) {
        can[cur + val] |= can[cur];
      }
      go(added + 1);
      for (int cur = 0; cur <= v; cur++)
        can[cur] = newCan[cur];
    }
  }
}

int main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  #endif

  scanf("%d", &t);
  for (int cases = 1; cases <= t; cases++) {
    printf("Case #%d: ", cases);
    scanf("%d%d%d", &c, &d, &v);
    memset(can, false, sizeof can);
    can[0] = true;
    for (int i = 0; i < d; i++) {
      int val; scanf("%d", &val);
      for (int cur = v - val; cur >= 0; cur--) {
        can[cur + val] |= can[cur];
      }      
    }
    ans = INF;
    go(0);        
    printf("%d\n", ans);
    cerr<<"ok\n";
  }
  return 0;
}
