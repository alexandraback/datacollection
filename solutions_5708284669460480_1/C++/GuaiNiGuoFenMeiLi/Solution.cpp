#include <bits/stdc++.h>

using namespace std;

void construct(string &s, int *p) {
  int n = s.size();
  p[0] = -1;
  int j = -1;
  for (int i = 1; i < n; ++i) {
    while (j != -1 && s[j + 1] != s[i]) {
      j = p[j];
    }
    if(s[j + 1] == s[i]) {
      ++j;
    }
    p[i] = j;
  }
}

int T, K, L, S, next[100];
double g[26], f[2][101][101], sum[101];
string keyboard, target;


int main() {

  freopen("B-large.in", "r", stdin);
  freopen("B-large.out", "w", stdout);

  cin >> T;
  for (int test = 1; test <= T; ++test) {
    cin >> K >> L >> S >> keyboard >> target;
    memset(g, 0x00, sizeof(g));
    for (int i = 0; i < (int)keyboard.size(); ++i)
      g[keyboard[i] - 'A'] += 1;
    for (int i = 0; i < 26; ++i)
      g[i] /= (double)keyboard.size();
    construct(target, next);
    int x = 0, y = 1;
    memset(f[x], 0x00, sizeof(f[x]));
    f[x][0][0] = 1;
    for (int i = 0; i < S; ++i, swap(x, y)) {
      memset(f[y], 0x00, sizeof(f[y]));
      for (int j = 0; j <= 100; ++j)
        for (int k = 0; k < L; ++k)
          for (int ch = 0; ch < 26; ++ch) {
            int pos = k - 1, cnt = j;
            while (pos != -1 && target[pos + 1] != 'A' + ch)
              pos = next[pos];
            if (target[pos + 1] == 'A' + ch)
              ++pos;
            if (pos == L - 1) {
              ++cnt;
              pos = next[pos];
            }
            f[y][cnt][pos + 1] += g[ch] * f[x][j][k];
          }
    }
    int value;
    for (int i = 0; i <= 100; ++i) {
      sum[i] = 0;
      for (int j = 0; j < L; ++j)
        sum[i] += f[x][i][j];
      if (sum[i]) value = i;
    }
    double result = 0;
    for (int i = 0; i <= 100; ++i) {
      result += sum[i] * (value - i);
    }
    printf("Case #%d: %.15lf\n", test, result);
  }
  return 0;
}
