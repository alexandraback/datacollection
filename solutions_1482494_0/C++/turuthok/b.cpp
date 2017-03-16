#include <iostream>
#include <string>

using namespace std;

const int N = 1000;

int a[N];
int b[N];
int f[N];

int main() {
  int cases; cin >> cases;
  for (int caseNo = 1; caseNo <= cases; caseNo++) {
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
    for (int i = 0; i < n; i++) f[i] = 0;

    int res = 0, stars = 0, completed = 0;
    while (true) {
      bool changed = false;
      for (int i = 0; i < n; i++) {
        if (f[i] & 2) continue;
        if (stars >= b[i]) {
          if (f[i] & 1) stars++; else stars += 2;
          f[i] = 3;
          completed++;
          res++;
          changed = true;
        }
      }
      if (changed) continue;

      int pickId = -1, pick = -1;
      for (int i = 0; i < n; i++) {
        if (f[i] & 1) continue;
        if (stars >= a[i]) {
          if (b[i] > pick) pick = b[i], pickId = i;
        }
      }

      if (pickId < 0) break;

      res++;
      stars++;
      f[pickId] = 1;
    }

    cout << "Case #" << caseNo << ": ";
    if (completed < n)
      cout << "Too Bad" << endl;
    else
      cout << res << endl;
  }
  return 0;
}

