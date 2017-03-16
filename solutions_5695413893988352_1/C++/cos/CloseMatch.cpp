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
pair<ll, pair<string, string> > memo[3][30];
char str[2][100];
ll bases[30];
pair<ll, pair<string, string> > calc(const int want, const int depth) {
  if (depth == n) {
    return make_pair(0, make_pair("", ""));
  }
  if (memo[want][depth].second.first != "") { return memo[want][depth]; }
  pair<ll, pair<string, string> > ret = make_pair(1LL << 62, make_pair("", ""));
  if (want == 1) { ret.first = -ret.first; }
  REP(i, 10) {
    string c1 = "";
    c1 += '0' + i;
    if (str[0][depth] != '?' && str[0][depth] != '0' + i) { continue; }
    REP(j, 10){
      string c2 = "";
      c2 += '0' + j;
      if (str[1][depth] != '?' && str[1][depth] != '0' + j) { continue; }
      ll diff = (i - j) * bases[depth];
      int nwant = want;
      if (want == 0 && diff < 0) { nwant = 1; }
      if (want == 0 && diff > 0) { nwant = 2; }
      pair<ll, pair<string, string> > nans = calc(nwant, depth + 1);
      nans.first += diff;
      nans.second.first = c1 + nans.second.first;
      nans.second.second = c2 + nans.second.second;
      if (nans.first == ret.first) {
        ret =min(ret, nans);
      } else if (want == 0 && abs(nans.first) < abs(ret.first)) {
        ret = nans;
      } else if (want == 1 && -nans.first < -ret.first) {
        ret = nans;
      } else if (want == 2 && nans.first < ret.first) {
        ret = nans;
      }
    }
  }
  assert(ret.first != 1LL << 62);
  return memo[want][depth] = ret;
}

void solve() {
  REP(i, 3) REP(j, 30) { memo[i][j] = make_pair(0, make_pair("", "")); }
  scanf("%s %s", str[0], str[1]);
  n = strlen(str[0]);
  bases[n - 1] = 1;
  for (int i = n - 2; i >= 0; i--) { bases[i] = bases[i + 1] * 10; }
  pair<ll, pair<string, string> > ans = calc(0, 0);
  cout << ans.second.first << " " << ans.second.second << endl;
}
