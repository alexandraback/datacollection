#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

string grid[4];

char win(string s) {
  for (char x = 'O'; x <= 'X'; x += 'X'-'O') {
    bool ok = true;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] != x && s[i] != 'T') {
        ok = false;
      }
    }
    if (ok) return x;
  }
  return 0;
}

int main()
{
  int T; cin >> T;
  for (int tt = 1; tt <= T; tt++) {
    for (int i = 0; i < 4; i++) {
      cin >> grid[i];
    }
    
    bool full = true;
    char winner = 0;
    for (int i = 0; i < 4; i++) {
      if (!winner) winner = win(grid[i]);
      if (!winner) winner = win(string("") + grid[0][i] + grid[1][i] + grid[2][i] + grid[3][i]);
      if (grid[i].find('.') != -1) full = false;
    }
    if (!winner) winner = win(string("") + grid[0][0] + grid[1][1] + grid[2][2] + grid[3][3]);
    if (!winner) winner = win(string("") + grid[0][3] + grid[1][2] + grid[2][1] + grid[3][0]);
    printf("Case #%d: ", tt);
    if (winner) {
      printf("%c won\n", winner);
    } else if (!full) {
      puts("Game has not completed");
    } else {
      puts("Draw");
    }
  }
}