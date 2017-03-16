#include <iostream>
#include <iomanip>
#include <queue>

using namespace std;

const int MAXN = 20;

int n, a[MAXN];

const int MAXS = 2000000;

int ans1, ans2;
int seen[MAXS + 1];

void go(int i, int s, int m) {
  if (seen[s] != -1 && seen[s] != m) {
    ans1 = m;
    ans2 = seen[s];
    return;
  } else {
    seen[s] = m;
  }

  if (i < n) {
    go(i + 1, s, m);
    go(i + 1, s + a[i], m | (1 << i));
  }
}

void print(int m) {
  bool first = true;
  for (int i = 0; i < n; i++) {
    if (m & (1 << i)) {
      if (!first) cout << " ";
      cout << a[i];
      first = false;
    }
  }
  cout << "\n";
}

void solve() {
  cin >> n;

  for (int i = 0; i < n; i++)
    cin >> a[i];

  for (int i = 0; i <= MAXS; i++)
    seen[i] = -1;

  ans1 = ans2 = -1;
  go(0, 0, 0);

  if (ans1 != -1) {
    int common = ans1 & ans2;
    ans1 ^= common;
    ans2 ^= common;
    
    print(ans1);
    print(ans2);
  } else {
    cout << "Impossible\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case #" << i << ":\n";
    solve();
  }
}




