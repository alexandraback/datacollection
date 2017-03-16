#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <complex>
#define rep(i,m,n) for(int i = m; i < (int)n; i++)
#define REP(i,n) rep(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()

using namespace std;
static const double EPS = 1e-9;
int INF = 1<<28;
typedef long long ll;
typedef pair<int,int> Pii;

int E, R, N;
int v[11];
int dp[6][11];

void input() {
  cin >> E >> R >> N;
  REP(i,N) {
    cin >> v[i];
  }
  return;
}

void output() {
  REP(j,E+1) {
    REP(i,N+1) {
      printf(" %3d", dp[E-j][i]);
    }
    cout << endl;
  }
}

int solve() {
  input();
  memset(dp, -1, sizeof(dp));
  dp[E][0] = 0;
  for (int i = 1; i < N+1; i++) {
    for (int j = 0; j < E+1; j++) {
      if ( dp[j][i-1] < 0 )
	continue;
      for (int k = 0; k <= j; k++) {
	int next = min(j-k+R,E);
	dp[next][i] = max(dp[next][i], dp[j][i-1] + v[i-1] * k);
      }
    }
  }
//  output();
  int ans = -1;
  for (int i = 0; i <= E; i++) {
    ans = max(ans, dp[i][N]);
  }  
  return ans;
}


int main() {
  int T; cin >> T;
  for (int i= 0; i < T; i++) {
    int ans = solve();
    cout << "Case #"<< i+1 << ": ";
    cout << ans << endl;
  }
  
  
  return 0;
}
