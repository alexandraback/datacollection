#include <iostream>
#include <vector>
using namespace std;

int main() {
  int T;
  cin >> T;
  for (int x = 1; x <= T; x++) {
    int N;
    cin >> N;
    vector<int> a;
    vector<int> b;
    vector<int> s;
    for (int i = 0; i < N; i++) {
      int ai, bi;
      cin >> ai >> bi;
      a.push_back(ai);
      b.push_back(bi);
      s.push_back(0);
    }
    int y = 0;
    int S = 0;
    while (S < 2 * N) {
      int p = -1;
      for (int i = 0; i < N; i++) {
        if (s[i] < 2 && S >= b[i]) {
          S += 2 - s[i];
          s[i] = 2;
          p = -2;
          break;
        } else if (s[i] < 1 && S >= a[i] && (p == -1 || b[i] > b[p])) {
          p = i;
        }
      }
      if (p == -1) {
        break;
      } else if (p != -2) {
        S += 1 - s[p];
        s[p] = 1;
      }
      y++;
    }
    if (S == 2 * N) {
      cout << "Case #" << x << ": " << y << endl;
    } else {
      cout << "Case #" << x << ": Too Bad" << endl;
    }
  }
}
