#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int X, R, C;

void input() {
  cin >> X >> R >> C;
}

void output() {
  bool ans;
  if (X >= 7) {
    ans = false;
  } else {
    if ((R * C) % X != 0) {
      ans = false;
    } else {
      if (X <= 2) {
        ans = true;
      } else if (X == 3) {
        ans = ((R >= 2) && (C >= 2));
      } else if (X == 4) {
        ans = ( ((R >= 4) || (C >= 4))
                && ( (R >= 3) && (C >= 3) ) );
      } else if (X == 5) {
        ans = ((R >= 4) && (C >= 4));
      } else { // X == 6
        ans = ( ((R >= 6) || (C >= 6))
                && ( (R >= 4) && (C >= 4) ) );
      }
    }
  }
  cout << (ans ? "GABRIEL" : "RICHARD") << endl;
}

int main() {
  int T;
  cin >> T;
  for (auto t=1; t<=T; t++) {
    cout << "Case #" << t << ": "; 
    input();
    output();
  }
}
