#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <tuple>
#include <vector>
using namespace std;

struct Hiker {
  int pos;
  int speed;
};

void Solve() {
  int N;
  cin >> N;

  vector<Hiker> hikers;
  for (int i = 0; i < N; ++i) {
    int D, H, M;
    cin >> D >> H >> M;

    for (int i = 0; i < H; ++i) {
      hikers.push_back({D, M + i});
    }
  }

  if (hikers.size() <= 1 || hikers[0].speed == hikers[1].speed) {
    cout << 0;
    return;
  }

  if (hikers[0].speed > hikers[1].speed) {
    swap(hikers[0], hikers[1]);
  }

  if ((hikers[0].pos - hikers[1].pos + 360) * hikers[0].speed <
      360 * (hikers[1].speed - hikers[0].speed)) {
    cout << 1;
  } else {
    cout << 0;
  }
}

int main() {
//  freopen("../Console/1.txt", "rb", stdin);
    freopen("../Console/C-small-1-attempt0.in", "rb", stdin);
    freopen("../Console/C-small-1-attempt0.out", "wb", stdout);
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;
  for (int tc = 0; tc < T; ++tc) {
    cout << "Case #" << tc + 1 << ": ";
    Solve();
    cout << endl;
  }

  return 0;
}
