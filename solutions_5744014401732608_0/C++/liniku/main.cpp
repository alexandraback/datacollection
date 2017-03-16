#include <iostream>
#include <vector>
using namespace std;

typedef long long int LLI;

int B;
LLI M;

void solve() {
  vector<bool> v;
  v.resize(B - 1);
  for (int i = 0; i < B - 1; ++i) {
    v[i] = false;
  }

  LLI t = M;
  if (t > (1LL << (B - 2))) {
    cout << "IMPOSSIBLE" << endl;
    return;
  }

  if (t > 0) {
    v[0] = true;
    --t;
  }
  int p = 1;
  while (t) {
    v[p++] = t & 1;
    t >>= 1;
  }

  cout << "POSSIBLE" << endl;
  for (int i = 0; i < B; ++i) {
    for (int j = 0; j < B; ++j) {
      if (i >= j) {
        cout << "0";
      } else if (j != B - 1) {
        cout << "1";
      } else {  // j == B - 1
        cout << (v[i] ? 1 : 0);
      }
    }
    cout << endl;
  }
}

int main() {
  int T;
  cin >> T;
  for (int i = 0; i < T; ++i) {
    cin >> B >> M;
    cout << "Case #" << i + 1 << ": ";
    solve();
  }
}
