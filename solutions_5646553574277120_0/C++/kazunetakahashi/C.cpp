#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void init() {
}

// 変数を書く
int C, D, V;
vector<int> M;
bool can[1000];
int remain;

void input() {
  cin >> C >> D >> V;
  remain = V;
  M.clear();
  for (auto i=0; i<D; i++) {
    int x;
    cin >> x;
    M.push_back(x);
  }
  fill(can, can+1000, false);
}

int pw(int x, int y) {
  int ans = 1;
  for (auto i=0; i<y; i++) {
    ans *= x;
  }
  return ans;
}

void ume(int x) {
  for (auto i=V; i>=0; i--) {
    if (can[i] && i+x <= V && !can[i+x]) {
      remain--;
      can[i+x] = true;
    }
  }
}

void output() {
  can[0] = true;
  for (auto j=0; j<D; j++) {
    ume(M[j]);
    cerr << "using " << M[j] << ", remain = " << remain << endl;
  }
  if (remain == 0) {
    cout << 0 << endl;
    return;
  }
  int ans = 0;
  for (auto i=0; i<9; i++) {
    int kouho = pw(2, i);
    bool used = false;
    for (auto j=0; j<D; j++) {
      if (M[j] == kouho) {
        used = true;
        break;
      }
    }
    if (used) continue;
    bool temp[1000];
    int tremain = remain;
    for (auto j=0; j<1000; j++) {
      temp[j] = can[j];
    }
    ume(kouho);
    if (tremain == remain) {
      remain = tremain;
      for (auto j=0; j<1000; j++) {
        can[j] = temp[j];
      }
    } else {
      ans++;
      if (remain == 0) {
        cout << ans << endl;
        return;
      }
    }
  }
  assert(false);
}

int main() {
  init();
  int T;
  cin >> T;
  for (auto t=1; t<=T; t++) {
    cout << "Case #" << t << ": "; 
    input();
    output();
  }
}
