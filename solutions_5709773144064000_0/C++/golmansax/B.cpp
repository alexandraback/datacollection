#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <vector>

using namespace std;

int main() {
  int n_tests;
  cin >> n_tests;
  for (int i_test = 0; i_test < n_tests; i_test++) {
    double c, f, x;
    cin >> c >> f >> x;

    double rate = 2;
    double time = 0;
    while (true) {
      // Decide whether we should buy a farm
      double time_finish = x / rate;
      double time_buy = (x + c + c * f / rate) / (rate + f);

      if (time_finish <= time_buy) {
        time += time_finish;
        break;
      } else {
        // Add buy time
        time += c / rate;
        rate += f;
      }
    }

    printf("Case #%d: ", i_test+1);
    printf("%.7f\n", time);
  }
}
