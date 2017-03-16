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

vector<int> dens;
vector<bool> vals;

void get_closure() {
  int sz = (int)dens.size();
  int all = (1 << sz);
  for (int i = 0; i < all; i++) {
    int todo = 0;
    for (int j = 0; j < sz; j++) {
      if (i & (1 << j)) {
	todo += dens[j];
      }
    }
    if (todo < vals.size()) {
      vals[todo] = true;
    }
  }
}

int next_required() {
  int sz = vals.size();
  for (int i = 1; i < sz; i++) {
    if (vals[i] == false) {
      return i;
    }
  }
  return 0;
}

int main () {
  std::ios::sync_with_stdio(false);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int c, d, v;
    cin >> c >> d >> v;
    dens.clear();
    dens.resize(d);
    vals.clear();
    vals.resize(v + 1, false);
    for (int i = 0; i < d; i++) {
      cin >> dens[i];
    }
    get_closure();
    // cout << "Closure" << endl;
    int ans = 0, req = 0;
    while (req = next_required()) {
      dens.push_back(req);
      sort(dens.begin(), dens.end());
      get_closure();
      ans++;
    }
    cout << "Case #" << i + 1 << ": " << ans << endl;
  }
  return 0;
}
