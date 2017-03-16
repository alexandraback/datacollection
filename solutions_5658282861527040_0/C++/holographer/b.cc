#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int A, B, K;

    cin >> A >> B >> K;

    long long num_pairs = 0;
    for (int a = 0; a < A; a++) {
      for (int b = 0; b < B; b++) {
        if ((a & b) < K) {
          num_pairs++;
        }
      }
    }

    cout << "Case #" << t << ": ";

    cout << num_pairs;

    cout << endl;

  }

  return 0;
}
