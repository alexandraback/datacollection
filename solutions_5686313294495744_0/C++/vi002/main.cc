#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

int PopCount(unsigned n) {
  int result = 0;
  for (; n != 0; n = n & (n - 1))
    result++;
  return result;
}

int Solve(int n, const vector<pair<string, string>> &topics) {
  int best = 0;
  for (unsigned mask = 0; mask < (1U << n); ++mask) {
    unordered_set<string> first;
    unordered_set<string> second;
    for (unsigned i = 0; i < n; ++i) {
      if ((mask & (1 << i)) == 0) {
        first.insert(topics[i].first);
        second.insert(topics[i].second);
      }
    }
    bool ok = true;
    for (unsigned i = 0; i < n && ok; ++i) {
      if ((mask & (1 << i)) != 0) {
        ok = ok && (first.count(topics[i].first) == 1) &&
             (second.count(topics[i].second) == 1);
      }
    }
    if (ok)
      best = max(best, PopCount(mask));
  }
  return best;
}

int main() {
  int num_tests;
  cin >> num_tests;
  for (int test_num = 0; test_num < num_tests; ++test_num) {
    int n;
    cin >> n;
    vector<pair<string, string>> topics;
    for (int i = 0; i < n; ++i) {
      string a, b;
      cin >> a >> b;
      topics.emplace_back(a, b);
    }
    cout << "Case #" << (test_num + 1) << ": " << Solve(n, topics) << endl;
  }
  return 0;
}
