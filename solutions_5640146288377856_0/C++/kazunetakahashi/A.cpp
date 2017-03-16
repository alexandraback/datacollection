#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void init() {
}

// 変数を書く

int R, C, W;

void input() {
  cin >> R >> C >> W;
}

void output() {
  cerr << R << " " << C << " " << W << endl;
  int ans = (R-1) * (C/W);
  int h = C/W;
  int tans = 0;
  tans += h-1;
  tans += ((C%W == 0) ? W : W+1);
  cout << ans + tans << endl;
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
