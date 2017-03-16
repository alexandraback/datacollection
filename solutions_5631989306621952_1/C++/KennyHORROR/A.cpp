#ifdef DEBUG
//#define _GLIBCXX_DEBUG
#endif
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <string>
#include <cstring>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <cassert>
#include <functional>
#include <complex>

using namespace std;
typedef long double LD;
typedef long long LL;


void Solve() {
  std::string s;
  cin >> s;
  string ret;
  ret = s[0];
  for (int i = 1; i < s.size(); ++i) {
    if (s[i] + ret < ret + s[i]) {
      ret = ret + s[i];
    } else {
      ret = s[i] + ret;
    }
  }
  cout << ret << endl;
}

int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        printf("Case #%d: ", i + 1);
        Solve();
    }
    return 0;
}
