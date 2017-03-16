#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <cstring>

#define rep(i,n) for(int i = 0; i < n; i++)
#define SZ(v) ((int)(v).size())
#define pb push_back
#define all(v) (v).begin(), (v).end()

#define trace(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef vector<int> vi;

const int INF = 1 << 29;

int n;
vi a,b;

int dp[1<<22];

int solve(int mask){

  int count = __builtin_popcount(mask);

  if(count == n*2) {
    return 0;
  }

  int& d = dp[mask];
  if(d != -1) return d;

  int ans = INF;

  rep(i,n){
    if(((mask >> i) & 1) || count < a[i]) continue;
    ans = min(ans,1+ solve(mask | (1 << i)));
  }

  rep(i,n){
    if(((mask >> (i+n)) & 1) || count < a[i] || count < b[i]) continue;
    ans = min(ans, 1+solve(mask | (1 << i) | (1 << (i+n))));
  }

  return d = ans;
  
}

int main(){

  int t;
  cin >> t;

  rep(i,t){
    cin >> n;

    a = vi(n);
    b = vi(n);

    rep(j,n) cin >> a[j] >> b[j];

    memset(dp, -1, sizeof(dp));
    int ans = solve(0);
    if(ans == INF)
      cout << "Case #" << i+1 << ": " << "Too Bad" << endl;
    else 
      cout << "Case #" << i+1 << ": " << ans << endl;
  }
  return 0;

}
