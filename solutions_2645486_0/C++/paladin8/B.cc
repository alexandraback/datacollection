#include <iostream>
#include <queue>
using namespace std;

long long v[10100], nxt[10100];

int main() {
  int t; cin >> t;
  for (int c = 1; c <= t; c++) {
    long long e, r, n; cin >> e >> r >> n;
    for (int i = 0; i < n; i++) cin >> v[i];

    priority_queue<pair<long long, int> > pq;
    for (int i = 0; i < n; i++) {
      while (!pq.empty() && pq.top().first > -v[i]) {
        int prev = pq.top().second; pq.pop();
        nxt[prev] = i;
      }
      pq.push(make_pair(-v[i], i));
    }

    while (!pq.empty()) {
      int prev = pq.top().second; pq.pop();
      nxt[prev] = -1;
    }

    long long res = 0, cur = e;
    for (int i = 0; i < n; i++) {
      long long use;
      if (nxt[i] == -1) use = cur;
      else use = max(0LL, cur - max(0LL, e-(nxt[i]-i)*r));

      res += use * v[i];
      cur += r - use;
    }
    cout << "Case #" << c << ": " << res << endl;
  }
  return 0;
}
