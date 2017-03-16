#include <bits/stdc++.h>

using namespace std;

void solveTest() {
  long long n,m;
  cin >> n >> m;
  if ((1LL << (n - 2)) < m) {
    cout << "IMPOSSIBLE\n";
    return;
  }
  cout << "POSSIBLE\n";
  vector<vector<int>> res(n, vector<int>(n));
  for (int i = 1; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      res[i][j] = 1;
    }
  }
  if (m == (1LL << (n-2))) {
    for (int i = 1; i < n; i++) {
      res[0][i] = 1;
    }
  } else {
    for (int i = 0; i < n - 2; i++) {
      if (m & (1LL<<(n-i-3))) {
	res[0][i+1] = 1;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << res[i][j];
    }
    cout << "\n";
  }
}

int main() {
  int tn;
  cin >> tn;
  for (int tc = 0; tc < tn; tc++) {
    cout << "Case #" << (tc+1) << ": ";
    solveTest();
  }
  return 0;
}
