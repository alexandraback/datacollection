#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;

ll powLog(ll b, ll p) {
  if (p == 0) return 1;
  ll ret = powLog(b, p / 2);
  ret *= ret;
  if (p & 1) ret *= b;
  return ret;
}

ll K, C, S;

bool isInvalid() {
  if (C == 1) return S < K;
  int needed = K / 2 + (K & 1);
  return S < needed;
}

vector< ll > ans;

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.in", "r", stdin);
  freopen("in.out", "w", stdout);
#endif
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ":";
    cin >> K >> C >> S;

    if (isInvalid()) {
      cout << " IMPOSSIBLE" << endl;
    } else {
      ans.clear();
      if (C == 1) {
        for (int i = 0; i < K; i++) {
          ans.push_back(i);
        }
      } else {
        int needed = K / 2 + (K & 1);
        int half = K / 2;
        ll _power = powLog(K, C - 1);
        for (int i = 0; i < half; i++) {
          ans.push_back(i * _power + (i + half));
        }
        if (K & 1) {
          ans.push_back((K - 1) * _power);
        }
        assert(ans.size() == needed);
      }
      for(int i = 0; i < ans.size(); i++) {
        cout << " " << ans[i] + 1;
      }
      cout << endl;
    }
  }

  return 0;
}
