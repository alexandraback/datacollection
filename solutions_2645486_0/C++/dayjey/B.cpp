#include <iostream>

using namespace std;

int e, r, n, m;
int v[10000];

void best(int pos, int lev, int val) {
  if (lev > e) lev = e;
  
  if (pos == n) {
    if (val > m)
      m = val;
  }
  else {
    int start = lev + r - e;
    if (start < 0) start = 0;
    for (int i = start; i <= lev; i++) {
      best(pos+1, lev-i+r, val + i*v[pos]);
    }
  }
}

int main() {
  int tc; cin >> tc;
  for (int t = 1; t <= tc; t++) {
    cin >> e >> r >> n;
    for (int i = 0; i < n; i++)
      cin >> v[i];

    if (r > e) r = e;
    m = 0;
    best(0, e, 0);
    cout << "Case #" << t << ": ";
    cout << m;
    cout << endl;
  }

  return 0;
}
