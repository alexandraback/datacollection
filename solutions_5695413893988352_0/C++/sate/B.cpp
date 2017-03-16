#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;

struct edge {
  P p,to;
};

ll dp[20][2];
vector<edge> rdp[20][2];

P resolve( int i,int j ){
  if( dp[i][j] == LLONG_MAX ) return P(-1,-1);
  ll a=0,b=0;
  // cout << i << " " <<j<< ", " << a << "  " << b << endl;
  while( i > 0 ){
    edge to={P(LLONG_MAX,LLONG_MAX),P(-1,-1)};
    for(int k=0;k<(int)rdp[i][j].size();k++){
      if( to.p > rdp[i][j][k].p ) 
        to = rdp[i][j][k];
    }
    a*=10LL; b*=10LL;
    a += to.p.first;
    b += to.p.second;
    i = to.to.first;
    j = to.to.second;
    //    cout << i << " " <<j<< ", " << a << "  " << b << endl;    
  }
  return P(a,b);
}

P solve(const string &s1,const string&s2,bool rvf){
  int n = s1.size();
  for(int i=0;i<=n;i++){
    for(int j=0;j<2;j++){
      dp[i][j] = LLONG_MAX;
      rdp[i][j].clear();
    }
  }
  dp[0][0] = 0;  
  ll k = 1;
  for(int i=0;i<n;i++){
    for(int j=0;j<2;j++){
      if( dp[i][j] == LLONG_MAX ) continue;
      int k1 = s1[i]=='?'?-1:s1[i]-'0';
      int k2 = s2[i]=='?'?-1:s2[i]-'0';
      for(int a=0;a<10;a++){
        if( k1 != -1 && k1 != a ) continue;
        for(int b=0;b<10;b++){
          if( k2 != -1 && k2 != b ) continue;
          int ak = a - j;
          int nt = 0;
          if( ak < b ){
            ak = ak + 10;
            nt = 1;
          }
          // cout << i<< "," << j << " => " <<  dp[i][j] << " " << ak << " " << b << endl;
          if( dp[i+1][nt] >= dp[i][j] + (ak-b)*k ){
            if( dp[i+1][nt] > dp[i][j] + (ak-b)*k ) {
              dp[i+1][nt] = dp[i][j] + (ak-b)*k;
              rdp[i+1][nt].clear();
            }
            if( rvf ) rdp[i+1][nt].push_back( { P( b, a ), P( i, j ) } );
            else rdp[i+1][nt].push_back( { P( a, b ), P( i, j ) } );
          }          
        }
      }
    }
    k*=10;
  }

  P res1 = resolve( n, 0 );
  return res1;
}

void output( P res,int n){
  cout << setfill('0') << setw(n) << right << res.first;
  cout << " ";
  cout << setfill('0') << setw(n) << right << res.second;
  cout << endl;
}

int main(){
  int T; cin >> T;
  for(int ttt=1;ttt<=T;ttt++){
    cout << "Case #" << ttt << ": ";
    string s1,s2;
    cin >> s1 >> s2;
    reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());
    P res1 = solve( s1, s2 , false);
    swap( s1, s2 );
    P res2 = solve( s1, s2 , true);
    
    int n = s1.size();
    if( res1.first == -1 ){
      output( res2, n );
    } else if( res2.first == -1 ){
      output( res1, n );
    } else if( abs( res1.first - res1.second ) > abs( res2.first - res2.second ) ){
      output( res2, n );
    } else if( abs( res1.first - res1.second ) < abs( res2.first - res2.second ) ) {
      output( res1, n );
    } else {
      if( res1.first < res2.first ) {
        output( res1, n );
      } else if( res1.first > res2.first ) {
        output( res2, n );
      } else {
        if( res2.first < res2.second )
          output( res1, n );
        else
          output( res2, n );
      }
    }
  }
}
