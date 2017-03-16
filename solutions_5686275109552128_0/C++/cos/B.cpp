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
    // puts("");
    solve();
  }
}

int n;
int plate[3000];
void solve() {
  scanf("%d", &n);
  REP(i, n) { scanf("%d", &plate[i]); }
  sort(plate, plate + n);
  reverse(plate, plate + n);
  int low = 1;
  int high = 1010;
  while (low != high) {
    int mid = (low + high) / 2;
    bool ok = false;
    REP(move, mid) {
      int total = 0;
      REP(i, n) {
        int d = 1;
        while (total <= move && move + (plate[i] + (d - 1)) / d > mid) {
          total++;
          d++;
        }
        if (total > move) { break; }
      }
      if (total <= move) { ok = true; break; }
    }
    if (ok) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }
  printf("%d\n", low);
}
