#include <iostream>
#include <vector>
using namespace std;

enum {
  VERT = 1,
  NEG_VERT = 2,
  HOL = 3,
  NEG_HOL = 4,
};

bool choose(vector<int> &ans, int diff) {
  if (ans[diff] == 0) {
    ans[diff] = NEG_VERT;
    return true;
  }

  for (int i = diff-1; i > 0; i--) {
    if (ans[i] == 0) {
      ans[i] = NEG_VERT;
      if (choose(ans, diff-i)) {
        return true;
      }
      ans[i] = 0;
    }
  }
  return false;
}

int main(void) {
  int T;
  cin >> T;
  for (int cases = 1; cases <= T; cases++) {
    int x, y;
    bool inv_x = false, inv_y = false;
    cin >> x >> y;
    if (x < 0) {
      inv_x = true; x = -x;
    }
    if (y < 0) {
      inv_y = true; y = -y;
    }

    int sum = x + y;
    int n = 0, n_sum = 0;
    while (n_sum < sum || (n_sum % 2) != (sum % 2)) {
      n++;
      n_sum += n;
    }

    vector<int> ans(n+1, 0);
    int left = n_sum;
    {
      int tmp_x = x, max_n = n;
      while (tmp_x != 0) {
        if (tmp_x > max_n) {
          ans[max_n] = HOL;
          tmp_x -= max_n;
          left -= max_n;
          max_n--;
        } else {
          ans[tmp_x] = HOL;
          left -= tmp_x;
          tmp_x = 0;
        }
      }
    }

    int diff = (left - y) / 2;
    if (diff != 0) {
      choose(ans, diff);
    }

    cout << "Case #" << cases << ": ";
    for (int i = 1 ; i < n+1; i++) {
      if (ans[i] == 0) {
        cout << (inv_y ? 'S' : 'N');
      }
      if (ans[i] == HOL) {
        cout << (inv_x ? 'W' : 'E');
      }
      if (ans[i] == NEG_VERT) {
        cout << (inv_y ? 'N' : 'S');
      }
    }
    cout << endl;
  }
}
