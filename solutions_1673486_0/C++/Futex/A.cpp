#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;


int main() {
  int cases;
  cin >> cases;

  for (int c = 0; c < cases; ++c) {
    int already, total;
    cin >> already >> total;

    vector<double> vec(already);
    for (int a = 0; a < already; ++a) {
      cin >> vec[a];
    }

    double best = total + 2.0;
    double prob = 1.0;
    for (int back = already; back >= 0; --back) {
      double win = prob * (back + back + total - already + 1);
      double lose = (1.0 - prob) * (total - already + back + back + 2 + total);

      double final = win + lose;
      if (best > final) {
        best = final;
      }

      if (back > 0) {
        prob *= vec[already - back];
      }
    }

    cout << showpoint << fixed;
    cout.precision(6);
    cout << "Case #" << (c + 1) << ": " << best << endl;
  }

  return 0;
}
