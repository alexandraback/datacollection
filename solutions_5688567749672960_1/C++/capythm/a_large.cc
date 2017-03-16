#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int reverse( int n ){
  int ret = 0;
  while( n > 0 ){
    ret = ret*10 + (n%10);
    n /= 10;
  }
  return ret;
}
int rank( ll n ){
  ll ret = 0;
  while( n > 0 ){
    ret++; n /= 10;
  }
  return ret;
}
ll get_near( ll n ){
  if( n <= 20 ) return 1;
  int r = rank( n );
  ll a = 1,b=1;
  for( int i=0; i<(r+1)/2; i++ ){
    a = a*10;
  }
  for( int i=1; i<r-(r+1)/2; i++ ){
    b = b*10;
  }
  if( n/a == b ){
    if( b == 1 ){
      return 9*a/10 + 1;
    }
    return (b*10-1)*a/10 + 1;
  }
  return (n/a)*a + 1;
}
int main( void )
{
  int T;
  cin >> T;
  for( int ti=1; ti<=T; ti++ ){
    ll N;
    cin >> N;
    ll ret = 0;
    while( N > 0 ){
      ll a = get_near( N );
      if( a == 1 ){ ret+=N; break; }
      if( a > N ){ ret++; N--; continue; } 
      ret += N - a;
      N = a;
      N = reverse( N );
      ret++;
    }
    cout << "Case #" << ti << ": " << ret << endl;
  }
}
