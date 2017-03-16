#pragma comment(linker, "/STACK:256000000")
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <math.h>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;

  long long k, n, m, p;
  string s1, s2; 
  long long a[31], b[31], l[31], r[31], lpl[31], rpl[31], pos[31];
  int M, R, C, P;
  int i, j, ii, jj;
  vector<vector<int> > matr(30);
 
int doing() {
    vector<string> s(n);
    int sum_len = 0;
    for (int i = 0; i < n; ++i) {
      cin >> s[i];
      sum_len += s[i].size();
    }
    int result = 0;
    vector<int> k(n);
    while (sum_len > 0) {
      char cur = s[0][k[0]];
      vector<int> cur_k(n);
      for (int i = 0; i < n; ++i) {
        if (s[i][k[i]] != cur) {
          return -1;
        }
        while (k[i] + cur_k[i] < s[i].size() && s[i][k[i] + cur_k[i]] == cur) {
          cur_k[i]++;
        }
        k[i] += cur_k[i];
        sum_len -= cur_k[i];
      }
      sort(cur_k.begin(), cur_k.end());
      int mediana = cur_k[n/2];
      for (int i = 0; i < n; ++i) {
        result += abs(cur_k[i] - mediana);
      }
    }
    return result;
}

long long nod(long long a, long long b) {
  if (a == 0 || b == 0) {
    return max(a, b);
  } else {
    nod (b % a, a);
  }
}

bool dfs2(int h, int y) {
  if (pos[h] == y) {
    return false;
  }
  pos[h] = y;
  for (int g = 0; g < 30; ++g) {
    if (matr[h][g] == 1) {
     return dfs2(g, y);
    }
  }
  return true;
}

bool dfs(int y) {
  if (pos[y] > 0) {
    return true;
  }
  pos[y] = y;
  for (int h = 0; h < 30; ++h) {
    if (matr[y][h] == 1) {
     return dfs2(h, y);
    }
  }
  return true;
}



int main() {
  freopen("input", "r", stdin);
  freopen("output", "w", stdout);
  std::ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) { 
    cin >> n;
    long long prod = 1;
    vector<string> s(n), d(n), f;
    for (int y = 0; y < 30; ++y) {
      a[y] = 0;
      b[y] = 0;
      l[y] = 0;
      r[y] = 0;
      lpl[y] = 0;
      rpl[y] = 0;
    }
    for (int i = 0; i < n; ++i) {
      cin >> s[i];
    }
    cout << "Case #" << t << ": ";
    for (int i = 0; i < n; ++i) {
      d[i] = s[i][0];
      for (int j = 1; j < s[i].size(); ++j) {
        if (s[i][j] != s[i][j - 1]) {
          d[i] += s[i][j];
        }
      }
      for (int j = 1; j < d[i].size() - 1; ++j) {
        a[int(d[i][j]) - int('a')]++;
      }
      if (d[i].size() == 1) {
        b[int(d[i][0]) - int('a')]++;
      } else {
        f.push_back(d[i]);
      }
    }
    for (int y = 0; y < 30; ++y) {
      int u = 1;
      while (u < b[y]) {
        u++;
        prod *= u;
        prod %= 1000000007;
      }
    }

    for (int i = 0; i < f.size(); ++i) {
      l[int(f[i][0]) - int('a')]++;
      lpl[int(f[i][0]) - int('a')] = i;
      r[int(f[i][f[i].size() - 1]) - int('a')]++;
      rpl[int(f[i][f[i].size() - 1]) - int('a')] = i;
      if (f[i][0] == f[i][f[i].size() - 1]) {
        prod = 0;
      }
    }
    int sizef = f.size();
    for (int y = 0; y < 30; ++y) {
      if (l[y] != 0) {
        b[y] = 0;
        if (r[y] != 0) 
          sizef--;
        if (a[y] != 0) {
          prod = 0;
        }
      } else {
        if (r[y] != 0) {
          b[y] = 0;
          if (a[y] != 0) {
            prod = 0;
          }
        } else {
          if (b[y] != 0) {
            if (a[y] != 0) {
              prod = 0;
            } else {
              sizef++;
            }
          }
        }
      }
      if (l[y] > 1 || r[y] > 1 || a[y] > 1) {
        prod = 0;
      }
    }
    int u = 1;
    if (sizef <= 0) {
      prod = 0;
    }
    while (u < sizef) {
      u++;
      prod *= u;
      prod %= 1000000007;
    }
    if (prod != 0) {
      for (int y = 0; y < 30; ++y) {
        matr[y].resize(30);
        pos[y] = -1;
      }
      for (int i = 0; i < f.size(); ++i) {
        matr[int(f[i][0]) - int('a')][int(f[i][f[i].size() - 1]) - int('a')] = 1;
      }
      for (int y = 0; y < 30; ++y) {
        if (dfs(y) == false) {
          prod = 0;
        }
      }
    }
    cout << prod;
    cout << "\n";
  }
}
