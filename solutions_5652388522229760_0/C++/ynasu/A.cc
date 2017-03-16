#include <iostream>
#include <string>

using namespace std;

namespace {

string Solve(int N) {
  if (N == 0) return "INSOMNIA";
  int left = (1 << 10) - 1;
  for (long long i = 1; ; ++i) {
    long long n = i * N;
    while (n) {
      left &= ~(1 << (n % 10));
      n /= 10;
    }
    if (left == 0) return to_string(i * N);
  }
}

}

int main(void) {
  int T;
  cin >> T;
  for (int i = 1; i <= T; ++i) {
    int N;
    cin >> N;
    cout << "Case #" << i << ": " << Solve(N) << endl;
  }

  return 0;
}
