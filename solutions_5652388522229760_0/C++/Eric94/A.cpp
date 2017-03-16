#include <iostream>
#include <vector>
using namespace std;

vector <bool> seen;

bool all_seen() {
  for (int i = 0; i < 10; ++i) {
    if (not seen[i]) return false;
  }
  return true;
}

void update (int n) {
  if (n < 10) {
    seen[n] = true;
    return;
  }

  seen[n%10] = true;
  update(n/10);
}

void solve() {
  int N;
  cin >> N;
  if (N == 0) {
    cout << " INSOMNIA";
    return;
  }
  seen = vector <bool> (10, false);

  update(N);
  int ans = N;
  while (not all_seen()) {
    ans += N;
    update(ans);
  }

  cout << ' ' << ans;

}

int main() {
  int T;
  cin >> T;
  for (int i = 0; i < T; ++i) {
    cout << "Case #" << i + 1 << ":";
    solve ();
    cout << endl;
  }
}
