
#include <stdio.h>
#include <iostream>
using namespace std;

char board[4][5];
int boardi[4][4];

bool done () {
    for (int i = 0; i < 4; ++i) for (int j = 0; j < 4; ++j) if (board[i][j] == '.') return false;
    return true;
}

//  0: nothing
// -4: X
//  4: O

int result (int a, int b, int c, int d) {
    int r[] = { 0, 0, 0, 0 };
    r[a]++; r[b]++; r[c]++; r[d]++;
    if (r[0]+r[2] == 4) return -1;
    if (r[1]+r[2] == 4) return 1;
    return 0;
}

int row (int i) { return result( boardi[i][0], boardi[i][1], boardi[i][2], boardi[i][3]); }
int col (int i) { return result( boardi[0][i], boardi[1][i], boardi[2][i], boardi[3][i]); }

int d1 () { return result(boardi[0][3], boardi[1][2], boardi[2][1], boardi[3][0]); }
int d2 () { return result(boardi[0][0], boardi[1][1], boardi[2][2], boardi[3][3]); }

int find() {
    int r;
    r = d1(); if (r) return r;
    r = d2(); if (r) return r;
    for (int i = 0; i < 4; ++i) {
        r = row(i); if (r) return r;
        r = col(i); if (r) return r;
    }
    return 0;
}

void solve (int CASE)
{
    cin >> board[0];
    cin >> board[1];
    cin >> board[2];
    cin >> board[3];

    for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) {
        switch (board[i][j]) {
            case 'X': boardi[i][j] = 0; break;
            case 'O': boardi[i][j] = 1; break;
            case 'T': boardi[i][j] = 2; break;
            case '.': boardi[i][j] = 3; break;
        }
    }

    int r = find();
    switch (find()) {
        case 0:
          if (done()) printf("Case #%d: Draw\n", CASE);
          else printf("Case #%d: Game has not completed\n", CASE);
          break;
        case -1: printf("Case #%d: X won\n", CASE); break;
        case 1: printf("Case #%d: O won\n", CASE); break;
    }
}

int main ()
{
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) solve(i);
  return 0;
}

