#include <iostream>
using namespace std;

int main() {

  long long int in_t;
  cin >> in_t;
  for ( long long int for_t = 0; for_t < in_t; for_t++ ) {
    cout << "Case #" << for_t + 1 << ":";

    long long int k, c, s;
    cin >> k >> c >> s;

    for ( long long int i = 0; i < k; i++ ) {

      cout << " " << i + 1;

    }
    cout << endl;

  }

  return 0;

}
