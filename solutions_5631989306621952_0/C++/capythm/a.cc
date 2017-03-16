#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string dfs( string& s, string t ){
  int idx = t.size();
  if( idx == s.size() ) return t;
  string s0 = dfs( s, t + s[idx] ); 
  string s1 = dfs( s, string() + s[idx] + t ); 
  return max( s0, s1 );
}

int main( void )
{
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  for( int testcase=1; testcase<=T; testcase++ ){
    string S;
    cin >> S;
    string ret = dfs(S, "");
    cout << "Case #" << testcase << ": " << ret << endl;
  }
}
