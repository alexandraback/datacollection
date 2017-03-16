#include<bits/stdc++.h>
using namespace std ;
pair<string,string>arr[18] ;
int n;
long long dp[1<<17];
long long rec(int bit) {
  if( __builtin_popcount(bit) == n ) {
    return 0;
  }
  if( dp[bit] != -1 ) {
    return dp[bit];
  }
  long long ret=0;
  for( int i = 0 ; i < n ; i++ ) {
    if( (bit&(1<<i))==0 ) {
      bool f1=0 ;
      bool f2=0 ;
      for( int j = 0 ; j < n ; j++ ) {
        if( bit&(1<<j) ) {
          if( arr[i].first == arr[j].first ) {
            f1=1;
          }
          if( arr[i].second == arr[j].second ) {
            f2=1;
          }
        }
      }
      if( f1 && f2 ) {
        ret = max( ret , 1+rec(bit|(1<<i)) );
      } else {
        ret = max( ret , rec(bit|(1<<i)) );
      }
    }
  }
  return dp[bit] = ret ;
}
int main() {

  freopen("C-small-attempt1.in","r",stdin);
  freopen("C-small-attempt1.out","w",stdout);
  int cases,caseno=1 ;
  cin >> cases ;
  while( cases -- ) {
    cin >> n ;
    for( int i = 0 ; i < n ; i++ ) {
      string s , s1 ;
      cin >> s >> s1 ;
      arr[i]= {s,s1} ;
    }
    memset(dp,-1,sizeof(dp));
    cout << "Case #" << caseno++ << ": " << rec(0) << "\n" ;
    //cerr << "Case #" << caseno << ": " << rec(0) << "\n" ;
  }
  return 0 ;
}
