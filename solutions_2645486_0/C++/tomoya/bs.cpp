#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

#define lli long long int

int main(){
  int T;
  cin >> T;
  for(int test_case=1; test_case<=T; test_case++){
    int e,r,n;
    cin >> e >> r >> n;
    vector< int > v(n);
    for(int i=0; i<n; i++){ cin >> v[i]; }
    vector< vector<int> > dp(e+1,vector<int>(n+1,-1));
    
    dp[e][0] = 0;
    for(int vi=0; vi<n; vi++){
      for(int en=0; en<=e; en++){
	if( dp[en][vi] < 0 )continue;
	for(int h=0; h<=en; h++){
	  int next = dp[en][vi] + h * v[vi];
	  int nexte = min(e,en-h+r);
	  dp[nexte][vi+1] = max(dp[nexte][vi+1], next);
	}
      }
    }
    int ans = 0;
    for(int i=0; i<=e; i++){
      ans = max(dp[i][n],ans);
    }
    cout << "Case #" << test_case << ": " << ans << endl;
  }
  return 0;
}
