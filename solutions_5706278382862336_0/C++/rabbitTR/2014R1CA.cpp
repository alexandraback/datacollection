#include <iostream>
using namespace std;

int main() {

  int T;

  cin >> T;

  for ( int i = 0; i < T; i++ ) {

    cout << "Case #" << i+1 << ": ";

    long long int p, q;

    char input;

    cin >> p >> input >> q;

    if ( p == 1 && q == 1 ) {

      cout << "0" << endl;
      continue;

    }

    int ans = -1;

    bool flag = true;

    for ( int j = 0; j < 40; j++ ) {

      if ( p * 2 < q ) {

	if ( ( q % 2 ) == 0 ) {
	  q /= 2;
	}else {
	  p *= 2;
	}

	continue;

      }

      if ( ans == -1 ) ans = j + 1;

      if ( p * 2 == q ) {

	cout << ans << endl;
	flag = false;
	break;

      }

      if ( ( q % 2 ) != 0 ) {
	p *= 2;
	q *= 2;
      }
      p -= q / 2;

      if ( ( q % 2 ) == 0 ) {
	q /= 2;
      }else {
	p *= 2;
      }

    }

    if ( flag == true ) cout << "impossible" << endl;

  }

  return 0;

}
