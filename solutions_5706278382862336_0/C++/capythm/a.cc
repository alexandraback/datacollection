#include <iostream>
using namespace std;
typedef long long ll;
ll gcd( ll a, ll b )
{
  ll t;
  if( a < b ){ t = a; a = b; b = t; }
  while( ( t = a % b ) != 0 ){ a = b; b = t; }
  return b;
}
int main( void )
{
  int T;
  ll P,Q;
  char dummy;
  cin >> T;
  for( int testcase=1; testcase<=T; testcase++ ){
    cin >> P >> dummy >> Q;
    if( P == 0 || P > Q ){
      cout << "Case #" << testcase << ": " << "impossible" << endl;
      continue;
    }
    ll G = gcd( P, Q ); P /= G; Q /= G;
    int c=0,f=0;
    while( Q > 0 ){
      f += Q % 2;
      Q /= 2;
      c++;
    }
    if( f > 1 ){
      cout << "Case #" << testcase << ": " << "impossible" << endl;
      continue;
    }
    int ret=0;
    for( int i=0; i<c; i++ ){
      if( P & (1<<(c-1-i)) ){ ret = i; break; }
    }
    if( ret==0 ) ret = 1;
    cout << "Case #" << testcase << ": " << ret << endl;
  }
  return 0;
}
