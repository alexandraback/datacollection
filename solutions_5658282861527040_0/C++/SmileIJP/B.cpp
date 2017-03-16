#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>

#define ALL(v) v.begin(), v.end()

using namespace std;

template< typename T > T next() {  T tmp; cin >> tmp; return tmp; }


void solve() {
	int a = next< int >();
	int b = next< int >();
	int k = next< int >();

	int res = 0;
	for (int i = 0; i < a; ++i) {
		for (int j = 0; j < b; ++j) {
			res += (i & j) < k ? 1 : 0;
		}
	}
	cout << res << "\n";
}

int main() {

//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);

  int test = next< int >();
  for (int i = 1; i <= test; ++i) {
    printf("Case #%d: ", i);
    solve();
  }

  return 0;
}


