#include <iostream>
#include <string>
using namespace std;

int main() {

  long long int t;
  cin >> t;

  for ( long long int tt = 0; tt < t; tt++ ) {

    cout << "Case #" << tt+1 << ": ";


    string s;
    cin >> s;

    long long int ans[10] = {};
    long long int cnt[26] = {};

    for ( long long int i = 0; i < s.size(); i++ ) {

      cnt[ s[i] - 'A' ]++;

    }

    char d[10] = { 'Z', 'W', 'G', 'U', 'H', 'F', 'V', 'O', 'S', 'E' };
    long long int dc[10] = { 0, 2, 8, 4, 3, 5, 7, 1, 6, 9 };
    string z[10] = { "ZERO", "TWO", "EIGHT", "FOUR", "THREE", "FIVE", "SEVEN", "ONE", "SIX", "NINE" };


    for ( long long int i = 0; i < 10; i++ ) {

      ans[ dc[i] ] = cnt[ d[i] - 'A' ];
      for ( long long int x = 0; x < ans[ dc[i] ]; x++ ) {
	for ( long long int j = 0; j < z[i].size(); j++ ) {
	  cnt[ z[i][j] - 'A' ]--;
	}
      }

    }

    for ( long long int i = 0; i < 10; i++ ) {

      for ( long long int j = 0; j < ans[i]; j++ ) {
	cout << i;
      }

    }


    cout << endl;

  }

  return 0;

}
