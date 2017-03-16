#include <iostream>
#include <iomanip>
#include <queue>

using namespace std;

const int MAXN = 205;

int n;
double t[MAXN], x;

bool safe(int j, double yj) {
  double mi = t[j] + yj * x;
  double r = yj;
  for (int i = 0; i < n; i++) {
    if (i != j) {
      double def = mi - t[i];
      if (def > 0) r += def / x;
    }
  }
  return r > 1;
}

void solve() {
  cin >> n;

  for (int i = 0; i < n; i++)
    cin >> t[i];

  x = 0;
  for (int i = 0; i < n; i++)
    x += t[i];

  for (int i = 0; i < n; i++) {
    double lo = 0, hi = 1;

    for (int j = 0; j < 100; j++) {
      double mi = (lo + hi) / 2;
      if (safe(i, mi)) {
        hi = mi;
      } else {
        lo = mi;
      }
    }
    if (i > 0)
      cout << " ";
    cout << setprecision(10) << lo * 100;
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
}



