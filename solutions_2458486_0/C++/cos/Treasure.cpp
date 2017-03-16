#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <set>
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
    //puts("");
    solve();
  }
}


int k, n;
int need[1000];
vector<int> treasure[1000];
set<vector<char> > memo;

int depth = 0;
vector<int> calc(map<int, int> have, vector<char> open) {
  //cout << depth << endl;
  vector<int> ret;
  if (memo.count(open)) { return ret; }
  memo.insert(open);
  int cnt = 0;
  REP(i, n) {
    if (open[i]) { continue; }
    cnt++;
    if (have[need[i]] > 0) {
      map<int, int> nhave = have;
      nhave[need[i]]--;
      FORIT(it, treasure[i]) { nhave[*it]++; }
      vector<char> nopen = open;
      nopen[i] = 1;
      depth++;
      vector<int> nret = calc(nhave, nopen);
      depth--;
      if (nret.size() != 0) {
        nret.push_back(i);
        ret = nret;
        break;
      }
    }
  }
  if (cnt == 0) {
    ret.push_back(-1);
  }
  return ret;
}

void solve() {
  MEMSET(need, -1);
  memo.clear();
  scanf("%d %d", &k, &n);
  map<int, int> have;
  REP(i, k) {
    int v;
    scanf("%d", &v);
    have[v] += 1;
  }
  REP(i, n) {
    treasure[i].clear();
    int cnt;
    scanf("%d %d", &need[i], &cnt);
    REP(j, cnt) {
      int v;
      scanf("%d", &v);
      treasure[i].push_back(v);
    }
  }
  vector<char> open(n, 0);
  vector<int> ans = calc(have, open);
  reverse(ans.begin(), ans.end());
  ans.pop_back();
  if ((int)ans.size() != n) {
    puts("IMPOSSIBLE");
  } else {
    REP(i, n) {
      if (i != 0) { putchar(' '); }
      printf("%d", ans[i] + 1);
    }
    puts("");
  }
}
