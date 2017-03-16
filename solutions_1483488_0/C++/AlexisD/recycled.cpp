#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;

int solve(int A, int B) {
  int res = 0;
  int digits = 0;
  for (int x = A; x > 0; x /= 10) digits++;
  int d10 = 1;
  for (int d = 1; d < digits; d++) d10 *= 10;
  for (int i = A; i < B; i++) {
    int x = i;
    for (int d = 1; d < digits; d++) {
      int r = x % 10;
      x /= 10;
      x += r*d10;
      if (x == i) break;
      if (x > i && x >= A && x <= B) res++;
    }
  }
  return res;
}

int main() {
  int T;
  cin >> T;
  for (int testcase = 0; testcase < T; testcase++) {
    int A, B;
    cin >> A;
    cin >> B;
    int res = solve(A, B);
    cout << "Case #" << testcase + 1 << ": " << res << endl;
  }
  return 0;
}
