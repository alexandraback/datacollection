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
    string S;
    cin >> S;

    int len = S.size();
    string ret = "";
    ret.push_back(S[0]);
    for (int i = 1; i != len; ++i) {
      if (S[i] < ret[0]) {
        ret += S[i];
      }
      else {
        ret = S[i] + ret;
      }
    }

    cout << "Case #" << t + 1 << ": " << ret << endl;
  }
}