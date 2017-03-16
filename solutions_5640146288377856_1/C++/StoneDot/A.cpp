#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

int R, C, W;
set<int> cand;
bool shooted_space[100];
int lane(int hit, int shooted) {
  int cnt[100];
  for (int i = 0; i < C; i++) cnt[i] = 0;
  for(auto pos : cand) {
    for (int i = 0; i < W; i++) {
      cnt[pos + i]++;
    }
  }
  int max_pos = 0;
  for (int i = 0; i < C; i++) {
    if (shooted_space[i]) continue;
    if (cnt[i] > cnt[max_pos]) max_pos = i;
  }
  shooted++;
  shooted_space[max_pos] = true;

  bool isHit = true;
  int maxSpace = 0;
  for (auto pos : cand) {
    bool this_hit = false;
    for (int i = 0; i < W; i++) {
      if (pos + i == max_pos) {
        this_hit = true;
      }
    }
    if (!this_hit) {
      isHit = false;
      break;
    }
  }

  if (!isHit) {
    for (int i = -(W - 1); i <= 0; i++) {
      cand.erase(max_pos + i);
    }
  }
  else {
    hit++;
  }
  if (cand.size() <= 1) {
    return shooted + (W - hit);
  }
  else {
    return lane(hit, shooted);
  }
}

void solve() {
  cin >> R >> C >> W;
  cand.clear();
  for (int i = 0; i < C - W + 1; i++) {
    cand.insert(i);
  }
  for (int i = 0; i < C; i++) {
    shooted_space[i] = false;
  }
  int ans = lane(0, 0) + (C / W) * (R - 1);
  cout << ans << endl;
}

int main(void) {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": ";
    solve();
  }
  return 0;
}