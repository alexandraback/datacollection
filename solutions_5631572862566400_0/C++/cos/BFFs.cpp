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

typedef vector<int> Edges;
typedef vector<Edges> Graph;

int n;
Graph g, revG;
int depths[1010];
int dfs(int from, int depth) {
  if (depths[from] != -1) { return depth - depths[from]; }
  depths[from] = depth;
  int ret = 0;
  FORIT(it, g[from]) {
    ret = max(ret, dfs(*it, depth + 1));
  }
  return ret;
}

int calc(int from, int parent) {
  int ret = 0;
  FORIT(it, revG[from]) {
    if (*it == parent) { continue; }
    ret = max(ret, calc(*it, from) + 1);
  }
  return ret;
}

void solve() {
  MEMSET(depths, -1);
  scanf("%d", &n);
  g = revG = Graph(n);
  REP(i, n) {
    int to;
    scanf("%d", &to);
    to--;
    g[i].push_back(to);
    revG[to].push_back(i);
  }
  int ans = 0;
  REP(from, n) {
    MEMSET(depths, -1);
    ans = max(ans, dfs(from, 0));
  }
  int sum = 0;
  REP(from, n) {
    int to = g[from][0];
    if (g[to][0] != from) { continue; }
    sum += 2;
    sum += calc(from, to);
    sum += calc(to, from);
  }
  ans = max(ans, sum / 2);
  printf("%d\n", ans);
}
