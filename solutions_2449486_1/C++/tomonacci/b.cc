#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <functional>
#include <queue>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main() {
  int T;
  cin >> T;
  for (int I = 1; I <= T; I++) {
    int N, M, a[100][100], rowmax[100], colmax[100];
    cin >> N >> M;
    for (int i = 0; i < N; i++)
      for (int j = 0; j < M; j++)
        cin >> a[i][j];
    for (int i = 0; i < N; i++) {
      rowmax[i] = a[i][0];
      for (int j = 1; j < M; j++)
        rowmax[i] = max(rowmax[i], a[i][j]);
    }
    for (int j = 0; j < M; j++) {
      colmax[j] = a[0][j];
      for (int i = 0; i < N; i++)
        colmax[j] = max(colmax[j], a[i][j]);
    }
    bool possible = true;
    for (int i = 0; i < N; i++)
      for (int j = 0; j < M; j++)
        if (!(a[i][j] == rowmax[i] || a[i][j] == colmax[j])) {
          possible = false;
          break;
        }
    cout << "Case #" << I << ": " << (possible ? "YES" : "NO") << endl;
  }
  return 0;
}
