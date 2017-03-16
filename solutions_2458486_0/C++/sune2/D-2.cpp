#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <complex>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
#include <cassert>
#include <queue>
#include <set>
#include <map>
#include <valarray>
#include <bitset>
#include <stack>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define chmax(a,b) (a<(b)?(a=b,1):0)
#define chmin(a,b) (a>(b)?(a=b,1):0)
#define valid(y,x,h,w) (0<=y&&y<h&&0<=x&&x<w)
const int INF = 1<<29;
const double EPS = 1e-8;
const double PI = acos(-1);
typedef pair<int,int> pii;
typedef long long ll;

string dp[1<<20];
int t[20],m[20];
int contain[20][40];

int main() {
  int T;
  cin >> T;
  REP(cs,T) {
    int k,n;
    cin >> k >> n;
    map<int,int> ini;
    REP(i,k) {
      int key;
      cin >> key;
      ini[key]++;
    }
    REP(i,n) {
      cin >> t[i] >> m[i];
      REP(j,m[i]) {
        cin >> contain[i][j];
      }
    }
    REP(S,1<<n) dp[S] = "*";
    dp[0] = "";
    REP(S,1<<n) {
      if (dp[S] == "*") continue;
      map<int,int> keys = ini;
      REP(i,n) if (S>>i&1) {
        keys[t[i]]--;
        REP(j,m[i]) keys[contain[i][j]]++;
      }
      REP(i,n) {
        if (S>>i&1) continue;
        string tmp = dp[S];
        tmp.push_back(i);
        if (keys[t[i]] > 0 && (dp[S|1<<i] == "*" || dp[S|1<<i] > tmp)) {
          dp[S|1<<i] = tmp;
        }
      }
    }
    printf("Case #%d:", cs+1);    
    if (dp[(1<<n)-1] == "*") {
      puts(" IMPOSSIBLE");
    } else {
      REP(i,n) cout << " " << (int)dp[(1<<n)-1][i]+1;
      cout << endl;
      // vector<int> ans;
      // for (int now = (1<<n)-1; now != 0; now = pre[now]) {
      //   REP(i,n) {
      //     if ((now^pre[now])>>i&1) ans.push_back(i);
      //   }
      // }
      // for (int i=n-1; i>=0; --i) printf(" %d", ans[i]+1);
      // puts("");
    }
    
  }

}
