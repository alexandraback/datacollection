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
#include <stack>
#include <unordered_map>
#include <unordered_set>

#define what_is(x) cout << #x << " is " << x << endl;

using namespace std;

typedef long long ll;

int main () {
  std::ios::sync_with_stdio(false);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int r, c, w, ans = 0, fails;
    cin >> r >> c >> w;
    fails = c / w;
    ans += (r - 1) * fails;
    ans += fails - 1;
    ans += w;
    ans += (c % w != 0);
    cout << "Case #" << i + 1 << ": " << ans << endl;
  }
  return 0;
}
