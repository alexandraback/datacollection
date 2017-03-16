#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// 1, i, j, k, -1, -i, -j, -k

int table[8][8] = {
  { 0, 1, 2, 3, },
  { 1, 4, 3, 6, },
  { 2, 7, 4, 1, },
  { 3, 2, 5, 4, },
};

void init() {
  for (auto i=0; i<4; i++) {
    for (auto j=0; j<4; j++) {
      int x = table[i][j];
      table[i+4][j] = (x + 4) % 8;
      table[i][j+4] = (x + 4) % 8;
      table[i+4][j+4] = x;
    }
  }
}

int c(char a) {
  return (a - 'i' + 1);
}

int mult(int x, int y) {
  return table[x][y];
}

int L;
ll X;
string S;

int multtimes(int x, ll t) {
  if (t == 0) return 0;
  if (t%2 == 1) return mult(multtimes(x, t-1), x);
  int y = multtimes(x, t/2);
  return mult(y, y);
}

void input() {
  cin >> L >> X >> S;
}

void output() {
  int x = 0;
  for (auto i=0; i<L; i++) {
    x = mult(x, c(S[i]));
  }
  if (multtimes(x, X) != 4) {
    cout << "NO" << endl;
  } else { // ijkにスプリットできるかを調べる
    string SS = "";
    int times = min(X, (ll)20);
    for (auto i=0; i<times; i++) {
      SS += S;
    }
    x = 0;
    // iが作れるか
    int next = -1;
    bool ok = false;
    // i判定
    for (int i=0; i<(int)SS.size(); i++) {
      x = mult(x, c(SS[i]));
      if (x == 1) {
        next = i+1;
        break;
      }
    }
    if (next == -1) {
      cout << "NO" << endl;
      return;
    }
    // j判定
    x = 0;
    for (int i=next; i<(int)SS.size(); i++) {
      x = mult(x, c(SS[i]));
      if (x == 2) {
        // cerr << i << endl;
        next = i+1;
        ok = true;
      }
    }
    cout << (ok ? "YES" : "NO") << endl;
    return;
  }
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
