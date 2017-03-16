#include <iostream>
#include <queue>
#include <string>
#include <map>
using namespace std;
int main( void )
{
  int T;
  cin >> T;
  for( int testcase=1; testcase<=T; testcase++ ){
    int X, Y;
    cin >> X >> Y;
    map<pair<int,int>,int> m;
    map<pair<int,int>,char> n;
    queue<pair<int,int> > q;
    q.push( pair<int,int>(0,0) );
    m[pair<int,int>(0,0)] = 0;
    while( !q.empty() ){
      pair<int,int> d = q.front(); q.pop();
      if( d.first == X && d.second == Y ) break;
      //cout << d.first << ',' << d.second << endl;
      int dist = m[d];
      dist++;
      pair<int,int> a0 = pair<int,int>( d.first,      d.second+dist );
      pair<int,int> a1 = pair<int,int>( d.first,      d.second-dist );
      pair<int,int> a2 = pair<int,int>( d.first+dist, d.second      );
      pair<int,int> a3 = pair<int,int>( d.first-dist, d.second      );
      if( m.find( a0 ) == m.end() ){ m[a0] = dist; n[a0] = 'N'; q.push( a0 ); }
      if( m.find( a1 ) == m.end() ){ m[a1] = dist; n[a1] = 'S'; q.push( a1 ); }
      if( m.find( a2 ) == m.end() ){ m[a2] = dist; n[a2] = 'E'; q.push( a2 ); }
      if( m.find( a3 ) == m.end() ){ m[a3] = dist; n[a3] = 'W'; q.push( a3 ); }
    }
    string s;
    pair<int,int> d(X,Y);
    while( d.first != 0 || d.second != 0 ){
      //cout << d.first << ',' << d.second << endl;
      s = n[d] + s;
      switch( n[d] ){
        case 'N': d.second -= m[d]; break;
        case 'S': d.second += m[d]; break;
        case 'E': d.first  -= m[d]; break;
        case 'W': d.first  += m[d]; break;
      }
    }
    cout << "Case #" << testcase << ": " << s << endl;
  }
  return 0;
}
