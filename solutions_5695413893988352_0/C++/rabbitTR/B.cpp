#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {

  long long int t;
  cin >> t;

  for ( long long int tt = 0; tt < t; tt++ ) {

    cout << "Case #" << tt+1 << ": ";


    string c, j;
    cin >> c >> j;

    vector< pair< long long int, pair< string, string > > > v;

    for ( long long int ppp = 0; ppp < 2; ppp++ ) {

      string cc = c;
      string jj = j;

      bool f = true;

      for ( long long int i = 0; i < c.size(); i++ ) {

	if ( cc[i] != '?' && jj[i] != '?' ) {
	  if ( cc[i] >  jj[i] ) {
	    f = false;
	    break;
	  }
	  if ( cc[i] == jj[i] ) continue;

	  string ccc = cc;
	  string jjj = jj;
	  long long int k = jj[i] - cc[i];
	  for ( long long int p = i + 1; p < c.size(); p++ ) {
	    if ( ccc[p] == '?' ) ccc[p] = '9';
	    if ( jjj[p] == '?' ) jjj[p] = '0';
	    k = k * 10 + ( jjj[p] - ccc[p] );
	  }
	  if ( ppp == 1 ) {
	    swap( ccc, jjj );
	  }
	  v.push_back( make_pair( k, make_pair( ccc, jjj ) ) );
	  f = false;
	  break;

	}

	if ( cc[i] == '?' && jj[i] == '?' ) {
	    string ccc = cc;
	    string jjj = jj;
	    ccc[i] = '0';
	    jjj[i] = '1';
	    long long int k = jjj[i] - ccc[i];
	    for ( long long int p = i + 1; p < c.size(); p++ ) {
	      if ( ccc[p] == '?' ) ccc[p] = '9';
	      if ( jjj[p] == '?' ) jjj[p] = '0';
	      k = k * 10 + ( jjj[p] - ccc[p] );
	    }
	    if ( ppp == 1 ) {
	      swap( ccc, jjj );
	    }
	    v.push_back( make_pair( k, make_pair( ccc, jjj ) ) );
	  cc[i] = '0';
	  jj[i] = '0';
	  continue;
	}
	if ( cc[i] == '?' ) {
	  if ( jj[i] > '0' ) {
	    string ccc = cc;
	    string jjj = jj;
	    ccc[i] = jjj[i] - 1;
	    long long int k = jjj[i] - ccc[i];
	    for ( long long int p = i + 1; p < c.size(); p++ ) {
	      if ( ccc[p] == '?' ) ccc[p] = '9';
	      if ( jjj[p] == '?' ) jjj[p] = '0';
	      k = k * 10 + ( jjj[p] - ccc[p] );
	    }
	    if ( ppp == 1 ) {
	      swap( ccc, jjj );
	    }
	    v.push_back( make_pair( k, make_pair( ccc, jjj ) ) );
	  }
	  cc[i] = jj[i];
	  continue;
	}

	  if ( cc[i] < '9' ) {
	    string ccc = cc;
	    string jjj = jj;
	    jjj[i] = ccc[i] + 1;
	    long long int k = jjj[i] - ccc[i];
	    for ( long long int p = i + 1; p < c.size(); p++ ) {
	      if ( ccc[p] == '?' ) ccc[p] = '9';
	      if ( jjj[p] == '?' ) jjj[p] = '0';
	      k = k * 10 + ( jjj[p] - ccc[p] );
	    }
	    if ( ppp == 1 ) {
	      swap( ccc, jjj );
	    }
	    v.push_back( make_pair( k, make_pair( ccc, jjj ) ) );
	  }
	  jj[i] = cc[i];
	  continue;

      }

      if ( f == true ) {
	v.push_back( make_pair( 0, make_pair( cc, jj ) ) );
      }

      swap( c, j );

    }

    sort( v.begin(), v.end() );

    cout << v[0].second.first << " " << v[0].second.second << endl;

  }

  return 0;

}
