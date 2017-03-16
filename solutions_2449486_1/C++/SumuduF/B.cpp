#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> VI;

bool mowable(int n, int m, const vector<VI> &lawn) {
  VI rowMax(n), colMax(m);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      rowMax[i] = max(rowMax[i], lawn[i][j]);
      colMax[j] = max(colMax[j], lawn[i][j]);
      }

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if ((lawn[i][j] < rowMax[i]) && (lawn[i][j] < colMax[j]))
        return false;
  return true;
  }

int main() {
  int nc; cin >> nc;
  for (int curC = 1; curC <= nc; ++curC) {
    int n, m; cin >> n >> m;

    vector<VI> lawn(n, VI(m));
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        cin >> lawn[i][j];

    cout << "Case #" << curC << ": ";
    if (mowable(n, m, lawn))
      cout << "YES\n";
    else
      cout << "NO\n";
    }
  }

