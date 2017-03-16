#include <iostream>
#include <string>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

namespace {

int Solve(vector<pair<string, string>> topics) {
  const int N = topics.size();
  int res = 0;
  for (int i = 1; i < (1 << N); ++i) {
    unordered_set<string> first;
    unordered_set<string> second;
    for (int j = 0; j < N; ++j) {
      if ((i >> j) & 1) {
        first.insert(topics[j].first);
        second.insert(topics[j].second);
      }
    }
    bool ok = true;
    for (int j = 0; j < N; ++j) {
      if ((i >> j) & 1) continue;
      if (first.count(topics[j].first) == 0 ||
          second.count(topics[j].second) == 0) {
        ok = false;
        break;
      }
    }
    if (ok) {
      res = max(res, N - __builtin_popcount(i));
    }
  }
  return res;
}

}

int main(void) {
  int T;
  cin >> T;
  for (int i = 1; i <= T; ++i) {
    int N;
    cin >> N;
    vector<pair<string, string>> topics(N);
    for (int j = 0; j < N; ++j) {
      cin >> topics[j].first >> topics[j].second;
    }
    cout << "Case #" << i << ": " << Solve(topics) << endl;
  }

  return 0;
}
