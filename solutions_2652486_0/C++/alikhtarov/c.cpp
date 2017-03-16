#include <iostream>
#include <map>
#include <tuple>
#include <vector>
#include <functional>
#include <cmath>
#include <cstring>
using namespace std;

int ispr[1000010];

int main() {
  for (int i = 2; i <= 1000000; ++i)
    ispr[i] = 1;

  vector<int> pr;
  for (long long i = 2; i <= 1000000; ++i) {
    if (ispr[i]) {
      pr.push_back(i);
      if (i <= 1000)
        for (long long j = i * i; j <= 1000000; j += i)
          ispr[j] = 0;
    }
  }


  int t, r, n, m, k;
  cin >> t >> r >> n >> m >> k;
  cout << "Case #1:" << endl;
  while (r--) {
    map<int, int> ff;
    for (int i = 0; i < k; ++i) {
      int p;
      cin >> p;
      int j = 0;
      map<int, int> f;
      while (p > 1) {
        while (p > 1 && !(p % pr[j])) {
          ++f[pr[j]];
          p /= pr[j];
        }
        ++j;
      }
      for (auto x : f)
        ff[x.first] = max(ff[x.first], x.second);
    }

    map<pair<map<int, int>, int>, bool> cache;
    function<bool(map<int, int>, int)> dp
      = [&](map<int, int> ff, int rem) -> bool {

      if (cache.find(make_pair(ff, rem)) != cache.end())
        return cache.at(make_pair(ff, rem));

      bool& cc = cache[make_pair(ff, rem)];
      if (!rem) {
        for (auto x : ff)
          if (x.second) return cc = false;
        return cc = true;
      }

      auto fff = ff;
      if (m >= 8 && fff[2] >= 3) {
        fff[2] -= 3; if (dp(fff, rem-1)) return cc = true; }

      fff = ff;
      if (m >= 7 && fff[7]) {
        fff[7] -= 1; if (dp(fff, rem-1)) return cc = true; }

      fff = ff;
      if (m >= 6 && fff[2] && fff[3]) {
        fff[2]--; fff[3]--; if (dp(fff, rem-1)) return cc = true; }

      fff = ff;
      if (m >= 5 && fff[5]) {
        fff[5]--; if (dp(fff, rem-1)) return cc = true; }

      fff = ff;
      if (m >= 4 && fff[2] >= 2) {
        fff[2] -= 2; if (dp(fff, rem-1)) return cc = true; }

      fff = ff;
      if (m >= 3 && fff[3]) {
        fff[3]--; if (dp(fff, rem-1)) return cc = true; }

      fff = ff;
      if (m >= 2 && fff[2]) {
        fff[2]--; if (dp(fff, rem-1)) return cc = true; }

      return cc = false;
    };

    vector<int> digs;
    function<bool(map<int, int>, int)> fill =
      [&](map<int, int> ff, int rem) {
      if (!rem) return true;
      auto fff = ff;
      if (m >= 8 && ff[2] >= 3) {
        fff[2] -= 3;
        if (dp(fff, rem-1)) {
          digs.push_back(8);
          return fill(fff, rem-1);
        }
      }

      fff = ff;
      if (m >= 7 && ff[7]) {
        fff[7] -= 1;
        if (dp(fff, rem-1)) {
          digs.push_back(7);
          return fill(fff, rem-1);
        }
      }

      fff = ff;
      if (m >= 6 && ff[2] && ff[3]) {
        fff[2]--; ff[3]--; if (dp(fff, rem-1)) {
          digs.push_back(6);
          return fill(fff, rem-1);
        }
      }

      fff = ff;
      if (m >= 5 && ff[5]) {
        fff[5]--;
        if (dp(fff, rem-1)) {
          digs.push_back(5);
          return fill(fff, rem - 1);
        }
      }

      fff = ff;
      if (m >= 4 && ff[2] >= 2) {
        fff[2] -= 2;
        if (dp(fff, rem-1)) {
          digs.push_back(4);
          return fill(fff, rem - 1);
        }
      }

      fff = ff;
      if (m >= 3 && ff[3]) {
        fff[3]--;
        if (dp(fff, rem-1)) {
          digs.push_back(3);
          return fill(fff, rem - 1);
        }
      }

      fff = ff;
      if (m >= 2 && ff[2]) {
        fff[2]--;
        if (dp(fff, rem-1)) {
          digs.push_back(2);
          return fill(fff, rem - 1);
        }
      }

      return false;
    };

    fill(ff, n);

    while (digs.size() < n) digs.push_back(2);

    for (auto x : digs)
      cout << x;
    cout << endl;
  }
}
