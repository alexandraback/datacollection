#include <iostream>
#include <vector>

using namespace std;

void solveCase(int tc) {
  int smax;
  string s;
  cin >> smax;
  cin >> s;
  int have = 0;
  int answer = 0;
  for (size_t i = 0; i < s.size(); ++i) {
    int cur = s[i] - '0';
    int need = i;
    if (have < need) {
      answer += need - have;
      have = need;
    }
    have += cur;
  }
  cout << "Case #" << (tc + 1) << ": " << answer << endl;
  cerr << "Case #" << (tc + 1) << ": " << answer << endl;
}

//#define NAME "A-small-attempt0"
#define NAME "A-large"

int main() {
  freopen(NAME".in", "rt", stdin);
  freopen(NAME".out", "wt", stdout);
  int T;
  cin >> T;
  for (int i = 0; i < T; i++) {
    solveCase(i);
  }
  return 0;
}
