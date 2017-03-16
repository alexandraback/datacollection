#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int A, B, K;
    int r = 0;
    cin >> A >> B >> K;
    for (int i = 0; i < A; i++) {
      for (int j = 0; j < B; j++) {
        if ((i & j) < K) r++;
      }
    }
    cout << "Case #" << t << ": ";
    cout << r << endl;
  }
}