#include <iostream>
#include <algorithm>
#include <array>
#include <climits>
#include <cmath>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>

typedef long long          ll;
typedef unsigned int       uint;
typedef unsigned long long ull;

using namespace std;

int solve() {
  int N;
  cin >> N;
  vector<tuple<double, int, int>> hikers;
  for (ll i = 0; i < N; i++) {
    ll D;
    ll H;
    ll M;
    cin >> D >> H >> M;
    for (ll j = 0; j < H; j++) {
      ll time = (360 + 360 - D) * (M + j);
      hikers.push_back(make_tuple(time, D, M + j));
    }
  }
  if (hikers.size() == 1) {
    return 0;
  }
  sort(hikers.begin(), hikers.end());
  if (get<0>(hikers[0]) > (360 - get<1>(hikers[1])) * get<2>(hikers[1])) {
    return 0;
  }
  return 1;
}

int main() {
  ll T;
  cin >> T;
  for (ll i = 0; i < T; i++) {
    std::cout << "Case #" << i + 1 << ": " << solve() << std::endl;
  }
  return 0;
}
