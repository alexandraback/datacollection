#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

const int mod = 1e9+7;

int N;

bool precheck(const vector<string> & vs) {
  for (char c = 'a'; c <= 'z'; ++c) {
    int begin = 0, end = 0;
    int middle = 0, all = 0;
    for (int i = 0; i < N; ++i) {
      int now = 0;
      int nowb = 0, nowe = 0;
      bool prev = false;
      for (int j = 0; j < int(vs[i].size()); ++j) {
        if (vs[i][j] == c) {
          if (now and !prev) return false;
          if (j == 0) ++nowb;
          if (j+1 == int(vs[i].size())) ++nowe;
          ++now;
          prev = true;
        }
        else prev = false;
      }
      if (nowb and nowe) ++all;
      else if (nowb) ++begin;
      else if (nowe) ++end;
      else if (now) ++middle;
    }
    
    if ((middle and (begin or end or all)) or middle > 1) return false;
    if (begin > 1 or end > 1) return false;
  }
  return true;
} 

//returns true if valid, false otherwise
bool dfs(int u, vector<bool> vis, const vector<vector<int> > & G) {
  if (vis[u]) return false;
  vis[u] = true;
  for (int i = 0; i < int(G[u].size()); ++i) {
    int v = G[u][i];
    if (!dfs(v, vis, G)) return false;
  }
  return true;
}

bool check2(const vector<string> & vs) {
  vector<vector<int> > G(N);
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) if (i != j) {
      if (vs[i][vs[i].size()-1] != vs[i][0]) {
        if (vs[i][vs[i].size()-1] == vs[j][0])
          G[i].push_back(j);
      }
    }
  }
  //check cycles
  vector<bool> vis;
  for (int i = 0; i < N; ++i) {
    vis = vector<bool>(N, false);
    //valid?
    if (!dfs(i, vis, G)) return false;
  } 
  return true; 
}

int fact(int n) {
  ll ans = 1;
  for (int i = 2; i <= n; ++i) {
    ans = (ans*i)%mod;
  }
  return ans%mod;
}

int calc(const vector<string> & vs) {
  int ans = 1;
  for (char c = 'a'; c <= 'z'; ++c) {
    int t = 0;
    for (int i = 0; i < N; ++i) {
      if (vs[i][0] == c and vs[i][vs[i].size()-1] == c)
        ++t;
    }
    ans = (ll(ans)*ll(fact(t)))%mod;
  }
  
  
  vector<bool> used(26, false);
  for (int i = 0; i < N; ++i) {
    used[vs[i][0]-'a'] = true;
  }
  
  int noreq = 0;
  
  for (char c = 'a'; c <= 'z'; ++c) {
    if (used[c-'a']) { 
      bool reqs = false;
      for (int i = 0; i < N; ++i) {
        if (vs[i][0] == c) {
          char x = vs[i][vs[i].size()-1];
          if (c != x and used[x-'a']) reqs = true;
      
        }
      }
      if (!reqs) ++noreq;
    }
  }
  
  ans = (ll(ans)*ll(fact(noreq)))%mod;

  return ans;
}


int main() {
  int T; cin >> T;
  int ncase = 0;
  while (T--) {
    cin >> N;
    vector<string> vs(N);
    for (int i = 0; i < N; ++i)
      cin >> vs[i];
    
    bool pos = (precheck(vs) and check2(vs));
    
    
    int ans = 0;
    if (pos) {
      ans = calc(vs);
    }

    cout << "Case #" << ++ncase << ": " << ans << endl;

  }
}