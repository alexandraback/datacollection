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

int n, h, w;
void solve() {
  scanf("%d %d %d", &n, &h, &w);
  if (w > h) { swap(h, w); }
  string ans = "RICHARD";
  if (h * w % n != 0) { goto end; }
  if (n >= 7) { goto end; }
  if (w == 1 && n >= 3) { goto end; }
  if (w == 2 && n >= 4) { goto end; }
  if (w == 3 && n >= 6) { goto end; }
  ans = "GABRIEL";
end:
  cout << ans << endl;
}
