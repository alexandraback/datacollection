#include<bits/stdc++.h>
using namespace std ;
bool mat[51][51] ;
long long B , M ;
string s[51] ;

int main() {
  freopen("B-large.in","r",stdin) ;
  freopen("B-large.out","w",stdout) ;
  int  cases , caseno = 1 ;
  cin >> cases ;
  while( cases -- ) {
    cin >> B >> M ;
    if((1LL<<(B-2) < M )) {
      cout << "Case #"<<caseno++ << ": IMPOSSIBLE\n";
      continue ;
    }
    string tmp = "" ;
    for( int i = 0 ; i < B ; i++ ) {
      tmp += "0";
    }
    for( int i = 0 ; i < B ; i++ ) {
      s[i] = tmp ;
    }
    if((1LL<<(B-2) == M )) {
      for( int i = 0 ; i < B ; i++ ) {
        for( int j = 0 ; j < B ; j++ ) {
          if( i == 0 )continue ;
          else if( j > i ) {
            s[i][j] = '1' ;
          }
        }
      }
      for(int i = 1 ; i < B; i++ ) {
        s[0][i]='1';
      }
      cout << "Case #"<<caseno++ << ": POSSIBLE\n";
      for( int i = 0 ; i < B ; i++ ) {
        cout<< s[i] <<"\n";
      }
      continue ;
    }
    for( int i = 0 ; i < B ; i++ ) {
      for( int j = 0 ; j < B ; j++ ) {
        if( i == 0 )continue ;
        else if( j > i ) {
          s[i][j] = '1' ;
        }
      }
    }
    for( long long i = 0 ; i < B ; i++ ) {
      if( M & ( 1LL << i ) ) {
        s[0][B-i-2]='1';
      }
    }
    cout<<"Case #"<<caseno++<<": POSSIBLE\n";
    for( int i = 0 ; i < B ; i++ ) {
      cout<<s[i]<<"\n";
    }
  }
  return 0 ;
}
