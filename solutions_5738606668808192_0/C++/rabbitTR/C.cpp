#include <iostream>
#include <vector>
using namespace std;

bool f[100001] = {};

int main() {

  vector< long long int > v;
  for ( long long int i = 2; i < 100000; i++ ) {
    if ( f[i] == false ) {
      v.push_back( i );
      for ( long long int j = 2; i*j < 100000; j++ ) {
	f[i*j] = true;
      }
    }
  }

  long long int in_t;
  cin >> in_t;
  for ( long long int for_t = 0; for_t < in_t; for_t++ ) {
    cout << "Case #" << for_t + 1 << ":" << endl;

    long long int n, j;
    cin >> n >> j;

    long long int m = -1;

    long long int ans = 0;

    while( ans < j ) {

      m++;
      long long int k = ( 1 << ( n - 1 ) ) + ( m << 1 ) + 1;

      long long int a[11] = {};
      long long int f = 0;

      for ( long long int i = 2; i <= 10; i++ ) {

	for ( long long int p = 0; p < 1000; p++ ) {

	  long long int b = 0;
	  long long int r = 1;

	  for ( long long int q = 0; q < n; q++ ) {
	    long long int h = ( 1 << q );
	    if ( ( k & h ) != 0 ) {
	      b += r;
	      b %= v[p];
	    }
	    r *= i;
	    r %= v[p];
	  }

	  if ( b == 0 ) {
	    a[i] = v[p];
	    f++;
	    break;
	  }

	}

      }

      if ( f == 9 ) {
	for ( long long int i = 0; i < n; i++ ) {
	  long long int p = ( 1 << ( n - 1 - i ) );
	  if ( ( k & p ) != 0 ) {
	    cout << 1;
	  }else {
	    cout << 0;
	  }
	}
	for ( long long int i = 2; i <= 10; i++ ) {
	  cout << " " << a[i];
	}
	cout << endl;
	ans++;
      }

    }

  }

  return 0;

}
