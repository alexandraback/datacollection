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

struct suit{int j,p,s;};

int cnt[5][5][5], ans[5][5][5], q;
int mxans[5][5][5], mxq;


void solve(int t) {
  int J, P, S, K;
  cin >> J >> P >> S >> K;
  memset(mxans, 0, sizeof mxans);
  mxq = 0;
  vector<suit> v;
  forn(i, J) forn(j, P) forn(k, S) 
    v.pb({i,j,k});

  forn(itr, 10000) {
  random_shuffle(all(v));
  memset(cnt, 0, sizeof cnt);
  memset(ans, 0, sizeof ans);
  q = 0;
  for(auto u : v){
    int i = u.j,
      j = u.p,
      k = u.s;
    bool ok = 1;
    if(cnt[1][i][j] >= K) ok = 0;
    if(cnt[2][i][k] >= K) ok = 0;
    if(cnt[3][j][k] >= K) ok = 0;
    if(ok) {
      cnt[1][i][j]++;
      cnt[2][i][k]++;
      cnt[3][j][k]++;
      ans[i][j][k] = 1;
      q++;
    }
  }
  if(q > mxq) {
    mxq = q;
    forn(i, J) forn(j, P) forn(k, S) {
      mxans[i][j][k] = ans[i][j][k];
    }
  }
  }

  cout << mxq << "\n";
  forn(i, J) forn(j, P) forn(k, S) {
    if(mxans[i][j][k])
      cout << i + 1 << " " << j + 1 << " " << k + 1 << "\n";
  }
}

int main() {
  #ifndef ONLINE_JUDGE
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  #endif
    int T;
    cin >> T;
    for(int t = 1; t <= T; ++t) {
      cout << "Case #" << t << ": ";
      solve(t);
    }
  return 0;
}
