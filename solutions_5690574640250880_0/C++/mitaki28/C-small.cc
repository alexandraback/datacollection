#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;


int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int R, C, M;
    bool swapped = false;
    cin >> R >> C >> M;
    if (R > C) {
      swap(R, C);
      swapped = true;
    }
    vector<vector<char>> a(R, vector<char>(C, '.'));
    a[0][0] = 'c';
    if (R == 1) {
      for (int i = 0; i < M; i++) {
        a[0][C - 1 - i] = '*';
      }
    } else if (R == 2) {
      if (M == R * C - 1) {
        a = vector<vector<char>>(R, vector<char>(C, '*'));
        a[0][0] = 'c';
      } else if (M % 2 == 1) {
        a[0][0] = '%';
      } else if (2 * C - M <= 3) {
        a[0][0] = '%';
      } else {
        for (int i = 0; i < M / 2; i++) {
          a[0][C - 1 - i] = a[1][C - 1 - i] = '*';
        }
      }
    } else {
      int p = R - 1;
      while (p >= 3) {
        int q = C - 1;
        while (q >= 0 && M > 0) {
          if (M == 1 && q == 1) {
            a[p - 1][C - 1] = '*';
          } else {
            a[p][q] = '*';
          }
          q--;
          M--;
        }
        if (M == 0) break;
        p--;
      }
      int q = C - 1;
      while (q >= 3 && M >= 3) {
        a[0][q] = a[1][q] = a[2][q] = '*';
        M -= 3;
        q--;
      }
      if (q >= 3) {
        if (M == 1) {
          a[2][q] = '*';
        } else if (M == 2) {
          a[2][q] = a[2][q - 1] = '*';
        } 
      } else {
        if (M == 2 || M == 4 || M == 6 || M == 7) {
          a[0][0] = '%';
        } else {
          if (M >= 1) {
            a[2][2] = '*';
          }
          if (M >= 3) {
            a[2][0] = a[2][1] = '*';
          }
          if (M >= 5) {
            a[0][2] = a[1][2] = '*';
          }
          if (M >= 8) {
            a[0][1] = a[1][0] = a[1][1] = '*';
          }
        }
      }
    }

    vector<vector<char>> r;
    if (swapped) {
      r.resize(C, vector<char>(R));
      for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
          r[j][i] = a[i][j];
        }
      }
    } else {
      r = a;
    }
    printf("Case #%d:\n", t);
    if (a[0][0] == '%') {
      printf("Impossible\n");
    } else {
      for (int i = 0; i < r.size(); i++) {
        for (int j = 0; j < r[0].size(); j++) {
          printf("%c", r[i][j]);
        }
        printf("\n");
      }
    }
  }
}