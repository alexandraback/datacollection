#include <bits/stdc++.h>
using namespace std;

int main() {
  int TT;
  cin >> TT;
  for (int tt = 1; tt <= TT; ++tt) {
    int n;
    cin >> n;
    if (n == 0) {
      cout << "Case #" << tt << ": INSOMNIA" << endl;
      continue;
    }
    vector<bool> a(10, true);
    int count = 0;
    int i = 1;
    while (count < 10) {
      long long x = n * (long long)i;
      while (x>0) {
        int d = x%10;
        x/=10;
        if (a[d]) {
          ++count;
          a[d] = false;
        }
      }
      //cerr << n << " " << i << " " << count << endl;
      i++;
    }
    --i;
    cout << "Case #" << tt << ": " << n*(long long)i << endl;

  }
}
