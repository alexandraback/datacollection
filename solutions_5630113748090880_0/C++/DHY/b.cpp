#include <iostream>
#include <map>
using namespace std;

int main() {
  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": ";

    int N; cin >> N;

    map<int, int> m;
    int buf;
    for (int r = 0; r < 2*N-1; r++) {
      for (int c = 0; c < N; c++) {
        cin >> buf;
        if (m[buf]) {
          m[buf]++;
        } else {
          m[buf] = 1;
        }
      }
    }

    for (auto pair : m) {
      if (pair.second % 2 != 0) {
        cout << pair.first << " ";
      }
    }

    cout << endl;
  }
  return 0;
}
