#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  int T, N;
  double s[200], sum, v[200];

  cin >> T;

  for (int i=0; i<T; i++) {
    cin >> N;
    sum = 0;
    for (int j=0; j<N; j++) {
      cin >> s[j];
      sum += s[j];
      v[j] = 0;
    }

    double remain = sum;
    while (remain > 0) {
      double lowest = s[0];
      int count = 0;

      for (int j=0; j<N; j++) {
        if (s[j] < lowest) {
          lowest = s[j];
          count = 1;
        } else if (s[j] == lowest) {
          count++;
        }
      }

      double second = s[0];
      for (int j=0; j<N; j++) {
        if (second == lowest || (s[j] < second && s[j] > lowest)) {
          second = s[j];
        }
      }

      double incr;
      if (second == lowest || remain < count*(second-lowest)) {
        incr = remain / count;
        remain = 0;
      } else {
        incr = second-lowest;
        remain -= count*(second-lowest);
      }

      //printf("low:%f\tcnt:%d\tsec:%f\tinc:%f\trem:%f\n", lowest, count, second, incr, remain);
      
      for (int j=0; j<N; j++) {
        if (s[j] == lowest) {
          s[j] += incr;
          v[j] += incr / sum;
        }
      }
    }
    
    cout << "Case #" << i+1 << ":";
    for (int j=0; j<N; j++) {
      printf(" %.6f", 100*v[j]);
    }
    cout << endl;
  }
}

