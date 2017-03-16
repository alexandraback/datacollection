#include <iostream>
using namespace std;

int main() {

  long long int in_t;
  cin >> in_t;
  for ( long long int for_t = 0; for_t < in_t; for_t++ ) {
    cout << "Case #" << for_t + 1 << ":";

    long long int k, c, s;
    cin >> k >> c >> s;

    if ( ( k + c - 1 ) / c > s ) {
      cout << " IMPOSSIBLE" << endl;
      continue;
    }

    long long int cnt = 1;
    long long int cc = 0;

    for ( long long int i = 1;; i++ ) {

      if ( i > k ) {
	cnt = ( cnt - 1 ) * k + 1;
      }else {
	cnt = ( cnt - 1 ) * k + i;
      }
      cc++;
      if ( cc == c ) {
	cout << " " << cnt;
	if ( i >= k ) break;
	cc = 0;
	cnt = 1;
      }

    }
    cout << endl;

  }

  return 0;

}
