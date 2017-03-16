#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
 
using namespace std; 

int t, res, n = 4, f[10][2];
char in[5][5];

void check_columns () {
  for (int column = 0; column < 4; column++) {
    for (int i = 0; i < n; i++) {
      if (in[i][column] == 'X' || in[i][column] == 'T') f[column][0]++;
      if (in[i][column] == 'O' || in[i][column] == 'T') f[column][1]++;
    }
  }
}

void check_rows () {
  for (int row = 0; row < 4; row++) {
    for (int i = 0; i < n; i++) {
      if (in[row][i] == 'X' || in[row][i] == 'T') f[row + 4][0]++;
      if (in[row][i] == 'O' || in[row][i] == 'T') f[row + 4][1]++;
    }
  }
}

void check_diagonals () {
  for (int i = 0; i < n; i++) {
    if (in[i][i] == 'X' || in[i][i] == 'T') f[8][0]++;
    if (in[i][i] == 'O' || in[i][i] == 'T') f[8][1]++;
  }
  for (int i = 0; i < n; i++) {
    if (in[i][n - i - 1] == 'X' || in[i][n - i - 1] == 'T') f[9][0]++;
    if (in[i][n - i - 1] == 'O' || in[i][n - i - 1] == 'T') f[9][1]++;
  }
}

bool check_draw () {
  for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (in[i][j] == '.') return false;
  return true;
}

int check () {
  check_columns();
  check_rows();
  check_diagonals();
  for (int i = 0; i < 10; i++) {
    if (f[i][0] == 4) return 1;
    if (f[i][1] == 4) return 2;
  }
  return 0;
}

int main() {
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
  scanf ("%d", &t);
  for (int c = 0; c < t; c++) {
    memset(f, 0, sizeof(f));
    for (int i = 0; i < n; i++) scanf ("%s", &in[i]);
    res = check();
    printf ("Case #%d: ", c + 1);
    if (res == 1) printf ("X won\n");
    if (res == 2) printf ("O won\n");
    if (res == 0) {
      if (check_draw()) printf ("Draw\n"); else printf ("Game has not completed\n");
    }
  }
	return 0;
}