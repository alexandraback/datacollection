#include <algorithm>
#include <iostream>
#include <random>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

namespace {

int Solve(vector<pair<string, string>> topics) {
  const int N = topics.size();
  unordered_map<string, int> map_first;
  unordered_map<string, int> map_second;
  for (int i = 0; i < N; ++i) {
    if (map_first.count(topics[i].first) == 0) {
      int id = map_first.size();
      map_first[topics[i].first] = id;
    }
    if (map_second.count(topics[i].second) == 0) {
      int id = map_second.size();
      map_second[topics[i].second] = id;
    }
  }

  vector<pair<int, int>> top;
  for (int i = 0; i < N; ++i) {
    top.emplace_back(map_first[topics[i].first], map_second[topics[i].second]);
  }
  vector<int> count_first(map_first.size());
  vector<int> count_second(map_second.size());
  for (int i = 0; i < N; ++i) {
    ++count_first[top[i].first];
    ++count_second[top[i].second];
  }
  for (int& c : count_first) --c;
  for (int& c : count_second) --c;

  auto rng = mt19937();
  int res = 0;
  for (int r = 0; r < 100000; ++r) {
    shuffle(top.begin(), top.end(), rng);
    vector<int> c1(count_first.size());
    vector<int> c2(count_second.size());
    int count = 0;
    for (int i = 0; i < N; ++i) {
      int f = top[i].first;
      int s = top[i].second;
      if (c1[f] < count_first[f] && c2[s] < count_second[s]) {
        ++count;
        ++c1[f];
        ++c2[s];
      }
    }
    res = max(res, count);
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
