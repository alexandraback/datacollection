#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef long long int64;
#define debug(x) cerr << #x << " = " << (x) << endl;

int64 solve1() {
  int64 E, R;
  int N;
  cin >> E >> R >> N;
  vector<int64> v(N);
  for (int i=0; i<N; ++i) {
    cin >> v[i];
  }
  int64 e = E;
  int64 ans = 0;
  for (int i=0, j; i<N; ++i) {
    int64 x = 0;
    for (j=i+1; j<N; ++j) {
      if (v[j] > v[i]) {
        break;
      }
    }
    if (j == N) {
      x = e;
    } else {
      int d = j-i;
      x = e + d*R - E;
      x = max(0LL, x);
      x = min(e, x);
    }

    ans += x * v[i];
    e -= x;
    e += R;
  }
  return ans;
}

int main() {
  cin.sync_with_stdio(0);

  int T;
  cin >> T;
  for (int tt=1; tt<=T; ++tt) {
    cout << "Case #" << tt << ": " << solve1() << '\n';
  }
  
  return 0;
}
