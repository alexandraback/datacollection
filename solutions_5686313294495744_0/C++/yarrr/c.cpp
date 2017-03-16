#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")

#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define all(v) v.begin(), v.end()

using namespace std;
using ll = int64_t;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int tests;
  cin >> tests;
  for (int test = 0; test < tests; test++) {

    int n;
    cin >> n;

    vector<pair<string,string>> in(n);
    vector<string> x(n), y(n);
    for (int i = 0; i < n; i++) {
      cin >> in[i].fi >> in[i].se;
      x[i] = in[i].fi;
      y[i] = in[i].se;
    }
    sort(all(x)); sort(all(y));

    vector<pair<int,int>> good(n);
    for (int i = 0; i < n; i++) {
      good[i].fi = distance(x.begin(), lower_bound(all(x), in[i].fi));
      good[i].se = distance(y.begin(), lower_bound(all(y), in[i].se));
    }

    vector<int> reses(1 << n, 0);
    for (int mask = 0; mask < (1 << n); mask++) {
      for (int add = 0; add < n; add++) {
        if (((mask >> add) & 1) == 0) {
          int new_mask = mask | (1 << add);
          int new_res = reses[mask];
          bool a = false, b = false;
          for (int other = 0; other < n; other++) {
            if ((mask >> other) & 1) {
              a |= good[other].fi == good[add].fi;
              b |= good[other].se == good[add].se;
            }
          }
          new_res += (a && b);
          reses[new_mask] = max(reses[new_mask], new_res);
        }
      }
    }


    int res = reses[(1 << n) - 1];

    cout << "Case #" << (test + 1) << ": ";
    cout << res << endl;
  }

  return 0;
}
