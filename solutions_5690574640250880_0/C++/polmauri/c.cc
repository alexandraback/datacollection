#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef vector<string> Vs;

Vs build(int rows, int cols, int mines) {
  int empty = rows*cols - mines;
  Vs res(rows, string(cols, '*'));
  
  if (empty == 1) {
    res[0][0] = 'c';
    return res;
  }
  
  if (rows == 1) {
    for (int i = 0; i < empty; ++i) res[0][i] = '.';
    res[0][0] = 'c';
    return res;
  }
  
  if (cols == 1) {
    for (int i = 0; i < empty; ++i) res[i][0] = '.';
    res[0][0] = 'c';
    return res;
  }
  
  if (rows == 2) {
    if (empty == 2) return Vs();
    if (empty%2 != 0) return Vs();
    for (int i = 0; i < empty/2; ++i) res[0][i] = res[1][i] = '.';
    res[0][0] = 'c';
    return res;
  }
  
  if (cols == 2) {
    if (empty == 2) return Vs();
    if (empty%2 != 0) return Vs();
    for (int i = 0; i < empty/2; ++i) res[i][0] = res[i][1] = '.';
    res[0][0] = 'c';
    return res;
  }
  
  if (empty == 2) return Vs();
  if (empty < 8 and empty%2 != 0) return Vs();
  
  res[0][0] = res[0][1] = res[1][0] = res[1][1] = '.';
  res[0][0] = 'c';
  int p = 4;
  
  if (empty >= 6) {
    res[2][0] = res[2][1] = '.';
    p += 2;
  }
  
  int q1 = min(cols - 2, (empty - p)/2);
  for (int i = 0; i < q1; ++i) {
    res[0][2 + i] = res[1][2 + i] = '.';
    p += 2;
  }
  
  int q2 = min(rows - 3, (empty - p)/2);
  for (int i = 0; i < q2; ++i) {
    res[3 + i][0] = res[3 + i][1] = '.';
    p += 2;
  }
  
  for (int i = 0; i < rows - 2; ++i)
    for (int j = 0; j < cols - 2; ++j)
      if (p < empty) {
        res[2 + i][2 + j] = '.';
        p += 1;
      }
  return res;
}

int main() {
  int tcas;
  cin >> tcas;
  for (int cas = 1; cas <= tcas; ++cas) {
    int r, c, m;
    cin >> r >> c >> m;
    Vs res = build(r, c, m);
    cout << "Case #" << cas << ":" << endl;
    if (res.size() == 0) cout << "Impossible" << endl;
    else {
      for (int i = 0; i < r; ++i)
        cout << res[i] << endl;
    }
  }
}
