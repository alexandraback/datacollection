#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  ll T, K, C, S;
  cin >> T;


  for (int t = 1; t <= T; t++) {
    cin >> K >> C >> S;

    cout << "Case #" << t << ": ";

    if (S*C < K) {
      cout << "IMPOSSIBLE\n";
      continue;
    }

    // zero-indexing for convenience
    ll checking = 0;

    while (checking < K) {
      ll curr = checking;
      checking++;
      for (ll i = 1; i < C; i++) {
        if (checking < K)
          curr = K*curr + checking;
        else
          curr = K*curr + (K-1);
        checking++;
      }
      cout << curr+1 << " "; // print with one-indexing
    }
    cout << "\n";
  }

  return 0;
}
