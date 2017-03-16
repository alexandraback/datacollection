#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
  int total;
  cin >> total;
  for (int totalCount = 0; totalCount < total; ++totalCount) {
    int N;
    cin >> N;
    int* point = new int[N];
    bool* check = new bool[N];
    float sum = 0;
    for (int i = 0; i < N; ++i) {
      cin >> point[i];
      sum += point[i];
      check[i] = false;
    }
    float share = 2 * sum;
    float target = share / N;
    int now = N;
    do {
      int cc = 0;
      for (int i = 0; i < N; ++i) {
        if (point[i] > target && !check[i]) {
          ++cc;
          check[i] = true;
          share -= point[i];
          //cout << i << "ignore" << endl;
        }
      }
      if (cc > 0) {
        now -= cc;
        target = share / now;
      } else {
        break;
      }
    } while (1);
    cout << "Case #" << totalCount + 1 << ":";
    for (int i = 0; i < N; ++i) {
      if (check[i]) {
        //cout << i << "iignore" << endl;
        printf(" 0.00000");
        //cout << i << "iignore" << endl;
      } else {
        printf(" %.5f", (target - point[i]) / sum * 100);
      }
    }
    delete[] check;
    delete[] point;
    cout << endl;
  }
  return 0;
}
