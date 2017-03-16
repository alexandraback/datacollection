#include <bits/stdc++.h>

#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x.size())
#define LL long long
#define mp make_pair
#define pb push_back
#define f first
#define s second

using namespace std;

const int N = 1e5 + 7;
const int mod = 1e9 + 7;

int ans[10][10];
int d[10];
int b, m, k;
vector<pair<int,int> > e;

void solve(int t) {
  scanf("%d%d", &b, &m);
  e.clear();
  for(int i = 1; i <= b; ++i)
    for(int j = i + 1; j <= b; ++j)
      e.pb(mp(i, j));
  k = sz(e);
  forn(mask, (1<<k)) {
    memset(d, 0, sizeof d);
    memset(ans, 0, sizeof ans);
    d[1] = 1;
    forn(i, k) 
      if(mask & (1<<i)) {
        d[e[i].s] += d[e[i].f];
        ans[e[i].f - 1][e[i].s - 1] = 1;
      }

    if(d[b] == m) {
      printf("POSSIBLE\n");
      forn(i, b) {
        forn(j, b) 
          printf("%d", ans[i][j]);
        printf("\n");
      }
      return;
    }
  }
  printf("IMPOSSIBLE\n");
}

int main() {
  #ifndef ONLINE_JUDGE
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  #endif
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; ++t) {
      printf("Case #%d: ", t);
      solve(t);
    }
  return 0;
}
