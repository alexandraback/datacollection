#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll path_pos(ll k, const vector<ll>& path) {
  ll pos = 0;
  for (int i = 0; i < int(path.size()); ++i) {
    pos *= k;
    pos += path[i];
  }
  return pos;
}

vector<ll> solve(ll k, ll c, ll s) {
  vector<ll> sol;
  vector<ll> cur_path;
  for (ll i = 0; i < k; ++i) {
    if (ll(cur_path.size()) == c) {
      sol.push_back(path_pos(k, cur_path));
      cur_path = vector<ll>();
    }
    cur_path.push_back(i);
  }
  while (ll(cur_path.size()) < c) {
    cur_path.push_back(0);
  }
  sol.push_back(path_pos(k, cur_path));
  return sol;
}

int main() {
  int T;
  cin >> T;
  for (int ca = 1; ca <= T; ++ca) {
    int k, c, s;
    cin >> k >> c >> s;
    cout << "Case #" << ca << ":";
    vector<ll> sol = solve(k, c, s);
    if (int(sol.size()) > s) {
      cout << " IMPOSSIBLE" << endl;
    } else {
      for (int i = 0; i < int(sol.size()); ++i) {
        cout << " " << sol[i] + 1;
      }
      cout << endl;
    }
  }
}
