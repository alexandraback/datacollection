#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>

using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
static const double EPS = 1e-9;
static const double PI = acos(-1.0);

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, n) for (int i = (s); i < (int)(n); i++)
#define FOREQ(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define FORIT(it, c) for (__typeof((c).begin())it = (c).begin(); it != (c).end(); it++)
#define MEMSET(v, h) memset((v), h, sizeof(v))

void solve();
int main() {
  int test;
  scanf("%d", &test);
  char str[1000];
  fgets(str, 999, stdin);
  int test_case = 0;
  while (test--) {
    test_case++;
    printf("Case #%d: ", test_case);
    solve();
  }
}

const int n = 4;
char field[100][100];
void solve() {
  int cnt = 0;
  REP(y, n) {
    scanf("%s", field[y]);
    REP(x, n) {
      cnt += field[y][x] == '.';
    }
  }
  int win = -1;
  REP(p, 2) {
    char c = p == 0 ? 'O' : 'X';
    const int sx[4] = { 0, 0, 0, 3 };
    const int sy[4] = { 0, 0, 0, 0 };
    const int dx[4] = { 1, 0, 1, -1 };
    const int dy[4] = { 0, 1, 1, 1 };
    REP(dir, 4) {
      REP(i, n) {
        REP(j, n) {
          int x = sx[dir] + dx[dir] * j;
          int y = sy[dir] + dy[dir] * j;
          if (dir == 0) { y += i; }
          if (dir == 1) { x += i; }
          //cout << x << " " << y << endl;
          assert(0 <= x && x < n);
          assert(0 <= y && y < n);
          if (field[y][x] != c && field[y][x] != 'T') { goto next; }
        }
        win = p;
        goto end;
next:;
      }
    }
  }
end:
  if (win == 0) {
    puts("O won");
  } else if (win == 1) {
    puts("X won");
  } else if (cnt == 0) {
    puts("Draw");
  } else {
    puts("Game has not completed");
  }
}
