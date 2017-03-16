#include <bits/stdc++.h>

using namespace std;

int bff[1005];
int N;

struct S {
  int operator()(const vector<int> & a, const vector<int> & b) {
    return a.size() > b.size();
  }
};

int solve() {
  int ans = 0;
  vector<set<vector<int>, S>> vs(N, set<vector<int>, S>());

  for (int i = 0; i < N; ++i) {
    int cur = i, prev = -1;
    vector<bool> used(N, false);
    used[cur] = true;
    int ll = 1;
    vector<int> c;
    c.push_back(cur);
    while (!used[bff[cur]]) {
      ++ll;
      prev = cur;
      cur = bff[cur];
      c.push_back(cur);
      used[cur] = true;
    }
    if (prev == bff[cur]) vs[prev].insert(c);
    else {
      ll = 1;
      for (int cc = bff[cur]; cc != cur; cc = bff[cc]) ll++;
    }
    ans = max(ans, ll);
  }
  int ll = 0;
  vector<bool> used(N, false);
  for (int i = 0; i < N; ++i) {
    if (!used[i] && !vs[i].empty()) {
      ll += vs[i].begin()->size();
      if (!vs[bff[i]].empty()) {
        used[bff[i]] = true;
        ll += vs[bff[i]].begin()->size() - 2;
      }
    }
  }
  ans = max(ans, ll);
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int T; cin >> T;
  for (int i = 0; i < T; ++i) {
    cin >> N;

    for (int j = 0; j < N; j++) {
      int x; cin >> x;
      bff[j] = x - 1;
    }

    cout << "Case #" << (i + 1) << ": " << solve() << endl;
  }
  return 0;
}
