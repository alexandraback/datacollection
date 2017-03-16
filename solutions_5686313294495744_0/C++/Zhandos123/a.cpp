//#pragma comment(linker, "/STACK:512000000")
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

const int N = 1e3 + 7;
const int mod = 1e9 + 7;

char s[N][20], t[N][20];
int n;
vector<int> g[N];
map<string, int>was1, was2, emp;

void solve() {
  scanf("%d", &n);
  forn(i, n) scanf("\n%s %s", s[i], t[i]);
  was1 = was2 = emp;
  int m = 0;
  forn(i, n) {
    int &id1 = was1[s[i]], &id2 = was2[t[i]];
    if(!id1) id1 = ++m;
    if(!id2) id2 = ++m;
    g[id1].pb(id2);
    g[id2].pb(id1);
  }

  int ans = 0;

  for(int i = 1; i <= m; ++i) {
    for(int j : g[i]) {
      if(sz(g[j]) > 1 && sz(g[i]) > 1) {
        ans++;
      }
    }
  }
  for(int i = 1; i <= m; ++i)
    g[i].clear();

  printf("%d\n", ans/2);
}

int main() {
  #ifndef ONLINE_JUDGE
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  #endif
    int T; scanf("%d", &T);
    for(int i = 1; i <= T; ++i) {
      printf("Case #%d: ", i);
      solve();
    }
  return 0;
}
