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

int main() {
  int tc;
  scanf("%d",&tc);
  while(tc--) {
    static int t = 0;
    printf("Case #%d: ", ++t);
    int n;
    scanf("%d",&n);
    int cnt[2505];
    RESET(cnt, 0);
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < 2*n-1; j++) {
        int x;
        scanf("%d",&x);
        cnt[x]++;
      }
    }
    vector<int> ans;
    for(int i = 1; i <= 2500; i++) {
      if (cnt[i]%2) ans.pb(i);
    }
    SORT(ans);
    for(int i = 0; i < (int)ans.size(); i++) {
      if (i) printf(" ");
      printf("%d", ans[i]);
    }
    printf("\n");
  }
}