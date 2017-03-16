#include <iostream>
#include <vector>
using namespace std;

int cycle(int n, int k, int digits) {
  int mul = 1, mul2 = 1;
  for (int i = 0; i < k; i++) mul *= 10;
  for (int i = 0; i < digits - k; i++) mul2 *= 10;
  return (n / mul) + (n % mul) * mul2;
}

int digits(int n) {
  int res = 0;
  while (n > 0) {
    res++;
    n /= 10;
  }
  return res;
}

int solve(int A, int B) {
  int ans = 0;
  for (int i = A; i <= B; i++) {
    int d = digits(A);
    vector<int> v;
    for (int j = 1; j < d; j++) {
      int n = cycle(i, j, d);
      if (n > i && n <= B && find(v.begin(), v.end(), n) == v.end()) {
        ans++;
        v.push_back(n);
      }
    }
  }
  return ans;
}

int main() {
  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    int A, B;
    cin >> A >> B;
    int answer = solve(A, B);
    cout << "Case #" << t << ": " << answer << endl;
  }
}

