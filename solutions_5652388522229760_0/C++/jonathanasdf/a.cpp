#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  int T; cin >> T;
  for (int zz=1; zz <= T; zz++) {
    cout << "Case #" << zz << ": ";
    ll N; cin >> N;
    bool seen[10]; memset(seen, 0, sizeof seen);
    for (int i=1; i < 100000; i++) {
      ll x = N*i;
      while(x) {
        seen[x%10] = true;
        x/=10;
      }
      bool done = true;
      for (int j=0; j < 10; j++) {
        if (!seen[j]) done = false;
      }
      if (done) {
        cout << N*i << endl;
        break;
      }
    }
    bool done = true;
    for (int j=0; j < 10; j++) {
      if (!seen[j]) done = false;
    }
    if (!done) cout << "INSOMNIA" << endl;
  }
  return 0;
}
