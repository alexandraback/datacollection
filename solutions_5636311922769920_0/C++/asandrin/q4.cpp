#include <iostream>
using namespace std;

#define _ long long

int main() {

  _ T;
  cin >> T;
  for (_ t = 0; t < T; t++) {
    _ K, C, S;
    cin >> K >> C >> S;

    cout << "Case #" << t + 1 << ": ";
    for (_ i = 0; i < K; i++) {
      _ d = 1;
      _ o = 0;
      for (_ j = 0; j < C; j++) {
        o += d * i;
        d *= K;
      }
      cout << o + 1 << " ";
    }
    cout << endl;
  }

  return 0;
}
