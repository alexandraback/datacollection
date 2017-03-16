#include <iostream>
using namespace std;

int main() {

  int T;

  cin >> T;

  for ( int i = 0; i < T; i++ ) {

    cout << "Case #" << i+1 << ": ";

    long long int n, m, k;

    cin >> n >> m >> k;;

    long long int ans = n * m;

    for ( int p = 0; p < 2; p++ ) {

      for ( long long int y = 1; y <= n; y++ ) {

	if ( y > m ) break;
	if ( y == 1 ) {
	  if ( k <= m ) ans = min( ans, k );
	}else if ( y == 2 ) {
	  if ( k <= m * 2 ) ans = min( ans, k );
	}else {
	  if ( ( y % 2 ) == 0 ) {
	    long long int num = y * 2;
	    long long int cnt = ( 1 + y / 2 ) * y;
	    long long int x = y;
	    if ( k <= cnt ) {

	      cnt = y;
	      num = y;

	      for ( long long int j = 0; true; j++ ) {

		if ( k <= cnt ) {
		  ans = min( ans, num );
		  break;
		}

		num++;
		if ( ( y / 2 - 1 ) * 2 >= ( j / 2 + 1 ) * 2 ) {
		  cnt += ( ( j / 2 + 1 ) * 2 );
		}else {
		  cnt += y / 2;
		}

	      }

	    }else {

	      while( true ) {

		if ( k <= cnt + y && x != m ) {
		  if ( k <= cnt + y / 2 ) {
		    ans = min( ans, num + 1 );
		    break;
		  }else {
		    ans = min( ans, num + 2 );
		    break;
		  }
		}else {
		  if ( x == m ) {
		    for ( long long int j = ( y / 2 - 1 ); j >= 0; j-- ) {
		      if ( k <= cnt + j * 4 ) {
			if ( k != cnt ) {
			  num += ( ( k - cnt - 1 ) / j + 1 );
			}
			ans = min( ans, num );
			break;
		      }
		      cnt += j * 4;
		      num += 4;
		    }
		    break;
		  }else {
		    x++;
		    cnt += y;
		    num += 2;
		  }
		}

	      }

	    }

	  }else {

	    long long int num = y * 2 - 2;
	    long long int cnt = ( 1 + y / 2 ) * ( 2 + y / 2 ) * 2 - 2 * y - 1;
	    long long int x = y;
	    if ( k <= cnt ) {

	      cnt = y;
	      num = y;

	      for ( long long int j = 0; true; j++ ) {

		if ( k <= cnt ) {
		  ans = min( ans, num );
		  break;
		}

		num++;
		cnt += ( ( j / 2 + 1 ) * 2 );

	      }

	    }else {

	      while( true ) {

		if ( k <= cnt + y && x != m ) {
		  if ( k <= cnt + ( y / 2 ) ) {
		    ans = min( ans, num + 1 );
		    break;
		  }else {
		    ans = min( ans, num + 2 );
		    break;
		  }
		}else {
		  if ( x == m ) {
		    for ( long long int j = ( y / 2 ); j >= 0; j-- ) {
		      if ( k <= cnt + j * 4 ) {
			if ( k != cnt ) {
			  num += ( ( k - cnt - 1 ) / j + 1 );
			}
			ans = min( ans, num );
			break;
		      }
		      cnt += j * 4;
		      num += 4;
		    }
		    break;
		  }else {
		    x++;
		    cnt += y;
		    num += 2;
		  }
		}

	      }

	    }
	  }

	}

      }

      long long int a = m;
      m = n;
      n = a;

    }

    cout << ans << endl;

  }

}
