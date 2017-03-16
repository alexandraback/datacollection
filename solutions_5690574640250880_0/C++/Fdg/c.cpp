/* 
  2014.03.26 15:10
  http://codeforces.ru/gym/100289/
*/


#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <memory.h>
#include <cmath>
#include <string> 
#include <ctime>

using namespace std;

#undef Fdg_Home

char f[55][55];

void solveTest(int CS) {
  printf("Case #%d:\n", CS);
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  // cout << n << " " << m << "   " << k << endl;
  memset(f, 0, sizeof(f));
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      f[i][j] = '.';
  if (n == 4 && m == 4) {

  }
  if (n == 1) {
    for (int i = 0; i < k; ++i)
      f[0][i] = '*';
    f[0][m - 1] = 'c';
    puts(f[0]);
    return;
  }
  if (m == 1) {
    for (int i = 0; i < k; ++i)
      f[i][0] = '*';
    f[n - 1][0] = 'c';
    for (int i = 0; i < n; ++i)
      puts(f[i]);
    return;
  }
  if (k + 1 == n * m) {
    for (int i = 0; i < n; ++i)
      for(int j = 0; j < m; ++j)
        f[i][j] = '*';
    f[0][0] = 'c';
    for (int i = 0; i < n; ++i)
      puts(f[i]);
    return;
  }
  if (k + 4 <= n * m || true) {
    k = n * m - k;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        f[i][j] = '*';
    // while (k > 0) {
    //   for (int i = 0; k > 0 && i < max(n, m); ++i) {
    //     for (int j = 0; k > 0 && j < i; ++j) {
    //       if (i < n && j < m) f[i][j] = '.', --k;
    //       // if (j < n && i < m) f[j][i] = '.', --k;
    //     }
    //     for (int j = 0; k > 0 && j <= i; ++j) {
    //       // if (i < n && j < m) f[i][j] = '.', --k;
    //       if (j < n && i < m) f[j][i] = '.', --k;
    //     }
    //   }
    // }
    for (int r = 2; r <= n; ++r) {
      for (int c = 2; c <= m; ++c) {
        if (r * c <= k && k - (r * c) != 1 && k - (r * c) < (r == n ? r : (c == m ? c : max(r, c)))) {
          // if (r == 1 && k == 2 * c - 1 || c == 1 && k == 2 * r - 1) continue;
          for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
              f[i][j] = '.';
          k -= r * c;
          // cout << r << "  " << c << " " << k << endl; 
          for (int i = 0; i < k; ++i) {
            if (m == c || m != c && c > r) f[r][i] = '.';
            else f[i][c] = '.';
          }
          f[0][0] = 'c';
          for (int i = 0; i < n; ++i)
            puts(f[i]);
          return;
        }
      }
    }
  }
  if (k + 4 <= n * m || true) {
    k = n * m - k;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        f[i][j] = '.';
    // while (k > 0) {
    //   for (int i = 0; k > 0 && i < max(n, m); ++i) {
    //     for (int j = 0; k > 0 && j < i; ++j) {
    //       if (i < n && j < m) f[i][j] = '.', --k;
    //       // if (j < n && i < m) f[j][i] = '.', --k;
    //     }
    //     for (int j = 0; k > 0 && j <= i; ++j) {
    //       // if (i < n && j < m) f[i][j] = '.', --k;
    //       if (j < n && i < m) f[j][i] = '.', --k;
    //     }
    //   }
    // }
    for (int r = 1; 2 + r <= n; ++r) {
      for (int c = 1; 2 + c <= m; ++c) {
        if (r * c <= k && k - (r * c) < (r == n ? r : (c == m ? c : max(r, c)))) {
          // if (r == 1 && k == 2 * c - 1 || c == 1 && k == 2 * r - 1) continue;
          for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
              f[i][j] = '*';
          k -= r * c;
          // cout << r << "  " << c << " " << k << endl; 
          for (int i = 0; i < k; ++i) {
            if (m == c || m != c && c > r) f[r][i] = '*';
            else f[i][c] = '*';
          }
          f[n - 1][m - 1] = 'c';
          for (int i = 0; i < n; ++i)
            puts(f[i]);
          return;
        }
      }
    }
  }
  puts("Impossible");
}

int main() {
#ifndef Fdg_Home
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int T;
  scanf("%d\n", &T);
  for (int test = 1; test <= T; ++test) {
    solveTest(test);
  }
  return 0;
}