#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

void solveCase() {
  int n;
  cin >> n;
  vector<int> cnt(2501, 0);
  for (int i = 0; i < 2*n-1; i++) {
    for (int j = 0; j < n; j++) {
      int a;
      cin >> a;
      cnt[a]++;
    }
  }
  for (int i = 0; i < (int)cnt.size(); i++) {
    if (cnt[i] % 2 == 1) {
      cout << i << " ";
      cerr << i << " ";
    }
  }
}

#define NAME "B-large"
//#define NAME "B-small-attempt0"
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
