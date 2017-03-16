#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

vector<string> firsts, seconds;

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    firsts.clear();
    seconds.clear();
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
      string first, second;
      cin >> first >> second;
      firsts.push_back(first);
      seconds.push_back(second);
    }
    int best = 0;
    for (int subset = 1; subset < (1<<N); subset++) {
      int cnt = N;
      unordered_set<string> firstsSet, secondsSet;
      for (int i = 0; i < N; i++) if (subset & (1<<i)) {
        firstsSet.insert(firsts[i]);
        secondsSet.insert(seconds[i]);
        cnt -= 1;
      }
      bool allRight = true;
      for (int i = 0; i < N; i++) if (!(subset & (1<<i))) {
        if (firstsSet.find(firsts[i]) == firstsSet.end() || secondsSet.find(seconds[i]) == secondsSet.end()) {
          allRight = false;
          break;
        }
      }
      if (allRight) best = max(best, cnt);
    }
    cout << "Case #" << t << ": " << best << '\n';
  }
}
