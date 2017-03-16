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

int cnt[26];

int main() {
  int tc;
  scanf("%d",&tc);
  while(tc--) {
    RESET(cnt, 0);
    static int t = 0;
    printf("Case #%d: ", ++t);
    string s;
    cin >> s;
    int n = s.length();
    for(int i = 0; i < n; i++) {
      cnt[s[i]-'A']++;
    }
    int best = 25;
    string back = "";
    string front = "";
    for(int i = n - 1; i >= 0; i--) {
      while(cnt[best] == 0 && best >= 0) best--;
      if (s[i] - 'A' == best) {
        front = front + s[i];
      } else {
        back = back + s[i];
      }
      cnt[s[i]-'A']--;
    }
    reverse(back.begin(), back.end());
    cout << (front + back) << endl;
  }
}