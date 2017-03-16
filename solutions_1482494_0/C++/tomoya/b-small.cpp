#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int tc;
  cin >> tc;
  for(int tid = 1; tid <= tc; tid++){
    int n; cin >> n;
    int nn = 2*n;
    vector< int > dp(1<<nn,-1);
    vector<int> a(n),b(n);
    for(int i=0; i<n; i++){
      cin >> a[i] >> b[i];
    }
    dp[0] = 0;
    for(int i=0; i<(int)dp.size(); i++){
      if( dp[i] < 0 )continue;
      int stars = 0;
      for(int j = 0; j<n; j++){
	int tmp = (i>>(2*j)) & 3;
	if( tmp >= 2 ) stars += 2;
	if( tmp == 1 ) stars += 1;
      }
      for(int j = 0; j<n; j++){
	int tmp = (i>>(2*j)) & 3;
	if( tmp >= 2 )continue;
	if( stars >= a[j] ){
	  int next = i | (1<<(2*j));
	  dp[next] = dp[next] == -1 ? dp[i] + 1 : min(dp[next], dp[i] + 1);
	}
	if( stars >= b[j] ){
	  int next = i | (3<<(2*j));
	  dp[next] = dp[next] == -1 ? dp[i] + 1 : min(dp[next], dp[i] + 1);
	}
      }
    }
    printf("Case #%d: ",tid);
    if( dp[(1<<nn)-1] == -1 )printf("Too Bad\n");
    else printf("%d\n",dp[(1<<nn)-1]);
  }
  return 0;
}
