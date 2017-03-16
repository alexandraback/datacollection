#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct D{ int a,b; };

bool lessB( const D& a, const D& b )
{
  if( a.b == b.b ) return a.a > b.a;
  return a.b < b.b;
}
bool lessA( const D& a, const D& b )
{
  if( a.a == b.a ) return a.b > b.b;
  return a.a < b.a;
}

int main( void )
{
  int T,N,a,b;
  D d;
  vector<D> d0,d1;
  ios::sync_with_stdio(false);
  cin >> T;
  for( int testnum=1; testnum<=T; testnum++ ){
    d0.clear(); d1.clear();
    cin >> N;
    for( int i=0; i<N; i++ ){
      cin >> d.a >> d.b;
      d0.push_back( d );
    }
    int star = 0;
    sort( d0.begin(), d0.end(), lessB );
    bool toobad=false;
    int ret=0;
    while( d0.size() > 0 || d1.size() > 0 ){
      int idx=0;
      while( idx < d0.size() && d0[idx].b <= star ){
        star += 2;
        idx++;
        ret++;
      }
      if( idx > 0 ){
        d0.erase( d0.begin(), d0.begin() + idx ); 
        if( d0.size() == 0 && d1.size() == 0 ) break;
      }
      idx=0;
      if( idx < d1.size() && d1[idx].b <= star ){
        star += 1;
        ret++;
        d1.erase( d1.begin(), d1.begin() + 1 );
        continue;
      }
      sort( d0.begin(), d0.end(), lessA );
      if( idx < d0.size() && d0[idx].a <= star ){
        star += 1;
        ret++;
        d1.push_back( d0[idx] );
        sort( d1.begin(), d1.end(), lessB );
        d0.erase( d0.begin(), d0.begin() + 1 );
        sort( d0.begin(), d0.end(), lessB );
        continue;
      }
      toobad=true; break;
    }
    cout << "Case #" << testnum << ": ";
    if( toobad )
      cout << "Too Bad" << endl;
    else
      cout << ret << endl;
  }
  return 0;
}
