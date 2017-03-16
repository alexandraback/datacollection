#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int ans;

void solve(vector<int> p, int m) {
  int cans = 0;
  sort(p.rbegin(), p.rend());
  while(p[0]>m) {
    ++cans;
    p[0] -= m;
    p.push_back(m);
    sort(p.rbegin(), p.rend());
  }
  ans = min(ans, cans+p[0]);
}

int t;
int main() {
  freopen("b1.in", "r", stdin);
  freopen("b1.out", "w", stdout);
  cin >> t;
  for (int x = 1; x <= t; x++) {
    int d; cin >> d;
    vector<int> p(d);
    for (int i = 0; i < d; i++) cin >> p[i];
    ans = 1e9;
    for (int i = 1; i <= 9; i++) {
      solve(p, i);
    }
    cout << "Case #" << x << ": " << ans << endl;
  }
}
