#include <iostream>
using namespace std;

int main() {

  long long int in_t;
  cin >> in_t;
  for ( long long int for_t = 0; for_t < in_t; for_t++ ) {
    cout << "Case #" << for_t + 1 << ": ";

    long long int n;
    cin >> n;

    if ( n == 0 ) {
      cout << "INSOMNIA" << endl;
      continue;
    }

    bool f[10] = {};
    long long int cnt = 0;

    for ( long long int i = 1;; i++ ) {

      long long int k = n * i;
      while( k > 0 ) {

	long long int m = k % 10;
	if ( f[m] == false ) {
	  f[m] = true;
	  cnt++;
	}
	k /= 10;

      }

      if ( cnt == 10 ) {
	cout << n * i << endl;
	break;
      }

    }


  }

  return 0;

}
