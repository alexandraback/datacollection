#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <set>
#include <string>

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
int memo[1 << 16];
char strs[1010][2][30];

int calc(int use, const set<string> &first, const set<string> &second) {
  if (use == (1 << n) -1) { return 0; }
  if (memo[use] != -1) { return memo[use]; }
  int ret = 0;
  REP(i, n) {
    int nuse = use | (1 << i);
    if (use == nuse) { continue; }
    set<string> nfirst = first;
    nfirst.insert(strs[i][0]);
    set<string> nsecond = second;
    nsecond.insert(strs[i][1]);
    int nret = calc(nuse, nfirst, nsecond);
    if (first.count(strs[i][0]) && second.count(strs[i][1])) { nret++; }
    ret = max(ret, nret);
  }
  return memo[use] = ret;
}

void solve() {
  MEMSET(memo, -1);
  scanf("%d", &n);
  REP(i, n) { scanf("%s %s", strs[i][0], strs[i][1]); }
  set<string> first;
  set<string> second;
  int ans = calc(0, first, second);
  printf("%d\n", ans);
}
