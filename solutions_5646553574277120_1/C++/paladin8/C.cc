#include <iostream>
#include <algorithm>
using namespace std;

int vals[110];

int main() {
  int t; cin >> t;
  for (int c = 1; c <= t; c++) {
    long long k, d, v; cin >> k >> d >> v;
    for (int i = 0; i < d; i++) cin >> vals[i];
    sort(vals, vals + d);

    long long res = 0, miss = 1, didx = 0;
    while (miss <= v) {
      if (didx >= d || vals[didx] > miss) {
        res++;
        miss *= k + 1;
      } else {
        miss += k * vals[didx++];
      }
    }
    cout << "Case #" << c << ": " << res << endl;
  }
  return 0;
}
