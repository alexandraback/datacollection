#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

const int ALPH_SIZE = 26;
const long double eps = 1e-9;
const int LIM = 102;

long double p[ALPH_SIZE];
long double dp[LIM][LIM][LIM];

int get_max(string& s, int k) {
  int res = 0;
  string r = "";
  for (int i = 0; i < k; ++i)
    r += " ";
  for (int i = 0; i < (int) s.length(); ++i)
    r[i] = s[i];
  ++res;
  for (int i = 1; i < k; ++i) {
    bool f = true;
    for (int j = 0; j < (int) s.length(); ++j)
      if (!(i + j < k && (r[i + j] == ' ' || r[i + j] == s[j])))
        f = false;
    if (!f)
      continue;
    for (int j = 0; j < (int) s.length(); ++j)
      r[i + j] = s[j];
    ++res;
  }
  return res;
}

int check(string& a, string& b) {
  for (int i = 0; i < (int) b.length(); ++i) {
    bool res = true;
    for (int j = 0; i + j < (int) b.length(); ++j)
      res &= (a[j] == b[i + j]);
    if (res)
      return b.length() - i;
  }
  return 0;
}

int main() {
  ofstream cout("B.out");
  ifstream cin("B-small-attempt0(1).in");
  cout << fixed << setprecision(7);
  int tests;
  cin >> tests;
  for (int test = 1; test <= tests; ++test) {
    int k = 0, l = 0, s = 0;
    string s1, s2;
    cin >> k >> l >> s >> s1 >> s2;
    fill(p, p + ALPH_SIZE, 0.0);
    for (int i = 0; i < k; ++i)
      p[s1[i] - 'A'] += 1.0 / (long double) k;
    int flag = true;
    for (int i = 0; i < l; ++i)
      if (p[s2[i] - 'A'] < eps)
        flag = false;
    if (!flag || l > s) {
      cout << "Case #" << test << ": 0.0\n";
      continue;
    }
    long double max_ban = get_max(s2, s);
    for (int i = 0; i < LIM; ++i)
      for (int j = 0; j < LIM; ++j)
        for (int k = 0; k < LIM; ++k)
          dp[i][j][k] = 0.0;
    dp[0][0][0] = 1.0;
    string nw;
    for (int i = 0; i < s; ++i)
      for (int j = 0; j < l + 1; ++j)
        for (int kk = 0; kk <= i; ++kk)
          for (int symb = 0; symb < ALPH_SIZE; ++symb) {
            nw = "";
            if (j == l) {
              for (int q = 1; q < j; ++q)
                nw += s2[q];
            } else {
              for (int q = 0; q < j; ++q)
                nw += s2[q];
            }
            nw += ('A' + symb);
            int nj = check(s2, nw);
            int nk = kk;
            if (nj == l)
              ++nk;
            dp[i + 1][nj][nk] += p[symb] * dp[i][j][kk];
          }
    long double mo = 0.0;
    for (int kk = 1; kk <= s; ++kk) {
      long double pr = 0.0;
      for (int j = 0; j < l + 1; ++j)
        pr += dp[s][j][kk];
      mo += ((long double) kk) * pr;
    }
    cout << "Case #" << test << ": " << max_ban - mo << '\n';
  }
  return 0;
}
