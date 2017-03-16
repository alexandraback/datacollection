#include <bits/stdc++.h>

using namespace std;

#define _ << " " <<
#define trace(a) #a << "=" << a
typedef long long ll;
typedef long double ld;

int j, p, s, k;

void solve() {
  cin >> j >> p >> s >> k;
  if (k >= s)
  {
    cout << j * p * s << endl;
    for (int a = 1; a <= j; ++a)
      for (int b = 1; b <= p; ++b)
        for (int c = 1; c <= s; ++c)
          cout << a _ b _ c << endl;
  }
  else
  {
    vector<vector<int>> ans;
    map<pair<int, int>, int> jp, js, ps;
    for (int a = 1; a <= j; ++a)
      for (int b = 1; b <= p; ++b)
        for (int c = 1; c <= s; ++c)
        {
          pair<int,int> x = {a, b}, y = {a, c}, z = {b, c};
          if (jp.find(x) == jp.end())
            jp[x] = 0;
          if (js.find(y) == js.end())
            js[y] = 0;
          if (ps.find(z) == ps.end())
            ps[z] = 0;

          if (jp[x] == k || js[y] == k || ps[z] == k)
            continue;

          ans.push_back({a, b, c});
          ++jp[x]; ++js[y]; ++ps[z];
        }

    cout << ans.size() << endl;
    for (auto &v : ans)
      cout << v[0] _ v[1] _ v[2] << endl;
  }
}

int main() {
  int tcs; cin >> tcs;
  for (int tc = 1; tc <= tcs; ++tc)
  {
    cout << "Case #" << tc << ": ";
    solve();
  }
  return 0;
}

