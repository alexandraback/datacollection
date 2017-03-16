//mishraiiit
#include<bits/stdc++.h>
#define ll long long int
#define fastScan ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;
typedef pair <ll, ll> pll;

#ifdef TRACE
  #include "trace.h"
#else
  #define trace1(x)
  #define trace2(x, y)
  #define trace3(x, y, z)
  #define trace4(a, b, c, d)
  #define trace5(a, b, c, d, e)
  #define trace6(a, b, c, d, e, f)
  #define myassert(a, b)
#endif

string F[18], S[18];
bool vis[100001];
int dp[100001];
int n;
int solve(ll mask) {
  if(vis[mask]) return dp[mask];
  vis[mask] = true;
  int & ans = dp[mask];
  for(int i = 0; i < n; i++) {
    if( ! (mask & (1LL << i))) {

      bool first_found = false, second_found = false;

      for(int j = 0; j < n; j++) {
        if(mask & (1LL << j)) {
          if(F[j] == F[i]) first_found = true;
          if(S[j] == S[i]) second_found = true;
        }
      }

      ans = max(ans, (first_found && second_found) + solve(mask | (1LL << i)));
    }
  }
  return ans;
}

int main() {
    fastScan;
    int t;
    cin >> t;
    for(int ii = 1; ii <= t; ii++) {
      memset(vis, 0, sizeof(bool) * 100001);
      memset(dp, 0, sizeof(int) * 100001);
      cin >> n;
      for(int i = 0; i < n; i++) {
        cin >> F[i] >> S[i];
      }
      int ans = solve(0LL);
      cout << "Case #" << ii << ": ";
      cout << ans << endl;
    }
    return 0;
}

