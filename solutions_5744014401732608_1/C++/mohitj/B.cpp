#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <numeric>

using namespace std;

int main() {
  int T;
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> T;
  long long int vals[55];
  int ans[55][55] = {0};
  long long int pow2[55] = {0LL, 1LL, 1LL, 2LL};
  for(int i = 4; i < 55; ++i) pow2[i] = 2LL * pow2[i-1];

  for(int cn = 1; cn <= T; ++cn) {
cerr << cn << " of " << T << '\n';
    long long int B, M;
	cin >> B >> M;
	for(int i = 0; i < 55; ++i) for(int j = 0; j < 55; ++j) ans[i][j] = 0;
	for(int i = 1; i < B; ++i) for(int j = i+1; j < B; ++j) ans[i][j] = 1;

	if(M > static_cast<long long int>(1ULL << (B - 2))) {
	  cout << "Case #" << cn << ": IMPOSSIBLE\n";
	  continue;
	}

	long long int v = M;
    for(int i = B - 1; i > 0; --i) {
		if(pow2[i] <= v) {
			vals[i] = v;
			v -= pow2[i];
			ans[i][B] = 1;
		} else vals[i] = 0LL;
	}	

	cout << "Case #" << cn << ": POSSIBLE\n";
	for(int i = 1; i <= B; ++i) {
	  for(int j = 1; j <= B; ++j) cout << ans[i][j];
	  cout << '\n';
	}
  }
}
