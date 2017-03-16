#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <string>
#include <climits>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <ctime>

#define FOR(i, m, n) for (int i=m; i<n; i++)

using namespace std;

int N, S, P;

void solve() {
  int ret = 0;
  int sup = 0;
  scanf("%d%d%d", &N, &S, &P);
  FOR (i, 0, N) {
    int b; scanf("%d", &b);
    if (b/3 + (b%3>0) >= P) ret++;
    else if (b>=2 && b<=28) {
      if (3*P - 2 == b || 3*P - 3 == b || 3*P - 4 == b) sup++;
    }
  }
  printf("%d\n", ret + min(S, sup));
}

int main()
{
  int t; scanf("%d", &t);
  FOR (i, 0, t) {
    printf("Case #%d: ", i+1);
    solve();
  }
  return 0;
}
