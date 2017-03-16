#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <iomanip>
#define MAXN 105

using namespace std;

int k, l, s;
string kb, t;

int pi[MAXN];
void kmpPreprocess(const string &P) {
  int i = 0, j = -1, m = P.size();
  pi[0] = -1;
  while(i < m) {
    while(j>=0 and P[i] != P[j])
      j = pi[j];
    i ++, j++;
    pi[i] = j;
  }
}

typedef long double ld;
ld M[MAXN][MAXN];
ld DP(int i, int j) {
  ld &ans = M[i][j];
  if (ans >= 0)
    return ans;
  if (i == s)
    return ans = 0;
  ans = 0;
  for (char c : kb) {
    int jj = j, q = 0;
    while (jj >= 0 and c != t[jj])
      jj = pi[jj];
    jj++;
    if (jj == l) {
      ++q;
      jj = pi[jj];
    }
    ans += q + DP(i+1, jj);
  }
  ans /= k;
  return ans;
}

bool T[128];

double solve() {
  for (char c : t)
    if (not T[c])
      return 0;
  kmpPreprocess(t);
  for (int i = 0; i <= s; ++i)
    for (int j = 0; j <= s; ++j)
      M[i][j] = -1;
  return 1 + (s - l) / (l-pi[l]) - DP(0, 0);
}

int main() {
  ios::sync_with_stdio(0);
  int tc;
  cin >> tc;
  cout << fixed << setprecision(7);
  for (int cs = 1; cs <= tc; ++cs) {
    cout << "Case #" << cs << ":";
    memset(T, 0, sizeof T);
    cin >> k >> l >> s;
    cin >> kb >> t;
    for (char c : kb)
      T[c] = true;
    cout << ' ' << solve();
    cout << endl;
  }
  return 0;
}
