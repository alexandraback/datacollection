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
  long long a[21];
  int M, R, C, P;
  int i, j, ii, jj;
 
bool can_constr() {
  ii = 0;
  jj = 0;
  for (i = 2; i <= R; ++i) {
    for (j = 2; j <= C; ++j) {
      if (P == i * j) {
        return true;
      }
      if (j != C) {
        for (jj = 2; jj < i; ++jj) {
          if (P == i * j + jj) {
            return true;
          }
        }
        jj = 0;
      }
      if (i != R) {
        for (ii = 2; ii <= j; ++ii) {
          if (P == i * j + ii) {
            return true;
          }
          if (j != C) {
            for (jj = 2; jj < i; ++jj) {
              if (P == i * j + ii + jj) {
                return true;
              }
            }
            jj = 0;
          }
        }
        ii = 0;
      }
    }
  }
  return false;
}


int main() {
  freopen("input", "r", stdin);
  freopen("output", "w", stdout);
  std::ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    cin >> R >> C >> M;
    P = R * C - M;
    cout << "Case #" << t << ": \n";
    if (R == 1 || C == 1 || M == 0 || P == 1) {
      bool start = false;
      for (int i = 0; i < R; ++i) {
        for ( int j = 0; j < C; ++j) {
          if (start) {
            if (P > 0)
              cout << '.';
            else
              cout << '*';
          } else {
            cout << 'c';
            start = true;
          }
          P--;
        }
        cout << "\n";
      }
    } else {
      if (can_constr()) {
        bool start = false;
        for (int x = 0; x < R; ++x) {
          for ( int y = 0; y < C; ++y) {
            if (start) {
              if ((x < i && y < j) || (x == i && y < ii) ||
                  (x < jj && y == j))
                cout << '.';
              else
                cout << '*';
            } else {
              cout << 'c';
              start = true;
            }
          }
          cout << "\n";
        }
      } else {
        cout << "Impossible\n";
      }
    }
  }
}
