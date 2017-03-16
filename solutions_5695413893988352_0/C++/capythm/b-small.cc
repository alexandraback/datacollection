#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<int> vs, vt;
void dfs( string s, int n, int d, vector<int>& v ){
  if( d == s.size() ){
    v.push_back( n ); return;
  }
  if( s[d] != '?' ){
    n = n*10 + s[d] - '0';
    dfs( s, n, d+1, v );
    return;
  }
  for( int i=0; i<10; i++ ){
    dfs( s, n*10+i, d+1, v );
  }
}
int main( void )
{
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  for( int testcase=1; testcase<=T; testcase++ ){
    string S, T;
    cin >> S >> T;
    int N = S.size();
    vs.clear(); vt.clear();
    dfs( S, 0, 0, vs );
    dfs( T, 0, 0, vt );
    int d = 1000, rs = 1000, rt = 1000;
    for( int i=0; i<vs.size(); i++ ){
      for( int j=0; j<vt.size(); j++ ){
        int diff = vs[i] - vt[j];
        if( diff < 0 ) diff = -diff;
        if( diff < d ){ d = diff; rs = vs[i]; rt = vt[j]; }
        if( diff == d && vt[j] < rt ){ rs = vs[i]; rt = vt[j]; }
      }
    }
    int ds = 1;
    if( rs >= 10 ) ds = 2;
    if( rs >= 100 ) ds = 3;
    int dt = 1;
    if( rt >= 10 ) dt = 2;
    if( rt >= 100 ) dt = 3;

    cout << "Case #" << testcase << ": ";
    for( int i=0; i<N-ds; i++ ) cout << 0;
    cout << rs << ' ';
    for( int i=0; i<N-dt; i++ ) cout << 0;
    cout << rt << endl;
  }
}
