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
    int c, d, v;
    cin >> c >> d >> v;
    vector<int> dens(d);
    for (int i = 0; i < d; i++) {
      cin >> dens[i];
    }
    ll scan = 1;
    int cur = 0, ans = 0;
    while (scan <= v) {
      while (cur < d) {
	if (dens[cur] > scan) {
	  break;
	}
	scan += c * 1ll * dens[cur];
	cur++;
      }
      if (scan <= v) {
	ans++;
	scan = (c + 1) * 1ll * scan;
      }
    }
    cout << "Case #" << i + 1 << ": " << ans << endl;
  }
  return 0;
}
