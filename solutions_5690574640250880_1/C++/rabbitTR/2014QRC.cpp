#include <iostream>
using namespace std;

int main() {

  int T;

  cin >> T;

  /*
  T = 999;
  int R, C, M;
  R = 1;
  C = 1;
  M = -1;
  */

  for ( int i = 0; i < T; i++ ) {

    cout << "Case #" << i+1 << ":" << endl;

    /*
    M++;
    if ( M == R * C ) {
      M = 0;
      C++;
      if ( C == 6 ) {
	C = 1;
	R++;
	if ( R == 6 ) break;
      }
    }
    cout << "R = " << R << endl << "C = " << C << endl << "M = " << M << endl;
    */

    int R, C, M;

    cin >> R >> C >> M;

    int B = R * C - M;

    if ( B == 1 ) {

      for ( int j = 0; j < R; j++ ) {

	for ( int k = 0; k < C; k++ ) {

	  if ( j == 0 && k == 0 ) {
	    cout << "c";
	  }else {
	    cout << "*";
	  }

	}

	cout << endl;

      }

      continue;

    }

    if ( R == 1 ) {

      cout << "c";

      for ( int j = 0; j < B-1; j++ ) {

	cout << ".";

      }

      for ( int j = 0; j < M; j++ ) {

	cout << "*";

      }

      cout << endl;

      continue;

    }

    if ( C == 1 ) {

      cout << "c" << endl;

      for ( int j = 0; j < B-1; j++ ) {

	cout << "." << endl;

      }

      for ( int j = 0; j < M; j++ ) {

	cout << "*" << endl;

      }

      continue;

    }

    if ( R == 2 ) {

      if ( ( M % 2 ) != 0 || B == 2 ) {

	cout << "Impossible" << endl;

      }else {

	for ( int j = 0; j < 2; j++ ) {

	  if ( j == 0 ) {
	    cout << "c";
	  }else {
	    cout << ".";
	  }

	  for ( int k = 1; k < B / 2; k++ ) {
	    cout << ".";
	  }
	  for ( int k = 0; k < M / 2; k++ ) {
	    cout << "*";
	  }

	cout << endl;

	}

      }

      continue;

    }

    if ( C == 2 ) {

      if ( ( M % 2 ) != 0 || B == 2 ) {

	cout << "Impossible" << endl;

      }else {

	cout << "c." << endl;

	for ( int k = 1; k < B / 2; k++ ) {
	  cout << ".." << endl;
	}
	for ( int k = 0; k < M / 2; k++ ) {
	  cout << "**" << endl;
	}

      }

      continue;

    }

    if ( B == 2 ) {

      cout << "Impossible" << endl;

      continue;

    }

    if ( B >= C * 2 && B != C * 2 + 1 ) {

      for ( int j = 0; j < R; j++ ) {

	for ( int k = 0; k < C; k++ ) {

	  if ( B > 0 ) {
	    if ( k == C - 1 && B == 2 ) {
	      cout << "*";
	    }else {
	      B--;
	      if ( j == 0 && k == 0 ) {
		cout << "c";
	      }else {
		cout << ".";
	      }
	    }
	  }else {
	    cout << "*";
	  }

	}

	cout << endl;

      }

      continue;

    }

    if ( ( B % 2 ) == 0 ) {

      for ( int j = 0; j < R; j++ ) {

	for ( int k = 0; k < C; k++ ) {

	  if ( j < 2 && k < B / 2 ) {
	    if ( j == 0 && k == 0 ) {
	      cout << "c";
	    }else {
	      cout << ".";
	    }
	  }else {
	    cout << "*";
	  }

	}

	cout << endl;

      }

      continue;

    }

    if ( B <= 7 ) {

      cout << "Impossible" << endl;

      continue;

    }

    for ( int j = 0; j < R; j++ ) {

      for ( int k = 0; k < C; k++ ) {

	if ( j < 2 && k < ( B - 3 ) / 2 ) {
	  if ( j == 0 && k == 0 ) {
	    cout << "c";
	  }else {
	    cout << ".";
	  }
	}else {
	  if ( j == 2 && k < 3 ) {
	    cout << ".";
	  }else {
	    cout << "*";
	  }
	}

      }

      cout << endl;

    }

    continue;

  }

  return 0;

}
