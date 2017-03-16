#include <iostream>
#include <set>
#include <cstring>
using namespace std;

char a[2000004];
int  f[] = { 0, 1, 10, 100, 1000, 10000, 100000, 1000000 };
int main( void )
{
  int T,t,A,B,d[8],n,c,ret;
  set<int> s;
  cin >> T;
  for( t=1; t<=T; t++ ){
    cin >> A >> B;
    ret=0;
    memset( a, 0, sizeof( a ) );
    for( int i=A; i<=B; i++ ){
      if( a[i] ) continue;
      n=0; c=i;
      while( c > 0 ){ d[n++] = c % 10; c /= 10; }
      s.clear();
      for( int j=0; j<n; j++ ){
        c=0;
        for( int k=n-1; k>=0; k-- ){
          c = c * 10 + d[(j+k)%n];
        }
        if( c < f[n] ) continue;
        if( c > B || c < A ) continue;
        if( s.find( c ) == s.end() ) s.insert( c );
        a[c] = 1;
      }
      if( s.size() > 1 ) ret += s.size() * ( s.size() - 1 ) / 2;
    }
    cout << "Case #" << t << ": " << ret << endl;
  }
  return 0;
}
