#include <iostream>
#include <string>
#include <vector>

#define pb push_back

using namespace std;

int n;
string mystr;
vector< string > total;

void produce( int idx, string current ) {
  if( idx == n ) {
    total.pb( current );
    return;
  }
  produce( idx + 1, current + mystr[ idx ] );
  string newstr;
  newstr += mystr[ idx ];
  newstr += current;
  produce( idx + 1, newstr );
}

int main( void ) {
  int T;
  freopen("Asmall.in","rt",stdin);
  freopen("Asmall.out","wt",stdout);
  cin >> T;

  for( int t = 1; t <= T; t++ ) {
    cin >> mystr;
    n = mystr.length();
    produce( 0, "" );
    sort( total.begin(), total.end() ) ;
    cout << "Case #" << t << ": " << total[ total.size() - 1 ] << endl;
    total.clear();
  }
  return 0;
}
