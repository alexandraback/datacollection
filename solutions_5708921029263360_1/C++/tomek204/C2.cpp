#include <bits/stdc++.h>

#define REP(x,n) for(int x=0;x<(n);x++)
#define FOR(x,b,e) for(int x=b;x<=(e);x++)
#define st first
#define nd second
#define mp make_pair
#define pb push_back

using namespace std;

int j, p, s, k;

vector<pair<int, pair<int, int> > > out;

void solve() {
  out.clear();
  scanf("%d%d%d%d", &j, &p, &s, &k);
  int a[15][15], b[15][15], c[15][15];
  REP(i,15) REP(j,15) a[i][j] = b[i][j] = c[i][j] = 0;
  FOR(_j,1,j) FOR(_p,1,p) FOR(_s,1,s) {
    if (a[_j][_p] < k && b[_j][_s] < k && c[_p][_s] < k) {
      out.pb(mp(_j,mp(_p,_s)));
      a[_j][_p]++;
      b[_j][_s]++;
      c[_p][_s]++;
    }
  }
  printf("%d\n", int(out.size()));
  for (int i = 0; i < int(out.size()); i++) {
    printf("%d %d %d\n", out[i].st, out[i].nd.st, out[i].nd.nd);
  }
}

int main() {
  int t; scanf("%d", &t);
  for (int ct = 1; ct <= t; ct++) {
    printf("Case #%d: ", ct);
    solve();
  }
  return 0;
}
