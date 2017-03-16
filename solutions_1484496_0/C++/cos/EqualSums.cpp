#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <map>

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
    puts("");
    solve();
  }
}

void PrintVect(const vector<int> &vs) {
  REP(i, vs.size()) {
    if (i != 0) { putchar(' '); }
    printf("%d", vs[i]);
  }
  puts("");
}

int n;
ll seq[1000];
map<ll, vector<int> > sums;

void solve() {
  sums.clear();
  scanf("%d", &n);
  REP(i, n) { scanf("%lld", &seq[i]); }
  REP(i, 1 << n) {
    ll s = 0;
    vector<int> vs;
    REP(j, n) {
     if ((i >> j) & 1) { s += seq[j]; vs.push_back(seq[j]); }
    }
    if (sums.count(s)) {
      vector<int> ans = sums[s];
      PrintVect(ans);
      PrintVect(vs);
      return;
    }
    sums[s] = vs;
  }
  puts("impossible");
}
