#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <set>

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
    // puts("");
    solve();
  }
}

int n, m;
vector<int> lines[100];
int grid[100][100];
bool used[100];

vector<int> calc(int x, bool first_skip) {
  if (x == n) {
    vector<int> ans;
    FOR(y, 1, n) {
      REP(i, m) {
        if (used[i]) { continue; }
        REP(x, n) {
          if (first_skip && x == 0) { continue; }
          if (lines[i][x] != grid[y][x]) { goto next; }
        }
        grid[y][0] = lines[i][0];
        goto found;
next:;
      }
      if (first_skip) { return vector<int>(); }
      {
        vector<int> temp;
        REP(x, n) { temp.push_back(grid[y][x]); }
        if (ans.size() != 0) { return vector<int>(); }
        ans = temp;
      }
found:;
    }
    if (first_skip) {
      assert(ans.size() == 0);
      REP(y, n) { ans.push_back(grid[y][0]); }
    }
    return ans;
  }

  FOR(i, 1, m) {
    if (used[i]) { continue; }
    if (grid[0][x] == lines[i][0]) {
      REP(y, n) { grid[y][x] = lines[i][y]; }
      used[i] = true;
      vector<int> nans = calc(x + 1, first_skip);
      if (nans.size() != 0) { return nans; }
      used[i] = false;
    }
  }
  if (x == 0) {
    return calc(x + 1, true);
  }
  return vector<int>();
}

void solve() {
  MEMSET(used, false);
  used[0] = true;
  scanf("%d ", &n);
  m = 2 * n - 1;
  REP(i, 100) { lines[i] = vector<int>(n); }
  REP(i, m) {
    REP(j, n) {
      scanf("%d", &lines[i][j]);
    }
  }
  sort(lines, lines + m);
  vector<int> ans;
  REP(iter, 2) {
    REP(i, n) { grid[0][i] = lines[0][i]; }
    ans = calc(0, false);
    if (ans.size() != 0) { break; }
    swap(lines[0], lines[1]);
  }
  REP(i, n) { 
    if (i != 0) { putchar(' '); }
    printf("%d", ans[i]);
  }
  puts("");
}
