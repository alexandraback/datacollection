#include <iostream>
#include <cmath>

using namespace std;

int main() {

  bool seen[10];
  int seenc;
  int o;

  int T;
  cin >> T;


  for (int i = 0; i < T; i++) {
    int N;
    cin >> N;

    cout << "Case #" << i + 1 << ": ";

    for (int i = 0; i < 10; i++) {
      seen[i] = false;
    }
    seenc = 0;

    for (int i = 1; i < 10000000; i++) {

      int c = N * i;
      int h = 1;
      for (int i = 0; i < 15; i++) {
        int d = c / h;
        if (d != 0) {
          int a = d % 10;
          if (!seen[a]) {
            seenc++;
          }
          seen[a] = true;
        }
        h *= 10;
      }

      if (seenc >= 10) {
        o = i;
        goto done;
      }
    }
    goto bad;

  done:
    cout << o * N << endl;
    continue;

  bad:
    cout << "INSOMNIA" << endl;
    continue;

  }


  return 0;

}
