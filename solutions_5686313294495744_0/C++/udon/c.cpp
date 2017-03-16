#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const ll INF = 5000000000;
#define PB push_back
#define sz(a) (a).size()
#define reps(i,n,m) for(int (i)=(n);(i)<(m);++(i))
#define rep(i,n) reps(i,0,n)
#define bt(b, i) ((b>>i) &1)

ll T;

int solve() {
  int n;
  cin >> n;
  vector < string > v0, v1;
  rep(i, n) {
    string t0, t1;
    cin >>t0 >> t1;
    v0.PB(t0);
    v1.PB(t1);
  }
  int ans = 0;
  for(int b = 0; b <(1 << n); ++b) {
    bool ok = true;
    rep(i, n) {
      if(bt(b, i)) {
        bool flg = false;
        rep(j, n) {
          if(!bt(b,j) && v0[i] == v0[j]) {
            flg = true;
          }
        }
        if(!flg) {ok = false; goto EXIT;}
        flg = false;
        rep(j, n) {
          if(!bt(b,j) && v1[i] == v1[j]) {
            flg = true;
          }
        }
        if(!flg) {ok = false; goto EXIT;}
      }
    }
  EXIT:
    if(ok) {
      ans = max(ans, __builtin_popcount(b));
    }
  }
  return ans;
}

int main(){
  cin >> T;
  reps(times, 1, T+1) {
    ll ans = solve();
    printf("Case #%d: %lld\n", times, ans);
  }

}
