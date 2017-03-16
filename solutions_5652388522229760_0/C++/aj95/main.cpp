// :)
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

#define N 100

set<int> s;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("/Users/Ayur/Downloads/A-small-attempt0.in.txt","r",stdin);
  freopen("/Users/Ayur/Downloads/A-small.txt","w",stdout);
  int t, tt;
  ll i, j, k, n;
  cin >> tt;
  for (t = 1; t <= tt; t++) {
    cout << "Case #" << t << ": ";
    cin >> n;
    if (n == 0) {
      cout << "INSOMNIA\n";
      continue;
    }
    k = -1;
    s.clear();
    for (i = 1; i <= N; i++) {
      j = i * n;
      while (j > 0) {
        s.insert(j % 10);
        j /= 10;
      }
      if ((int)s.size() == 10) {
        k = i * n;
        break;
      }
    }
    if (k != -1) {
      cout << k << '\n';
    } else {
      cout << "INSOMNIA\n";
    }
  }
  return 0;
}