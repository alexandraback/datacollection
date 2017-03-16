#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <ctime>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>

#define sz(c) ((int)(c).size())
#define all(c) (c).begin(), (c).end()

using namespace std;
typedef long long ll;

void testCase()
{
  int n;
  cin >> n;

  vector<int> d(n);
  for (auto& x : d) {
    cin >> x;
  }

  int ans = *max_element(all(d));
  for (int k = ans - 1; k >= 1; k--) {
    int splits = 0;
    for (auto x : d) {
      splits += (x + k - 1) / k - 1;
    }
    ans = min(ans, splits + k);
  }
  cout << ans << endl;
}

int main() {
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": ";
    testCase();
  }
  return 0;
}
