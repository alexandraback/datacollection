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

  int result, A, B, n, m, len, ex, x;
  vector<PII> res;
  FOR (Z,1,T) {
    result = 0;
    res.clear();

    scanf("%d%d", &A, &B);
    len = int(log10(A));
    ex = int(pow(10.0,len));

    //printf("%d\n", len);
    FOR (n,A,B) {
      m = n;
      FOR (i,1,len) {
        x = m%10;
        m = (m/10) + (x*ex);
        //printf("%d\n", m);
        if (m > n && m >= A && m <= B) {
          res.PB(MP(n,m));
          //result++;
          //printf("%d: (%d, %d)\n", result, n, m);
        }
      }

    }

    sort(res.begin(), res.end());
    res.resize(unique(res.begin(), res.end())-res.begin());


    printf("Case #%d: %d\n", Z, int(res.size()));
  }

  return 0;
}
