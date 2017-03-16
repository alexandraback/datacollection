#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <cstring>


using namespace std;

int main(){
   int n_case;
   cin >> n_case;
   for( int loop = 0 ; loop < n_case ; loop++ ){
     int E,R,N;
     cin >> E >> R>> N;
     vector<int> act;
     for( int i = 0 ; i < N ;i++){
      int tmp;
      cin >> tmp;
      act.push_back(tmp);
     }
     int dp[12][6];
     memset( dp, 0 , sizeof(dp));
     for( int n = 0 ; n < N; n++ ){
      for( int e = 1 ; e <=E ; e ++ ){
        int curval = dp[n][e];
        for( int usede = 0 ; usede <= e ; usede++){
          dp[n+1][min(e-usede+R,E)] = max( dp[n+1][min(e-usede+R,E)], curval+usede*act[n] );
        }
      }
     }
     /*
     for( int n = 0 ; n < N ; n++ ){
      for( int e = 0 ; e <= E; e++ ){
        cout << dp[n][e]<<", ";
      }
     }*/
     int ans = 0;
     for( int j = 0 ; j <=E; j++){
      ans = max( ans, dp[N][j] );
     }
     cout << "Case #" << loop+1 << ": " <<ans<< endl;
   }
   return 0;
}
