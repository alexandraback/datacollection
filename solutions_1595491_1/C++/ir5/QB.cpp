#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cassert>
using namespace std;
typedef long long ll;

#define REP(i,n) for (int i=0; i<(int)(n); ++i)
#define FOR(i,k,n) for (int i=(k); i<(int)(n); ++i)
#define FOREQ(i,k,n) for (int i=(k); i<=(int)(n); ++i)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define SZ(v) (int)((v).size())
#define MEMSET(v,h) memset((v),(h),sizeof(v))

void solve() {
  int N, S, P; cin >> N >> S >> P;
  int vt[N];
  REP(i, N) cin >> vt[i];
  // sp,+1
  int dp[N+10][N+10]; // [idx][surprising]
  MEMSET(dp, 0xf0);
  dp[0][0] = 0;

  REP(i, N) REP(s, N+1) {
    int t = vt[i];
    // hogepiyo
    REP(a, 34) FOREQ(b, max(0, a-2), a) FOREQ(c, max(0, a-2), a) if (a+b+c==t) {
      int best = max(a,max(b,c));
      int diff = best-min(a,min(b,c));

      if (diff > 2) continue;
      int ns = (diff == 2) ? (s+1) : s;
      int adder = (best >= P) ? 1 : 0;
      dp[i+1][ns] = max(dp[i+1][ns], dp[i][s]+adder);
    }
     // cout<<"!"<<i<<" "<<s<<" "<<dp[i][s]<<endl;
  }

  printf("%d\n", dp[N][S]);
}

int main() {
  int test_case; cin >> test_case;
  REP(t, test_case) {
    printf("Case #%d: ", t+1);
    solve();
  }
}
