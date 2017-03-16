#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

void solveCase() {
  string s;
  cin >> s;
  int n = s.size();
  vector<bool> used(n, false);
  int from = n-1;
  string answer;
  for (int i = 'Z'; i >= 'A'; i--) {
    for (int j = from; j >= 0; j--) {
      if (s[j] == i) {
        answer += (char)i;
        from = j-1;
        used[j] = true;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (!used[i]) {
      answer += s[i];
    }
  }
  cout << answer;
  cerr << answer;
}

#define NAME "A-large"
//#define NAME "A-small-attempt0"
//#define NAME "test"

int main() {
  freopen(NAME ".in", "rt", stdin);
  freopen(NAME ".out", "wt", stdout);
  int T;
  cin >> T;
  for (int i = 1; i <= T; i++) {
    cout << "Case #" << i << ": ";
    cerr << "Case #" << i << ": ";
    solveCase();
    cout << endl;
    cerr << endl;
  }
  return 0;
}
