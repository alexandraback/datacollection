#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cmath>
#include <queue>
#include <ctime>
#pragma comment(linker, "/STACK:256000000")

using namespace std;

long long dp[50][2][2][2];

vector <int> get_digs(int val) {
  vector <int> ret;
  while (val > 0) {
    ret.push_back(val % 2);
    val /= 2;
  }
  return ret;
}

long long solve(int a, int b, int k) {
  --a, --b, --k;
  if (a == 0 || b == 0) {
    return (a + 1) * (b + 1);
  }
  memset(dp, 0, sizeof(dp));
  vector <int> digsk = get_digs(k);
  vector <int> digsa = get_digs(a);
  vector <int> digsb = get_digs(b);  

  int clen = max(digsa.size(), max(digsb.size(), digsk.size()));
  while (digsk.size() < clen) digsk.push_back(0);
  while (digsa.size() < clen) digsa.push_back(0);
  while (digsb.size() < clen) digsb.push_back(0);

  reverse(digsk.begin(), digsk.end());
  reverse(digsa.begin(), digsa.end());
  reverse(digsb.begin(), digsb.end());

  dp[0][1][1][1] = 1;
  for (int i = 0; i < clen; ++i) {
    for (int aa = 0; aa < 2; ++aa) {
      for (int bb = 0; bb < 2; ++bb) {
        for (int kk = 0; kk < 2; ++kk) {
          long long val = dp[i][aa][bb][kk];

          for (int d1 = 0; d1 < 2; ++d1) {
            for (int d2 = 0; d2 < 2; ++d2) {
              if (aa && d1 > digsa[i]) continue;
              if (bb && d2 > digsb[i]) continue;
              if (kk && (d1 & d2) > digsk[i]) continue;

              int na = 0;
              int nb = 0;
              int nc = 0;
              if (aa && d1 == digsa[i]) na = 1;
              if (bb && d2 == digsb[i]) nb = 1;
              if (kk && (d1 & d2) == digsk[i]) nc = 1;
              dp[i + 1][na][nb][nc] += dp[i][aa][bb][kk];
            }
          }
        }
      }
    }
  }

  long long res = 0;
  for (int aa = 0; aa < 2; ++aa) {
    for (int bb = 0; bb < 2; ++bb) {
      for (int kk = 0; kk < 2; ++kk) {
        res += dp[clen][aa][bb][kk];
      }
    }
  }
  return res;
}

void solve(int tcase) {
  printf("Case #%d: ", tcase);

  int a, b, k;
  cin >> a >> b >> k;

  cout << solve(a, b, k) << endl;
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int t;
  scanf("%d", &t);

  for (int i = 0; i < t; ++i) {
    solve(i + 1);
    cerr << i + 1 << endl;
  }

  return 0;
}
