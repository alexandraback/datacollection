#include <cassert>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solver {
 public:
  void Solve() {
    vector<pair<string, int>> order = {
      {"ZERO", 0},
      {"TWO", 2},
      {"FOUR", 4},
      {"SIX", 6},
      {"EIGHT", 8},
      {"FIVE", 5},
      {"SEVEN", 7},
      {"NINE", 9},
      {"THREE", 3},
      {"ONE", 1}
    };

    std::map<int, int> ans;
    for (auto& e : order) {
      while (Delete(e.first)) {
        if (ans.find(e.second) == ans.end()) {
          ans[e.second] = 0;
        }
        ans[e.second]++;
      }
    }

    std::string output;
    for (auto e : ans) {
      int count = e.second;
      while (count > 0) {
        count--;
        output += '0' + e.first;
      }
    }
    cout << output << endl;
  }

  bool Delete(const std::string& word) {
    auto copy = input;
    for (char c : word) {
      std::size_t found = copy.find(c);
      if (found == std::string::npos) {
        return false;
      }
      copy.erase(found, 1);
    }
    input = copy;
    return true;
  }

  string input;
};

int main() {
  int T;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    Solver solver;
    cout << "Case #" << t + 1 << ": ";
    cin >> solver.input;
    solver.Solve();
  }
}
