#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;
typedef unsigned long long ll;
typedef map<ll, int> MLLI;

ll reverse(ll n) {
  ll x = 0;
  while (n) {
    x *= 10;
    x += n%10;
    n /= 10;
  }
  return x;
}

int main() {
  int T; cin >> T;
  int ncase = 0;
  while (T--) {
    ll n; cin >> n;
    queue<ll> q;
    MLLI dist;
    dist[1] = 1;
    if (n != 1) q.push(1);
    int ans = 1;
    while (!q.empty()) {
      ll u = q.front(); q.pop();
      int d = dist[u];
      ll nu = u+1, ru = reverse(u);
      if (nu == n || ru == n) {
        ans = d+1;
        break;
      }
      auto it = dist.find(nu);
      if (it == dist.end()) {
        dist[nu] = d+1;
        q.push(nu);
      }
      it = dist.find(ru);
      if (it == dist.end()) {
        dist[ru] = d+1;
        q.push(ru);
      }
    }
    cout << "Case #" << ++ncase << ": " << ans << endl;
  }
}
