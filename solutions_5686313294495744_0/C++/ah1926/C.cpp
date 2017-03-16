#include <fstream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

inline int getBit(const int mask, const int bit) {
  return (mask >> bit) & 1;
}

int main() {
  ifstream in("input.txt");
  ofstream out("output.txt");
  int testCount;
  in >> testCount;
  for (int test = 1; test <= testCount; ++test) {
    int n;
    in >> n;
    auto topics = vector<pair<string, string>>(n);
    for (int i = 0; i < n; ++i)
      in >> topics[i].first >> topics[i].second;
    auto dp = vector<int>(1 << n, 0);
    for (int mask = 1; mask < (1 << n); ++mask) {
      for (int last = 0; last < n; ++last) {
        if (getBit(mask, last) == 1) {
          bool foundFirst = false;
          bool foundSecond = false;
          for (int i = 0; i < n; ++i) {
            if (getBit(mask, i) == 1 && i != last) {
              if (topics[i].first == topics[last].first)
                foundFirst = true;
              if (topics[i].second == topics[last].second)
                foundSecond = true;
            }
          }
          dp[mask] = max(dp[mask], dp[mask ^ (1 << last)] + ((foundFirst && foundSecond) ? 1 : 0));
        }
      }
    }
    out << "Case #" << test << ": " << dp[(1 << n) - 1] << "\n";
  }
  in.close();
  out.close();
  return 0;
}
