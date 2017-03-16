#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;

double solve(int A, int B, vector<double> &p) {
  double res;
  res = B + 2;
  double pi = 1;
  for (int i = 1; i <= A; i++) {
    pi *= p[i-1];
    double x = (2*(A-i) + (B - A) + 1) + (1 - pi)*(B + 1);
    res = min(res, x);
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
    vector<double> p(A);
    for (int i = 0; i < A; i++) {
      cin >> p[i];
    }
    double res = solve(A, B, p);
    cout << setprecision(10) << "Case #" << testcase + 1 << ": " << res << endl;
  }
  return 0;
}
