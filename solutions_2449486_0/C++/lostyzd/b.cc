#include <iostream>


int main() {
  int T;
  std::cin >> T;
  for (int tt = 1; tt <= T; ++tt) {
    int n, m;
    std::cin >> n >> m;

    int a[100][100];
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        std::cin >> a[i][j];


    bool flag = true;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        bool ok = true;
        for (int ii = 0; ii < n; ++ii) {
          if (ii != i && a[ii][j] > a[i][j]) {
            ok = false;
            break;
          }
        }

        if (ok) continue;

        ok = true;
        for (int jj = 0; jj < m; ++jj) {
          if (jj != j && a[i][jj] > a[i][j]) {
            ok = false;
            break;
          }
        }
        if (ok == false) {
          flag = false;
          i = 102;
          break;
        }
      }
    }

    std::cout << "Case #" << tt << ": ";
    if (flag) {
      std::cout << "YES\n";
    } else {
      std::cout << "NO\n";
    }
  }
}
