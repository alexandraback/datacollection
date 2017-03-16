#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>

using namespace std;

int main() {
  long long T;
  long long A, B, K;
  cin >> T;

  for (long long ii = 1; ii <= T; ii++) {
    cout << "Case #" << ii << ": ";
    cin >> A >> B >> K;
    long long ret = 0;
    for (long long a = 0; a < A; a++) {
      for (long long b = 0; b < B; b++) {
        if ((a & b) < K) {
          ret++;
        }
      }
    }
    cout << ret << endl;
  }
}
