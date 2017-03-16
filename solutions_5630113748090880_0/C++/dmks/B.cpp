#include <vector>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <set>

using namespace std;

void solve() {
  int n;
  cin >> n;
  set<int> s;
  for (int i = 0; i < 2*n - 1; i++) {
    for (int j = 0; j < n; j++) {
      int k;
      cin >> k;
      if (!s.erase(k)) {
        s.insert(k);
      }
    }
  }
  bool first = true;
  for(set<int>::iterator it = s.begin(); it != s.end(); it++) {
    if (!first) {
      cout << ' ';
    }
    first = false;
    cout << *it;
  }
}

int main() {
  int T;
  cin >> T;
  for (int i = 0; i < T; i++) {
    cout << "Case #" << (i+1) << ": ";
    solve();
    cout << endl;
  }
  return 0;
}
