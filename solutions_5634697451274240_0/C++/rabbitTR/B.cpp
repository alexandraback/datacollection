#include <iostream>
#include <string>
using namespace std;

int main() {

  long long int in_t;
  cin >> in_t;
  for ( long long int for_t = 0; for_t < in_t; for_t++ ) {
    cout << "Case #" << for_t + 1 << ": ";

    string in;
    cin >> in;

    in += '+';

    long long int ans = 0;

    for ( long long int i = in.size() - 2; i >= 0; i-- ) {

      if ( in[i] != in[i+1] ) ans++;

    }

    cout << ans << endl;

  }

  return 0;

}
