#include <iostream>

using namespace std;

int t, n, s, p;
int result, best, curr;

int main () {
  cin >> t;
  for (int ii = 1; ii <= t; ++ii) {
    cout << "Case #" << ii << ": ";

    cin >> n >> s >> p;
    
    result = 0;
    for (int i = 0; i < n; ++i) {
      cin >> curr;

      switch (curr % 3) {
      case 0:
        if (curr == 0 || curr == 30) {
          best = curr / 3;
          if (best >= p) result++;
          break;
        } else {
          best = curr / 3;
          if (best >= p) {
            result++;
            break;
          } else if (best + 1 >= p && s > 0) {
            s--;
            result++;
            break;
          }
        }
        break;
      case 1:
        best = curr / 3 + 1;
        if (best >= p) {
          result++;
          break;
        }
        break;
      case 2:
        best = curr / 3 + 1;
        if (best >= p) {
          result++;
          break;
        } else if (best + 1 >= p && s > 0) {
          s--;
          result++;
          break;
        }
        break;
      }
    }

    cout << result << endl;
  }
  return 0;
}