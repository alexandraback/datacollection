#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int ans;

void solve(vector<int> &p, int m) {
  priority_queue<int> pq(p.begin(), p.end());
  int cans = 0;
  while(pq.top()>m) {
    ++cans;
    if (cans >= ans) break;
    int tmp = pq.top();
    pq.pop(); pq.push(tmp-m);
  }
  ans = min(ans, cans+m);
}

int t;
int main() {
  freopen("b2.in", "r", stdin);
  freopen("b.out", "w", stdout);
  cin >> t;
  for (int x = 1; x <= t; x++) {
    int d; cin >> d;
    vector<int> p(d);
    for (int i = 0; i < d; i++) cin >> p[i];
    sort(p.rbegin(), p.rend());
    ans = 1e9;
    for (int i = p[0]; i >= 1; i--) {
      solve(p, i);
    }
    cout << "Case #" << x << ": " << ans << endl;
  }
}
