#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {

  long long int t;
  cin >> t;

  for ( long long int tt = 0; tt < t; tt++ ) {

    cout << "Case #" << tt+1 << ": ";


    long long int n;
    cin >> n;

    vector< string > v0, v1;

    for ( long long int i = 0; i < n; i++ ) {

      string in0, in1;
      cin >> in0 >> in1;

      v0.push_back( in0 );
      v1.push_back( in1 );

    }

    long long int ans = 0;

    for ( long long int i = 0; i < ( 1 << n ); i++ ) {

      bool f[20] = {};
      long long int cnt = i;
      for ( long long int j = 0; j < n; j++ ) {
	f[j] = cnt % 2;
	cnt /= 2;
      }
      cnt = 0;
      for ( long long int j = 0; j < n; j++ ) {
	if ( f[j] == false ) {
	  bool f0 = false;
	  bool f1 = false;
	  for ( long long int p = 0; p < n; p++ ) {
	    if ( p == j ) continue;
	    if ( v0[j] == v0[p] && f[p] == true ) f0 = true;
	    if ( v1[j] == v1[p] && f[p] == true ) f1 = true;
	  }
	  if ( f0 == false || f1 == false ) {
	    cnt = -1;
	    break;
	  }
	  cnt++;
	}
      }

      if ( cnt < 0 ) continue;
      ans = max( ans, cnt );

    }

    cout << ans << endl;

  }

  return 0;

}
