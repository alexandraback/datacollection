#include <iostream>
#include <algorithm>
using namespace std;

int p[1000];

int main() {
  int t; cin >> t;
  for (int T = 1; T <= t; T++) {
    int d; cin >> d;
    int mx = 0;
    for (int i = 0; i < d; i++) {
      cin >> p[i];
      mx = max(mx,p[i]);
    }
    int mn = 42424242;
    for (int i = 1; i <= mx; i++) {
      int mni = 0;
      for (int j = 0; j < d; j++)
        mni += (p[j]+i-1)/i-1;
      mni += i;
      mn = min(mn,mni);
    }
    cout << "Case #" << T << ": " << mn << "\n";
  }
  return 0;
}
