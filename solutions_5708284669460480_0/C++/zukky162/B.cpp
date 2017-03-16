#include <bits/stdc++.h>
using namespace std;

int K, L, S;
string Key, Target;

double dp[101][101][101];
int dp2[101][101][101];
int nextJ[101][101];

int main() {
  int T; cin >> T;
  for(int tc = 1; tc <= T; ++tc) {
    cout << "Case #" << tc << ": ";
    cin >> K >> L >> S;
    cin >> Key;
    cin >> Target;
    
    for(int j = 0; j <= L; ++j) {
      string s = Target.substr(0, j);
      for(int k = 0; k < K; ++k) {
        string t = s + string(1, Key[k]);
        for(int i = min(L, j + 1); i >= 0; --i) {
          if(t.substr(t.size()-i) == Target.substr(0, i)) {
            nextJ[j][k] = i;
            break;
          }
        }
      }
    }
    
    memset(dp, 0, sizeof(dp));
    memset(dp2, 0, sizeof(dp2));
    dp[0][0][0] = 1;
    dp2[0][0][0] = 1;
    for(int i = 0; i < S; ++i) {
      for(int j = 0; j <= L; ++j) {
        for(int n = 0; n < 101; ++n) {
          for(int k = 0; k < K; ++k) {
            int nj = nextJ[j][k];
            int nn = n + (nj == L);
            dp[i+1][nj][nn] += dp[i][j][n] / (double)K;
            dp2[i+1][nj][nn] |= dp2[i][j][n];
          }
        }
      }
    }
    double res = 0, maxi = 0;
    for(int j = 0; j <= L; ++j) {
      for(int n = 0; n < 101; ++n) {
        if(dp2[S][j][n]) {
          res += n * dp[S][j][n];
          maxi = n;
        }
      }
    }
    printf("%.10f\n", maxi - res);
  }
  return 0;
}
