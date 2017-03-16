#include <iostream>
#include <algorithm>
using namespace std;

typedef long long lli;

const int MAXN = 12;
const int MAXE = 7;

lli E, R, N, V[MAXN];
lli dp[MAXN][MAXE];

int main() {
  int Tc;
  cin >> Tc;
  for(int tc = 0; tc < Tc; ++tc) {
    cin >> E >> R >> N;
    for(int i = 0; i < N; ++i) cin >> V[i];
    fill(dp[0], dp[MAXN], -1);
    dp[0][E] = 0;
    for(int i = 0; i < N; ++i) {
      for(int j = 0; j <= E; ++j) {
	if(dp[i][j] == -1) continue;
	for(int k = 0; k <= j; ++k) {
	  int nj = min(E, j - k + R);
	  dp[i+1][nj] = max(dp[i+1][nj], dp[i][j] + k * V[i]);
	}
      }
    }
    lli ans = 0;
    for(int j = 0; j <= E; ++j) ans = max(ans, dp[N][j]);
    cout << "Case #" << tc+1 << ": " << ans << endl;
  }
  return 0;
}
