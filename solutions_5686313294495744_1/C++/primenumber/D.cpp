#include <bits/stdc++.h>

#define ALL(x)      begin(x),end(x)
#define REP(i,n)    for(int i=0;i<(n);++i)

using namespace std;

class BipartiteMatching {
  int V;
  vector<vector<int>> g;
  vector<int> match;
  vector<bool> used;
  bool dfs(int v) {
    used[v] = true;
    for (int u: g[v]) {
      int w = match[u];
      if (w < 0 || (!used[w] && dfs(w))) {
        match[v] = u; match[u] = v;
        return true;
      }
    }
    return false;
  }
public:
  BipartiteMatching (int v) : V(v), g(v), match(v), used(v) {}
  void add_edge(int u, int v) {
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int maximum_matching(void) {
    int res = 0;
    fill (ALL(match), -1);
    REP(v, V) {
      if (match[v] < 0) {
        fill (ALL(used), 0);
        if (dfs(v)) res++;
      }
    }
    return res;
  }
};

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
    int fs = fst.size();
    int ss = scd.size();
    BipartiteMatching bm(fs + ss);
    REP(i,n) {
      string f,s;
      tie(f,s) = vp[i];
      int fi = lower_bound(begin(fst),end(fst), f) - begin(fst);
      int si = lower_bound(begin(scd),end(scd), s) - begin(scd);
      bm.add_edge(fi, si + fs);
    }
    int res = n - (fs + ss - bm.maximum_matching());
    cout << "Case #" << (cnt+1) << ": " << res << endl;
  }
  return 0;
}
