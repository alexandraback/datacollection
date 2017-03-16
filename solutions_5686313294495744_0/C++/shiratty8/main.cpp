#include <bits/stdc++.h>
using namespace std;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FORR(x,arr) for(auto&& x:arr)
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define RFOR(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define REP(i,n) for (int i = 0; i < (n); i++)
#define RREP(i,n) for (int i = (n)-1; i >= 0; i--)
#define ALL(x) (x).begin(), (x).end()
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define RITR(x,c) for(__typeof(c.rbegin()) x=c.rbegin();x!=c.rend();x++)
#define BIT(n) (1LL<<(n))
#define SZ(x) ((int)(x).size())
typedef long long ll;
// -------------------------------------

int N;
typedef pair<string, string> SS;
SS WS[1000];
map<string, set<int>> fc, sc;

void solve() {
  cin >> N;
  REP(i, N) {
    cin >> WS[i].first >> WS[i].second;
    fc[WS[i].first].insert(i);
    sc[WS[i].second].insert(i);
  }

  set<int> cand;
  REP(i, N) {
    string& f = WS[i].first;
    string& s = WS[i].second;
    if (SZ(fc[f]) >= 2 && SZ(sc[s]) >= 2) {
      cand.insert(i);
    }
  }

  while (1) {
    bool changed = 0;
    FORR(i, cand) {
      string& f = WS[i].first;
      string& s = WS[i].second;
      bool af = true, as = true;
      FORR(j, fc[f]) {
        if (cand.count(j)==0) {
          // 候補じゃない人がいる
          af = false;
          break;
        }
      }
      FORR(j, sc[s]) {
        if (cand.count(j)==0) {
          // 候補じゃない人がいる
          as = false;
          break;
        }
      }
      if (af && as) {
        cand.erase(i);
        changed=1;
        break;
      }
    }
    if (!changed) break;
  }

  int ans = SZ(cand);

  FORR(ss, fc) {
    set<int>& s = ss.second;
    bool all=true;
    FORR(c, s) {
      if (cand.count(c)==0) {
        all=false;
        break;
      }
    }
    if (all) {
      ans--;
    }
  }

  FORR(ss, sc) {
    set<int>& s = ss.second;
    bool all=true;
    FORR(c, s) {
      if (cand.count(c)==0) {
        all=false;
        break;
      }
    }
    if (all) {
      ans--;
    }
  }

  _P("%d\n", ans);
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  scanf("%d", &T);
  REP(i, T) {
    _P("Case #%d: ", i+1);
    solve();
  }

  return 0;
}
