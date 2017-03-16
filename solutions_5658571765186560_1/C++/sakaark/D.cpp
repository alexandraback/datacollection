#include <string>
#include <vector>
#include <cstring>
#include <cmath>
#include <utility>
#include <algorithm>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <list>
#include <iomanip>
#include <ctime>
#include <cassert>
#include <unordered_map>
#include <unordered_set>

#define WHAT_IS(x) cout << #x << " is " << x << endl;

using namespace std;

typedef long long LL;

const string rich = "RICHARD", gab = "GABRIEL";

int main () {
  std::ios::sync_with_stdio(false);
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    int x, r, c;
    string ans;
    cin >> x >> r >> c;
    int maxv = max(r, c), minv = min(r, c);
    if (x == 1) {
      ans = gab;
    }
    else if (x == 2) {
      if (r * c % 2) {
	ans = rich;
      }
      else {
	ans = gab;
      }
    }
    else if (x == 3) {
      if (r * c % 3 || r * c == 3 || minv == 1) {
	ans = rich;
      }
      else {
	ans = gab;
      }
    }
    else if (x == 4 || x == 5 || x == 6) {
      if (r * c % x || r * c == x || r * c == 2 * x || minv == 1) {
	ans = rich;
      }
      else {
	ans = gab;
      }
    }
    else {
      ans = rich;
    }
    cout << "Case #" << i << ": " << ans << endl;
  }
  return 0;
}
