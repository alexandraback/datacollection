#include <cstdio>
#include <cassert>
#include <cstring>

#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;
typedef long long llint;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

const int MAXN = 2000005;

int n;
int bio[MAXN];

int rev(int x) {
  int ret = 0;
  while (x) {
    ret = ret * 10 + x % 10;
    x /= 10;
  }
  return ret;
}

void solve() {
  scanf("%d", &n);
  REP(i, MAXN) bio[i] = 0;
  bio[1] = 1;

  queue< int > q;
  q.push(1);
  while (!q.empty()) {
    int cur = q.front(); q.pop();
    if (cur == n) break;
    for (int nxt : {cur + 1, rev(cur)}) {
      if (nxt > MAXN) continue;
      if (bio[nxt]) continue;
      bio[nxt] = bio[cur] + 1;
      q.push(nxt);
    }
  }

  printf("%d\n", bio[n]);
}

int main(void) 
{
  int T; scanf("%d", &T);
  FOR(tc, 1, T + 1) {
    printf("Case #%d: ", tc);
    solve();
  }
  return 0;
}
