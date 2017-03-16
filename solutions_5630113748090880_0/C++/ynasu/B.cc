#include <iostream>
#include <map>
#include <vector>

using namespace std;

namespace {

vector<int> Solve(vector<vector<int>> lines) {
  map<int, int> counts;
  for (const auto& line : lines) {
    for (auto h : line) ++counts[h];
  }
  vector<int> res;
  for (const auto& c : counts) {
    if (c.second & 1) res.push_back(c.first);
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
    vector<vector<int>> lines(2 * N - 1);
    for (int j = 0; j < lines.size(); ++j) {
      for (int k = 0; k < N; ++k) {
        int h;
        cin >> h;
        lines[j].push_back(h);
      }
    }
    cout << "Case #" << i << ":";
    for (int h : Solve(lines)) {
      cout << ' ' << h;
    }
    cout << endl;
  }

  return 0;
}
