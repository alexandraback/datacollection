#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <utility>
#include <vector>
using namespace std;

#define FORIT(it, obj) for(__typeof(obj.begin()) it=obj.begin();it!=obj.end();++it)
#define REP(i, N) for(int i = 0; i < N; i++)
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define mp make_pair
#define pb push_back
#define bpc __builtin_popcount
typedef pair<int,int> pii;
typedef long long ll;
int P[2500];
int D;
int pos(int x, bool debug = false) {
  int splits = 0;
  static int dp[1500];
  FOR(i, 0, 1000) {
    if (i <= x) dp[i] = 0;
    else dp[i] = 1 + dp[i - x]; //dp[i] = 1 + dp[i/2] + dp[i - i/2];
  }
  REP(i, D) {
    splits += dp[P[i]];
    if (debug)
      printf("P[i] = %d, x=%d, sp=%d\n", P[i], x, dp[P[i]]);
  }
  if (debug)
    printf("splits=%d\n", splits);
  
  return x + splits;
}

int main() {
  //freopen("c.in", "r", stdin);
  int T; cin >> T;
  REP(casenum, T) {
    printf("Case #%d: ", casenum + 1);
    cin >> D;
    REP(i, D)
      cin >> P[i];
    int ans = 1000, bi;
    FOR(i, 1, 1000) {
      int p = pos(i);
      if (p < ans) ans = p, bi=i;
    }
    //    pos(bi, true);
    
    printf("%d\n", ans);
  }
  return 0;
}
