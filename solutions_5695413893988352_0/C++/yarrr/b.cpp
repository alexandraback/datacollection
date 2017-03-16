#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")

#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define all(v) v.begin(), v.end()

using namespace std;
using ll = int64_t;

struct State {
  string a, b;
  ll diff;

  bool operator<(const State& other) const {
    if (diff != other.diff)
      return diff < other.diff;
    if (a != other.a)
      return a < other.a;
    return b < other.b;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int tests;
  cin >> tests;
  for (int test = 0; test < tests; test++) {
    string a, b;
    cin >> a >> b;
    assert(a.size() == b.size());
    reverse(all(a));
    reverse(all(b));
    int n = a.size();

    vector<State> states;
    states.pb(State{"", "", 0});

    for (ll i = 0, p = 1; i < n; i++, p *= 10) {
      vector<State> new_states;

      set<char> good_c0;
      set<char> good_c1;

      for (char c = '0'; c <= '9'; c++) {
        if (a[i] == c || a[i] == '?')
          good_c0.insert(c);
        if (b[i] == c || b[i] == '?')
          good_c1.insert(c);
      }

      for (char c0 : good_c0) {
        for (char c1 : good_c1) {
          ll add = p * (ll(c0) - c1);
          for (auto old : states) {
            old.a = c0 + old.a;
            old.b = c1 + old.b;
            old.diff += add;
            new_states.pb(old);
          }
        }
      }

      sort(all(new_states));
      states.clear();
      assert(!new_states.empty());
      states.pb(new_states[0]);
      int zero_pos = 0;
      for (int i = 1; i < new_states.size(); i++) {
        if (new_states[i].diff != new_states[i - 1].diff)
          states.pb(new_states[i]);
        if (new_states[i].diff >= 0 && new_states[i - 1].diff < 0)
          zero_pos = states.size() - 1;
      }

      constexpr size_t kBuben = 10000;

      vector<State> best;
      set<int> good_ind;
      for (int i = 0; i < min(states.size(), kBuben); i++) {
        good_ind.insert(i);
        good_ind.insert(states.size() - 1 - i);
        if (zero_pos + i < states.size())
          good_ind.insert(zero_pos + i);
        if (zero_pos - i >= 0)
          good_ind.insert(zero_pos - i);
      }

      for (int i : good_ind)
        best.pb(states[i]);

      states = best;

      assert(!states.empty());
    }

    for (auto& x : states)
      x.diff = abs(x.diff);
    sort(all(states));

    auto res = states[0];

    cout << "Case #" << (test + 1) << ": ";
    cout << res.a << " " << res.b << endl;
  }


  return 0;
}
