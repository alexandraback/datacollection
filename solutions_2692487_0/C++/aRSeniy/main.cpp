#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <bitset>
#include <cstdio>
#include <queue>

using namespace std;

void precalc () {

}

void solve () {
  int A, n;
  cin >> A >> n;

  vector <int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }

  if (A == 1) {
    cout << n << endl;
    return;
  }

  sort(v.begin(), v.end());

  vector <int> a(n, 0);

  for (int i = 0; i < n; ++i) {
    if (v[i] < A) {
      A += v[i];
    } else {
      while (A <= v[i]) {
        A += A - 1;
        ++a[i];
      }
      A += v[i];
    }
  }

  int ans = 1e9;
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    int res = sum + n - i;
    if (res < ans) {
      ans = res;
    }
    sum += a[i];
  }
  if (sum < ans) {
    ans = sum;
  }
  
  cout << ans << endl;
}

int main() {
	freopen("A-small-attempt1.in","r",stdin);
	freopen("output.txt","w",stdout);

  precalc();

	int T;
	cin >> T;
	for (int test = 1; test <= T; ++test) {
		cout << "Case #" << test << ": ";
    
    solve();
	}
	return 0;
}
