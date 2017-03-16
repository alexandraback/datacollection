#include <iostream>
using namespace std;

void dump(char a[4][4]) {
  for (int y = 0; y < 4; y++) {
    for (int x = 0; x < 4; x++) {
      cout << a[y][x];
    }
    cout << endl;
  }
}

bool horizontal(char a[4][4], char p) {
  int x, y;
  // dump(a);
  for (y = 0; y < 4; y++) {
    for (x = 0; x < 4; x++) {
      if (a[y][x] != p) break;
    }
    if (x == 4) return true;
  }
  return false;
}

bool vertical(char a[4][4], char p) {
  int x, y;
  for (x = 0; x < 4; x++) {
    for (y = 0; y < 4; y++) {
      if (a[y][x] != p) break;
    }
    if (y == 4) return true;
  }
  return false;
}

bool diagonal(char a[4][4], char p) {
  int i;
  for (i = 0; i < 4; i++) {
    if (a[i][i] != p) break;
  }
  if (i == 4) return true;

  for (i = 0; i < 4; i++) {
    if (a[3-i][i] != p) break;
  }
  if (i == 4) return true;

  return false;
}

bool win(char a[4][4], char p) {
  int yt = -1;
  int xt = -1;
  for (int y = 0; y < 4; y++) {
    for (int x = 0; x < 4; x++) {
      if (a[y][x] == 'T') {
	a[y][x] = p;
	yt = y;
	xt = x;
      }
    }
  }

  bool win = horizontal(a, p) || vertical(a, p) || diagonal(a, p);
  
  if (yt >= 0) a[yt][xt] = 'T';

  return win;
}

bool full(char a[4][4]) {
  for (int y = 0; y < 4; y++) {
    for (int x = 0; x < 4; x++) {
      if (a[y][x] == '.') return false;
    }
  }
  return true;
}

string solve(char a[4][4]) {
  if (win(a, 'X')) return "X won";
  if (win(a, 'O')) return "O won";
  if (full(a)) return "Draw";
  return "Game has not completed";
}

int main() {
  int cases;
  char a[4][4];
  cin >> cases;
  for (int i = 1; i <= cases; i++) {
    for (int y = 0; y < 4; y++) {
      for (int x = 0; x < 4; x++) {
	cin >> a[y][x];
      }
    }
    string ans = solve(a);
    printf("Case #%d: %s\n", i, ans.c_str());
  }
  return 0;
}
