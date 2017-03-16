#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

typedef long long ll;

ll solve(ll E, ll R, int N, vector<ll> &v) {
  sort(v.begin(), v.end(), greater<ll>());

  ll ret = 0;
  ret += v[0] * E;

  for (int i = 1; i < N; ++i) {
    ret += v[i] * R;
  }

  return ret;
}

int main(void) {
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    ll E, R;
    int N;
    cin >> E >> R >> N;
    vector<ll> v(N);
    for (int i = 0; i < N; ++i)
      cin >> v[i];

    int ans = solve(E, R, N, v);
    cout << "Case #" << t << ": " << ans << endl;
  }
}
