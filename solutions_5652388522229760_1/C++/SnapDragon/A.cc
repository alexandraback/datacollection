#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, T, prob=1;
  for (cin >> T; T--;) {
    cin >> N;
    cout << "Case #" << prob++ << ": ";
    if (N == 0) {
      cout << "INSOMNIA" << endl;
      continue;
    }

    vector<int> seen(10);
    int nseen = 0, x;
    for (x = N; ; x += N) {
      for (int y = x; y; y /= 10) {
        if (!seen[y%10]) {
          seen[y%10] = true;
          nseen++;
        }
      }
      if (nseen == 10) break;
    }
    cout << x << endl;
  }
}
