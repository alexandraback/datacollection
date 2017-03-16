#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cassert>
#include <string>
#include <memory.h>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <map>
#include <cctype>
#include <iomanip>
#include <sstream>
#include <cctype>
#include <fstream>
#include <cmath>
using namespace std;

#define REP2(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define REP(i, n) REP2(i, 0, n)
#define ALL(c) (c).begin(), (c).end()
#define ITER(c) __typeof((c).begin())
#define PB(e) push_back(e)
#define FOREACH(i, c) for(ITER(c) i = (c).begin(); i != (c).end(); ++i)
#define MP(a, b) make_pair(a, b)
#define PARITY(n) ((n) & 1)

typedef long long ll;
typedef pair<ll, ll> P;
const int INF = 1000 * 1000 * 1000 + 7;
const double EPS = 1e-10;

const int sz = 110;
const int MAX = 1000 * 1000 * 10;
int dp[110][110][110];

int solve(){
  memset(dp, -1, sizeof(dp));
  int A, N;
  cin >> A >> N;
  vector<int> M(N);
  REP(i,N) cin >> M[i];
  sort(ALL(M));

  
  dp[0][0][0] = A;
  REP(n, N){
    REP(a, sz - 1){
      REP(b, sz - 1){
        if(dp[n][a][b] == -1) continue;
        
        int L = dp[n][a][b];

        if(L > M[n]) {
          dp[n+1][a][b] = max(dp[n+1][a][b], min(MAX, L + M[n]));
        }
        
        dp[n+1][a+1][b] = max(dp[n+1][a+1][b], L);
        dp[n][a][b+1] = max(dp[n][a][b+1], min(MAX, 2 * L - 1));
      }
    }
  }
  
  int res = INF;
  
  REP(a, sz - 1)REP(b, sz - 1) if(dp[N][a][b] != -1) res = min(res, a + b);
  return res;
}

int main(){
  int T;
  cin >> T;
  REP(t, T){
    printf("Case #%d: %d\n", t + 1, solve());
  }
  return 0;
}
