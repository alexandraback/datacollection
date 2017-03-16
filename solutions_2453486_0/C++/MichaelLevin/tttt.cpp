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

int main() {
  freopen("A.txt", "r", stdin);
  freopen("A-out.txt", "w", stdout);
  int test_count;
  cin >> test_count;
  for (int test_index = 0; test_index < test_count; ++test_index) {
    vector<string> field(4);
    for (int i = 0; i < 4; ++i) {
      cin >> field[i];
    }
    bool all_cells = true;
    bool x_won = false;
    bool o_won = false;
    for (int row = 0; row < 4; ++row) {
      bool x_won_here = true;
      bool o_won_here = true;
      for (int col = 0; col < 4; ++col) {
        if (field[row][col] == '.') {
          all_cells = false;
          x_won_here = false;
          o_won_here = false;
        } else if (field[row][col] == 'O') {
          x_won_here = false;
        } else if (field[row][col] == 'X') {
          o_won_here = false;
        }
      }
      if (x_won_here) {
        x_won = true;
      }
      if (o_won_here) {
        o_won = true;
      }
    }
    for (int col = 0; col < 4; ++col) {
      bool x_won_here = true;
      bool o_won_here = true;
      for (int row = 0; row < 4; ++row) {
        if (field[row][col] == '.') {
          all_cells = false;
          x_won_here = false;
          o_won_here = false;
        } else if (field[row][col] == 'O') {
          x_won_here = false;
        } else if (field[row][col] == 'X') {
          o_won_here = false;
        }
      }
      if (x_won_here) {
        x_won = true;
      }
      if (o_won_here) {
        o_won = true;
      }
    }
    bool x_won_here = true;
    bool o_won_here = true;
    for (int row = 0; row < 4; ++row) {
      if (field[row][row] == '.') {
        x_won_here = false;
        o_won_here = false;
      } else if (field[row][row] == 'O') {
        x_won_here = false;
      } else if (field[row][row] == 'X') {
        o_won_here = false;
      }
    }
    if (x_won_here) {
      x_won = true;
    }
    if (o_won_here) {
      o_won = true;
    }
    x_won_here = true;
    o_won_here = true;
    for (int row = 0; row < 4; ++row) {
      if (field[row][3 - row] == '.') {
        x_won_here = false;
        o_won_here = false;
      } else if (field[row][3 - row] == 'O') {
        x_won_here = false;
      } else if (field[row][3 - row] == 'X') {
        o_won_here = false;
      }
    }
    if (x_won_here) {
      x_won = true;
    }
    if (o_won_here) {
      o_won = true;
    }
    cout << "Case #" << test_index + 1 << ": ";
    if (x_won) {
      cout << "X won" << endl;
    } else if (o_won) {
      cout << "O won" << endl;
    } else if (all_cells) {
      cout << "Draw" << endl;
    } else {
      cout << "Game has not completed" << endl;
    }
  }
  return 0;
}
