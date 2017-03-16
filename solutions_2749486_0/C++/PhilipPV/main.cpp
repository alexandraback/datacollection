#pragma comment(linker, "/STACK:46777216")

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <algorithm>
#include <memory.h>
#include <cmath>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned char byte;
typedef pair<int, int> pii;
#define forn(i,n) for (ll i = 0; i < ll(n); ++i)
#define mp make_pair

int main() {
  int T;
  cin >> T;
  forn (_, T) {
    cout << "Case #" << (_ + 1) << ": ";
    int x, y; cin >> x >> y;
    string result;

    if (x > 0) {
      for (int i = 0; i < x; ++i)
        result += "WE";
    } else {
      for (int i = 0; i < -x; ++i)
        result += "EW";
    }

    if (y > 0) {
      for (int i = 0; i < y; ++i)
        result += "SN";
    } else {
      for (int i = 0; i < -y; ++i)
        result += "NS";
    }

    cout << result << endl;
  }


  return 0;
}