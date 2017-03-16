#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <fstream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main() {
  freopen("B-small-attempt0.in", "r", stdin);
  freopen("B-small-attempt0.out", "w", stdout);

  int T;
  cin >> T;
  for (int cas = 1; cas <= T; cas++) {
    int x, y;
    cin >> x >> y;
    string res = "";
    if (x >= 0) {
      for (int i = 0; i < x; i++)
        res += "WE";
    } else {
      for (int i = 0; i < -x; i++)
        res += "EW";
    }

    if (y >= 0) {
      for (int i = 0; i < y; i++)
        res += "SN";
    } else {
      for (int i = 0; i < -y; i++)
        res += "NS";
    }

    cout << "Case #" << cas << ": " << res << '\n';

  }

  return 0;
}
