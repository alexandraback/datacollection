#include <bits/stdc++.h>

#define REP(i,n)    for(int i=0;i<(n);++i)

using namespace std;

int main() {
  int t;
  cin>>t;
  REP(cnt,t) {
    int n;
    cin>>n;
    vector<pair<string, string>> vp;
    vector<string> fst(n), scd(n);
    REP(i,n) {
      string f,s;
      cin>>f>>s;
      vp.emplace_back(f,s);
      fst[i] = f;
      scd[i] = s;
    }
    sort(begin(fst),end(fst));
    fst.erase(unique(begin(fst),end(fst)),end(fst));
    sort(begin(scd),end(scd));
    scd.erase(unique(begin(scd),end(scd)),end(scd));
    vector<pair<int,int>> vpi;
    REP(i,n) {
      string f,s;
      tie(f,s) = vp[i];
      int fi = lower_bound(begin(fst),end(fst), f) - begin(fst);
      int si = lower_bound(begin(scd),end(scd), s) - begin(scd);
      vpi.emplace_back(fi, si);
    }
    vector<int> dp(1<<n, 0);
    dp[0] = 0;
    REP(i,1<<n) {
      uint32_t fbits = 0, sbits = 0;
      REP(j,n) {
        if ((i>>j)&1) {
          fbits |= 1 << vpi[j].first;
          sbits |= 1 << vpi[j].second;
        }
      }
      REP(j,n) {
        if (((i>>j)&1) == 0) {
          uint32_t fb = 1 << vpi[j].first;
          uint32_t sb = 1 << vpi[j].second;
          if ((fbits | fb) == fbits && (sbits | sb) == sbits) {
            dp[i|(1<<j)] = max(dp[i|(1<<j)], dp[i] + 1);
          } else {
            dp[i|(1<<j)] = max(dp[i|(1<<j)], dp[i]);
          }
        }
      }
    }
    cout << "Case #" << (cnt+1) << ": " << dp[(1<<n)-1] << endl;
  }
  return 0;
}
