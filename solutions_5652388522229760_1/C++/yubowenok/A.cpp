#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <complex>
#include <ctime>
#include <cassert>
#include <functional>

using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> PII;

#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))

const int INF = (int)1E9;
#define MAXN 1000005

int ans[MAXN];
int main() {
  freopen("input", "r", stdin);
  freopen("output", "w", stdout);

  ans[0] = -1;
  REP(n, 1, MAXN) {
    set<int> ds;
    for (int i = 1;; i++) {
      int x = n * i;
      while(x) {
        ds.insert(x % 10);
        x /= 10;
      }
      if (ds.size() == 10) {
        ans[n] = n * i;
        break;
      }
    }
  }
  int cs, n;
  cin >> cs;
  REP(csn, 1, cs+1) {
    printf("Case #%d: ", csn);
    cin >> n;
    if (ans[n] == -1) puts("INSOMNIA");
    else printf("%d\n", ans[n]);
  }
  return 0;
}
