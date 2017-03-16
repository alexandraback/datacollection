#define DEBUG 0
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
const int INF = 2000000001;
#define FOR(x,b,e) for(int x=(b);x<=(e);++x)
#define FORD(x,b,e) for(int x=(b);x>=(e);--x)
#define REP(x,n) for(int x=0;x<(n);++x)
#define ALL(c) c.begin(),c.end()
#define VAR(x,c) __typeof(c) x=(c)
#define FOREACH(x,c) for(VAR(x,(c).begin());x!=(c).end();++x)
#define PB push_back
#define MP make_pair
#define ST first
#define ND second
#define dbg(...) \
  do { if (DEBUG) fprintf(stderr, __VA_ARGS__); } while (0)

int main() {
  int T;
  scanf("%d", &T);

  int result, N, S, p, sum, base;
  for (int j = 1; j <= T; j++) {
    result = 0;
    scanf("%d%d%d", &N, &S, &p);
    REP (i,N) {
      scanf("%d", &sum);
      base = (sum+2)/3;
      if (base >= p) { result++; continue; }
      if (base == p-1 && S > 0) {
        if (sum%3 == 0 && sum > 0) { S--; result++; }
        else if (sum%3 == 2 && sum < 29) { S--; result++; }
      }
    }


    printf("Case #%d: %d\n", j, result);
  }

  return 0;
}
