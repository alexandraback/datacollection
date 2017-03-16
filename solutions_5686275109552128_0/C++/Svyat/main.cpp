#include <bits/stdc++.h>
using namespace std;

int T;
int d, p[1001];

void load() {
  cin >> d;
  for (int i = 0; i < d; ++i)
    cin >> p[i];
}

void solve(int tc) {
  int res = 1001;
  for (int mx = 1; mx <= 1000; ++mx) {
    int cur = mx;
    for (int i = 0; i < d; ++i)
      if (p[i] > mx)
	cur += (p[i] - 1) / mx;
    res = min(res, cur);
  }
  assert(res != 1001);
  cout << "Case #" << tc << ": " << res << '\n';
}

void clear() {
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  ios_base::sync_with_stdio(false);
  cin >> T;
  for (int tc = 1; tc <= T; ++tc) {
    load();
    solve(tc);
    clear();
  }
  return 0;
}
