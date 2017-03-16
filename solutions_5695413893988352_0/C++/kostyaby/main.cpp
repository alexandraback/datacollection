#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 20;
const long long INF = (long long) 1e18;

string s, t;

long long f[MAX_N][2];

void upd(long long &a, long long b) {
  if (b == -1) {
    return;
  }

  if (a == -1) {
    a = b;
  }

  a = min(a, b);
}

long long dp(const string &s, const string &t) {
  memset(f, -1, sizeof(f));
  int n = s.size();

  f[0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2; j++) {
      if (f[i][j] == -1) {
        continue;
      }

      for (int p = 0; p < 10; p++) {
        if (s[i] != '?' && s[i] != '0' + p) {
          continue;
        }

        for (int q = 0; q < 10; q++) {
          if (t[i] != '?' && t[i] != '0' + q) {
            continue;
          }

          if (j == 0 && p < q) {
            continue;
          }

          int new_i = i + 1;
          int new_j = (p > q ? 1 : j);
          long long value = f[i][j] * 10 + p - q;

          upd(f[new_i][new_j], value);
        }
      }
    }
  }

  long long result = INF;
  upd(result, f[n][0]);
  upd(result, f[n][1]);

  return result;
}

long long calculate_dp() {
  return min(dp(s, t), dp(t, s));
} 

void solve(int case_id) {
  cin >> s >> t;

  long long minimal_difference = calculate_dp();

  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '?') {
      for (int d = 0; d < 10; d++) {
        s[i] = '0' + d;

        if (calculate_dp() == minimal_difference) {
          break;
        }
      }
    }
  }

  for (int i = 0; i < t.size(); i++) {
    if (t[i] == '?') {
      for (int d = 0; d < 10; d++) {
        t[i] = '0' + d;

        if (calculate_dp() == minimal_difference) {
          break;
        }
      }
    }
  }

  cout << "Case #" << case_id << ": " << s << " " << t << "\n";
}

int main() {
  int cases; cin >> cases;

  for (int i = 1; i <= cases; i++) {
    solve(i);
  }

  return 0;
}