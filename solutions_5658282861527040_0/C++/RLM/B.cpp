#include <iostream>
using namespace std;

#define f(x, y) for (int x = 0; x < (int)y; ++x)

int solve() {
  int A, B, K, r = 0; cin >> A >> B >> K;
  f(i, A) f(j, B) if ((i&j) < K) ++r;
  return r;
}

int main() {
  int T; cin >> T;
  for (int C = 1; C <= T; ++C) {
    cout << "Case #" << C << ": " << solve() << endl;
  }
}
