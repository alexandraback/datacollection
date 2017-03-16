#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool pan[101];
int len;
string raw;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  ll T;
  cin >> T;

  for (int t = 1; t <= T; t++) {
    cin >> raw;
    len = raw.length();
    for (int i = 0; i < len; i++) {
      pan[i] = raw[len-i-1] == '+';
    }

    ll cnt = 0;
    bool trypos = true;

    for (int i = 0; i < len; i++) {
      if (pan[i] ^ trypos) {
        trypos = !trypos;
        cnt++;
      }
    }

    cout << "Case #" << t << ": " << cnt << "\n";
  }

  return 0;
}
