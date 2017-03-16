#include <bits/stdc++.h>

using namespace std;

void solve(int case_id) {
  int k, c, s; cin >> k >> c >> s;

  cout << "Case #" << case_id << ": ";
  for (int i = 1; i <= s; i++) {
    cout << i << " ";
  }
  cout << "\n";
}

int main() {
  int cases; cin >> cases;

  for (int i = 1; i <= cases; i++) {
    solve(i);
  }

  return 0;
}