#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 16;

int f[1 << MAX_N];

string topics[MAX_N][2];

bool are_equal[MAX_N][MAX_N][2];

void solve(int case_id) {
  int n; cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> topics[i][0] >> topics[i][1];
  }

  memset(are_equal, false, sizeof(are_equal));
  memset(f, 0, sizeof(f));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) {
        continue;
      }

      for (int k = 0; k < 2; k++) {
        if (topics[i][k] == topics[j][k]) {
          are_equal[i][j][k] = true;
        }
      }
    }
  }

  for (int mask = 0; mask + 1 < (1 << n); mask++) {
    for (int i = 0; i < n; i++) {
      if (mask & (1 << i)) {
        continue;
      }

      bool flag_a = false;
      bool flag_b = false;

      for (int j = 0; j < n; j++) {
        if (mask & (1 << j)) {
          flag_a |= are_equal[i][j][0];
          flag_b |= are_equal[i][j][1];
        }
      }

      f[mask ^ (1 << i)] = max(f[mask ^ (1 << i)], f[mask] + (flag_a && flag_b));
    }
  }

  cout << "Case #" << case_id << ": " << f[(1 << n) - 1] << "\n";
}

int main() {
  int cases; cin >> cases;

  for (int i = 1; i <= cases; i++) {
    solve(i);
  }

  return 0;
}