#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
  int T;

  cin >> T;

  for (int cas = 1; cas <= T; cas++) {
    int N, X, Y;
    
    cin >> N >> X >> Y;

    int n = 0;
    int sum = 0;

    while (sum + n + n + 1 <= N) {
      sum += n + n + 1;
      n += 2;
    }
    // sum <= N < sum+n+n+1
    // n = 0, sum = 0  0 <= N < 1
    // n = 2, sum = 1  1 <= N < 6
    // n = 4, sum = 6  6 <= N < 15

    int col = Y + (X < 0 ? -X : X);
    //cout << N << ", " << n << ", " << sum << ", " << col << endl;
    double result;

    if (col < n) {
      result = 1.0;
    } else if (col > n) {
      result = 0.0;
    } else {
      int rest = N - sum;
      int tot = 1 << rest;
      int cnt = 0;
      if (X < 0) X = -X;
      int x = n - X;
      for (int idx = 0; idx < tot; idx++) {
        int l = 0;
        int r = 0;
        for (int i = 0; i < rest; i++) {
          if (idx & (1 << i)) {
            if (l == n) r++;
            else l++;
          } else {
            if (r == n) l++;
            else r++;
          }
        }
        //cout << "(" << l << ", " << r << ")" << endl;
        if (r > x) cnt++;
      }
      result = (double)cnt / tot;
    }
    cout << "Case #" << cas << ": " << setprecision(10) << result  << endl;
  }

  return 0;
}

