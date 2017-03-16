#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <limits>
#include <numeric>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define MP make_pair
#define all(v) (v).begin(), (v).end()

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<bool> vb;
typedef long long ll;
typedef pair<int, int> pii;

#define PROBLEM_ID "B"

int main() {
  freopen(PROBLEM_ID".in", "r", stdin);
  freopen(PROBLEM_ID".out", "w", stdout);
  int test_count;
  cin >> test_count;
  for (int test_index = 0; test_index < test_count; ++test_index) {    
    int rows, cols;
    cin >> rows >> cols;
    vvi field(rows, vi(cols));
    for (int row = 0; row < rows; ++row) {
      for (int col = 0; col < cols; ++col) {
        cin >> field[row][col];
      }
    }
    vector<int> row_max(rows), col_max(cols);
    for (int row = 0; row < rows; ++row) {
      row_max[row] = *std::max_element(field[row].begin(), field[row].end());
    }
    for (int col = 0; col < cols; ++col) {
      col_max[col] = field[0][col];
      for (int row = 1; row < rows; ++row) {
        col_max[col] = max(col_max[col], field[row][col]);
      }
    }
    bool ok = true;
    for (int row = 0; row < rows; ++row) {
      for (int col = 0; col < cols; ++col) {
        if (field[row][col] != min(row_max[row], col_max[col])) {
          ok = false;
          break;
        }
      }
    }
    cout << "Case #" << test_index + 1 << ": ";
    if (ok) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
