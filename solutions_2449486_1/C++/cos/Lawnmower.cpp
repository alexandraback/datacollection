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

int w, h;
int field[1000][1000];
int ok[1000][1000];
void solve() {
  MEMSET(ok, 0);
  scanf("%d %d", &h, &w);
  REP(y, h) {
    REP(x, w) {
      scanf("%d", &field[y][x]);
    }
  }
  REP(y, h) {
    int v = 0;
    REP(x, w) {
      v = max(v, field[y][x]);
    }
    REP(x, w) {
      if (field[y][x] == v) { ok[y][x] = 1; }
    }
  }
  REP(x, w) {
    int v = 0;
    REP(y, h) {
      v = max(v, field[y][x]);
    }
    REP(y, h) {
      if (field[y][x] == v) { ok[y][x] = 1; }
    }
  }
  int ans = 1;
  REP(y, h) {
    REP(x, w) {
      ans &= ok[y][x];
    }
  }
  puts(ans ? "YES" : "NO");
}
