#include <iostream>

using namespace std;

const int N = 1000;
const int INF = 1001;

int a[N];

int main() {
  int t; cin >> t;
  for (int tt = 1; tt <= t; tt++) {
    int n; cin >> n;
    int hi = 0;
    for (int i = 0; i < n; i++) cin >> a[i], hi = max(hi, a[i]);
    int best = INF;
    for (int lim = 1; lim <= hi; lim++) {
      int cost = lim;
      for (int i = 0; i < n; i++) {
        cost += (a[i]-1) / lim;
        if (cost >= best) break;
      }
      best = min(best, cost);
    }
    cout << "Case #" << tt << ": " << best << endl;
  }
  return 0;
}

