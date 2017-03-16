#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<string, string> ps;

vector<ps> v;
map<string, int> M[2];

int solve(int idx, int mask1, int mask2) {
  if (idx == v.size()) {
    if (mask1 == ((1 << M[0].size()) - 1) && mask2 == ((1 << M[1].size()) - 1))
      return 0;
    return v.size();
  }
  int leave = solve(idx + 1, mask1, mask2);
  int take = solve(idx + 1, mask1 | (1 << M[0][v[idx].first]),
      mask2 | (1 << M[1][v[idx].second])) + 1;
  return min(leave, take);
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.in", "r", stdin);
  freopen("in.out", "w", stdout);
#endif
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int T, n;
  cin >> T;
  string s1, s2;

  for (int tt = 1; tt <= T; tt++) {

    v.clear();
    M[0].clear();
    M[1].clear();

    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> s1 >> s2;
      v.push_back(ps(s1, s2));
      if (!M[0].count(s1)) {
        int sz = M[0].size();
        M[0][s1] = sz;
      }
      if (!M[1].count(s2)) {
        int sz = M[1].size();
        M[1][s2] = sz;
      }

    }
    int besti = solve(0, 0, 0);

    cout << "Case #" << tt << ": ";

    cout << v.size() - besti;

    cout << endl;
  }

  return 0;
}
