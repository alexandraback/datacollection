#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int nc; cin >> nc; cin.ignore(100, '\n');
  for (int cur = 1; cur <= nc; ++cur) {
    int n; cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i)
      cin >> a[i] >> b[i];

    int stars = 0, played = 0;
    vector<int> earned(n);
    while (stars < 2*n) {
      int nxt = -1, gain = 0, ext = -1;
      for (int i = 0; (gain < 2) && (i < n); ++i)
        if (earned[i] == 0) {
          if (stars >= b[i]) {
            gain = 2; nxt = i;
            }
          else if ((stars >= a[i]) && (b[i]-a[i] > ext)) {
            gain = 1; nxt = i; ext = b[i]-a[i];
            }
          }
        else if ((earned[i] == 1) && (stars >= b[i])) {
          gain = 1; nxt = i; ext = 10000;
          }

      if (nxt == -1) break;

      earned[nxt] += gain; stars += gain; ++played;
      }

    if (stars == 2*n) {
      if (played < n) cout << "too few\n";
      if (played > 2*n) cout << "too many\n";
      cout << "Case #" << cur << ": " << played << '\n';
      }
    else
      cout << "Case #" << cur << ": Too Bad\n";
    }
  }

