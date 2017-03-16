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
    printf("Case #%d:", test_case);
    puts("");
    solve();
  }
}

int h, w, n, m;
int field[300][300];
void solve() {
  scanf("%d %d %d", &h, &w, &m);
  n = h * w - m;
  MEMSET(field, 0);
  bool ans = true;
  if (n == 1 || h == 1 || w == 1) { ans = true; }
  else if (n < 4) { ans = false; }
  else if ((h == 2 || w == 2) && n % 2 == 1) { ans = false; }
  else if (n == 5 || n == 7) { ans = false; }
  if (w <= 2) {
    int sum = 0;
    REP(y, h) {
      REP(x, w) {
        field[y][x] = 1;
        sum++;
        if (sum == n) { break; }
      }
      if (sum == n) { break; }
    }
  } else if (h <= 2) {
    int sum = 0;
    REP(x, w) {
      REP(y, h) {
        field[y][x] = 1;
        sum++;
        if (sum == n) { break; }
      }
      if (sum == n) { break; }
    }
  } else if (n != 1) {
    int phase = 0;
    REP(i, n) {
      int tx = -100;
      int ty = -100;
      if (phase == 0) {
        if (i == 0) { tx = 0; ty = 0; }
        if (i == 1) { tx = 1; ty = 0; }
        if (i == 2) { tx = 0; ty = 1; }
        if (i == 3) { tx = 1; ty = 1; phase = 1; }
      } else if (phase == 1) {
        if (n % 2 == 1 && n - i == 3) {
          field[2][0] = 1;
          field[2][1] = 1;
          field[2][2] = 1;
          break;
        }
        tx = i / 2;
        ty = i % 2;
        if (tx == w - 1 && ty == 1) { phase = 2; }
      } else if (phase == 2) {
        if (n % 2 == 1 && n - i == 1) {
          field[2][2] = 1;
          break;
        }
        int v = i - 2 * w + 4;
        ty = v / 2;
        tx = v % 2;
        if (tx == 1 && ty == h - 1) { phase = 3; }
      } else {
        int v = i - 2 *  w - 2 * h + 4;
        ty = v / (w - 2) + 2;
        tx = v % (w - 2) + 2;
      }
      assert(0 <= tx && tx < w);
      assert(0 <= ty && ty < h);
      field[ty][tx] = 1;
    }
  }
  if (ans) {
    REP(y, h) {
      REP(x, w) {
        if (x == 0 && y == 0) { putchar('c'); }
        else { putchar(field[y][x] ? '.' : '*'); }
      }
      puts("");
    }
  } else {
    puts("Impossible");
  }
}
