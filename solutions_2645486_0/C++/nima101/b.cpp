#include <iostream>

using namespace std;

typedef long long ll;

const int maxn = 10005;
ll v[maxn], dp[2][10000005];

int main() {
  int tc, E, R, n;
  cin >> tc;
  for(int t=1; t<=tc; t++) {
    cin>>E>>R>>n;
    for(int i=0; i<n; i++)
      cin>>v[i];

    for(int i=0; i<=E; i++) {
      dp[(n-1)%2][i] = v[n-1]*i;
    }
    
    for(int i=n-2; i>=0; i--) {
      for(int s=0; s<=E; s++) {
        ll val = 0;
        for(int c=0; c<=s; c++) {
          val = max(val , v[i]*c + dp[(i+1)%2][min(E, s-c+R)]);
        }
        dp[i%2][s] = val;
      }
    }
    
    cout<<"Case #"<<t<<": "<<dp[0][E]<<endl;
  }  
  return 0;
}
