#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> Vi;
typedef vector<Vi> Mi;

int main() {
  int tcas;
  cin >> tcas;
  for (int cas = 1; cas <= tcas; ++cas) {
    cout << "Case #" << cas << ": ";
    int r, c;
    cin >> r >> c;
    Mi mat(r, Vi(c));
    for (int i = 0; i < r; ++i)
      for (int j = 0; j < c; ++j)
        cin >> mat[i][j];
    Vi row(r, 1), col(c, 1);
    for (int i = 0; i < r; ++i)
      for (int j = 0; j < c; ++ j) {
        row[i] = max(row[i], mat[i][j]);
        col[j] = max(col[j], mat[i][j]);
      }
    bool ok = true;
    for (int i = 0; i < r; ++i)
      for (int j = 0; j < c; ++j)
        if (mat[i][j] != min(row[i], col[j]))
          ok = false;
    if (ok) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
}
