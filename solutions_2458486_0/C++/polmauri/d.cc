#include <iostream>
#include <map>
#include <vector>
using namespace std;

typedef vector<int> Vi;
typedef vector<Vi> Mi;
typedef pair<int, int> P;
typedef vector<P> Vp;
typedef vector<Vp> Mp;

int K, N, M;
Vi init;
Vi open_key;
Mp inside;

map<int, int> key_map;

int T;
int dp[1<<20], tdp[1<<20], next[1<<20];

int fun(int mask) {
  if (mask == (1<<N) - 1) return 1;
  if (tdp[mask] == T) return dp[mask];
  tdp[mask] = T;
  Vi v = init;
  for (int i = 0; (1<<i) <= mask; ++i) {
    if ((mask>>i)&1) {
      --v[open_key[i]];
      for (int j = 0; j < int(inside[i].size()); ++j)
        v[inside[i][j].first] += inside[i][j].second;
    }
  }
  for (int i = 0; i < N; ++i) {
    if ((mask>>i)&1) continue;
    if (v[open_key[i]] and fun(mask | (1<<i))) {
      next[mask] = i;
      return dp[mask] = 1;
    }
  }
  return dp[mask] = 0;
}

Vp convert(Vi v) {
  int n = v.size();
  map<int, int> mp;
  for (int i = 0; i < n; ++i)
    if (key_map.count(v[i]))
      ++mp[key_map[v[i]]];
  return Vp(mp.begin(), mp.end());
}

int main() {
  int tcas;
  cin >> tcas;
  for (int cas = 1; cas <= tcas; ++cas) {
    cin >> K >> N;
    Vi tmp_init(K);
    for (int i = 0; i < K; ++i) cin >> tmp_init[i];
    Vi tmp_open(N);
    Mi tmp_inside(N);
    for (int i = 0; i < N; ++i) {
      cin >> tmp_open[i];
      int k;
      cin >> k;
      tmp_inside[i] = Vi(k);
      for (int j = 0; j < k; ++j) cin >> tmp_inside[i][j];
    }
    
    M = 0;
    key_map.clear();
    for (int i = 0; i < N; ++i) {
      if (key_map.count(tmp_open[i]) == 0)
        key_map[tmp_open[i]] = M++;
    }
    
    init = Vi(M);
    for (int i = 0; i < K; ++i)
      if (key_map.count(tmp_init[i]))
        ++init[key_map[tmp_init[i]]];
    open_key = Vi(N);
    for (int i = 0; i < N; ++i) open_key[i] = key_map[tmp_open[i]];
    inside = Mp(N);
    for (int i = 0; i < N; ++i) inside[i] = convert(tmp_inside[i]);
    
    cout << "Case #" << cas << ":";
    
    ++T;
    if (fun(0)) {
      int mask = 0;
      while (mask != (1<<N) - 1) {
        cout << " " << next[mask] + 1;
        mask |= 1<<next[mask];
      }
      cout << endl;
    }
    else cout << " IMPOSSIBLE" << endl;
  }
}
