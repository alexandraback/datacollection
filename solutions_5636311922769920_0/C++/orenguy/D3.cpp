#include <bits/stdc++.h>

using namespace std;

typedef long long     LL;
typedef pair<int,int> pii;

double PI  = acos(-1);
double EPS = 1e-7;
int INF    = 1000000000;
LL INFLL   = 1000000000000000000LL;

#define fi            first
#define se            second
#define mp            make_pair
#define pb            push_back

#define input(in)     freopen(in,"r",stdin)
#define output(out)   freopen(out,"w",stdout)

#define MIN(a, b)     (a) = min((a), (b))
#define MAX(a, b)     (a) = max((a), (b))

#define RESET(a, b)   memset(a,b,sizeof(a))
#define ALL(a)        (a).begin(), (a).end()
#define SIZE(a)       (int)a.size()
#define SORT(a)       sort(ALL(a))
#define UNIQUE(a)     (a).erase( unique( ALL(a) ), (a).end() )
#define FOR(a, b, c)  for (int (a)=(b); (a)<=(c); (a)++)
#define FORD(a, b, c) for (int (a)=(b); (a)>=(c); (a)--)
#define FORIT(a, b)   for (__typeof((b).begin()) a=(b).begin(); a!=(b).end(); a++)

int mx[8] = {-1,1,0,0,-1,-1,1,1};
int my[8] = {0,0,-1,1,-1,1,-1,1};

// ----- //

long long num[105];

int main() {
  int t;
  scanf("%d",&t);
  while(t--) {
    int k, c, s;
    scanf("%d %d %d",&k,&c,&s);
    num[0] = 1;
    for(int i = 1; i <= c; i++) {
      num[i] = k * num[i-1];
    }
    static int tc = 0;
    printf("Case #%d: ", ++tc);
    int ans = (k+c-1)/c;
    if (ans <= s) {
      long long cur = 0;
      vector<long long> lol;
      for(int i = 0; i < k; i++) {
        if (i % c == 0 && i > 0) {
          lol.pb(cur);
          cur = 0;
        }
        cur += i * num[i%c];
      }
      lol.pb(cur);
      for(int i = 0; i < (int)lol.size(); i++) {
        if (i > 0) {
          printf(" ");
        }
        printf("%lld", lol[i] + 1);
      }
      puts("");
    } else {
      puts("IMPOSSIBLE");
    }
  }
}