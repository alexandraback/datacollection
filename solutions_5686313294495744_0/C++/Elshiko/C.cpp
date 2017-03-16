#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

inline bool bit(int mask, int b) {
  return (mask >> b) & 1;
}

int main() {
  int tests;
  cin >> tests;
  for (int test = 0; test < tests; ++test) {
    int n;
    int ans = 20;
    cin >> n;
    vector<pair<string, string>> v(n);
    for (int i = 0; i < n; ++i)
      cin >> v[i].first >> v[i].second;

    for (uint32_t mask = 0; mask < (1u << n); ++mask) {
      unordered_set<string> fst, snd;
      for (int i = 0; i < n; ++i)
        if (bit(mask, i)) {
          fst.insert(v[i].first);
          snd.insert(v[i].second);
        }
      bool ok = true;
      for (int i = 0; i < n; ++i)
        if (!bit(mask, i) && (fst.find(v[i].first) == fst.end() || snd.find(v[i].second) == snd.end()))
          ok = false;
      if (ok)
        ans = min(ans, __builtin_popcount(mask));
    }
    cout << "Case #" << test + 1 << ": " << n - ans << endl;
  }

  return 0;
}
