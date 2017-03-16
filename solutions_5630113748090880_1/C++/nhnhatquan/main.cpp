#include <string>
#include <fstream>
#include <iostream>
#include <istream>
#include <sstream>
#include <functional>
#include <numeric>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

void main() {
  int T;
  cin >> T;

  for (int t = 0; t != T; ++t) {
    int count[2510] = { 0, };
    int N;
    cin >> N;

    int ll = (2 * N - 1) * N;

    int tmp;
    int max = 0;

    for (int i = 0; i != ll; ++i) {
      cin >> tmp;

      ++count[tmp];
      if (tmp > max) max = tmp;
    }

    cout << "Case #" << t + 1 << ":";
    ++max;
    //max = 2510;
    for (int i = 0; i != max; ++i) {
      if (count[i] % 2) {
        cout << " " << i;
      }
    }
    cout << endl;
  }
}