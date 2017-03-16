#include <iostream>
#include <vector>
using namespace std;

int R, C, W;
vector<int> past;

vector<int> possible_pos() {
  vector<int> pos;
  for (int p = 0; p + W <= C; ++p) {
    bool ok = true;
    for (int i = 0; ok && i < p; ++i) {
      if (past[i] == 1) {
        ok = false;
      }
    }
    for (int i = 0; ok && i < W; ++i) {
      if (past[p + i] == 2) {
        ok = false;
      }
    }
    for (int i = p + W; ok && i < C; ++i) {
      if (past[i] == 1) {
        ok = false;
      }
    }
    if (ok) {
      pos.push_back(p);
    }
  }
  return pos;
}

int player_b(int q);
int player_a(vector<int> pos) {
  if (pos.size() == 1) {
    int ret = 0;
    for (int i = 0; i < W; ++i) {
      if (past[pos[0] + i] != 1) {
        ++ret;
      }
    }
    return ret;
  }
  int ret = C;
  for (int q = 0; q < C; q++) {
    if (past[q] == 0) {
      ret = min(ret, 1 + player_b(q));
    }
  }
  return ret;
}

int player_b(int q) {
  int ret = -1;
  int ans = -1;
  past[q] = 1;
  auto pos = possible_pos();
  if (pos.size() > 0) {
    int tmp = player_a(move(pos));
    if (tmp > ret) {
      ans = 1;
      ret = tmp;
    }
    // ret = max(ret, player_a(move(pos)));
  }
  past[q] = 2;
  pos = possible_pos();
  if (pos.size() > 0) {
    int tmp = player_a(move(pos));
    if (tmp > ret) {
      ans = 2;
      ret = tmp;
    }
    // ret = max(ret, player_a(move(pos)));
  }
  past[q] = 0;
  // for (auto p : past) {
  //   cout << p;
  // }
  // cout << ", q: " << q << ", ans: " << ans << ", ret: " << ret << endl;
  return ret;
}

int run() {
  cin >> R >> C >> W;
  past.assign(C, 0);
  return player_a(possible_pos());
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    cout << "Case #" << t << ": " << run() << endl;
  }
}
