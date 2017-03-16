//Program: b
//Author: gary
//Date: 03/05/2014
#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ( (int) (x).size() )
#define all(x) (x).begin(), (x).end()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef pair<int, int> i2;
typedef long long ll;
const int INF = 1e9;
const int MAX_B = 31;

// flag = true means -> not greater than actual bit!
// flag = true -> has never chosen a smaller bit before!

int A[MAX_B], B[MAX_B], K[MAX_B];
ll dp[MAX_B][2][2][2];

ll rec(int n, int fk, int fa, int fb){
  if(n == -1){
    return (fk == 0) && (fa == 0) && (fb == 0);
  } 
  ll & ans = dp[n][fk][fa][fb];
  if(ans != -1)
    return ans;

  ans = 0;
  int bk = (fk ? K[n] : 1);
  int ba = (fa ? A[n] : 1);
  int bb = (fb ? B[n] : 1);
  for(int i = 0; i <= ba; i++){
    for(int j = 0; j <= bb; j++){
      if( (i & j) > bk ) continue;
      int nfk = fk && ((i & j) == bk);
      int nfa = fa && (i == ba);
      int nfb = fb && (j == bb);
      ans += rec(n - 1, nfk, nfa, nfb);
    }
  }
//  cout << "n = " << n << " fk = " << fk << " fa = " << fa << " fb = " << fb << " ans = " << ans << endl;
  return ans;
}

void bfill(int* a, int x){
  for(int i = 0; i < MAX_B; i++)
    a[i] = (x >> i) & 1;
}

ll solve(){
  int k, a, b;
  cin >> a >> b >> k;
  memset(dp, -1, sizeof dp);
  bfill(A, a);
  bfill(B, b);
  bfill(K, k);
  return rec(MAX_B - 1, 1, 1, 1);
}

int main(){
  ios::sync_with_stdio(0);
  int T;
  cin >> T;
  for(int caseno = 1; caseno <= T; caseno++){
    cout << "Case #" << caseno << ": " << solve() << endl;
  }
  return 0;
}
