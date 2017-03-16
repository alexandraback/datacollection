#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<char, char> cp;

int getInt() {
  int v;
  scanf("%d", &v);
  return v;
}

bool solve() {
  int X = getInt();
  int R = getInt();
  int C = getInt();
  int m = min(R, C);
  if(R * C % X != 0) { return false;}
  if(max(R,C) < X) { return false;}
  if(X == 1) { return true; }
  if(X == 2) { return true; }
  if(X == 3) {
    if(m < 2) { return false;}
    return true;
  }
  if(X == 4) {
    if(m < 3) { return false;}
    return true;
  }
  if(X == 5) {
    if(m < 3) { return false;}
    return true;
  }
  if(X == 6) {
    if(m < 4) { return false;}
    return true;
  }
  
  if(X >= 7) { return false;}
  return false;
}

int main() {
  int T = getInt();
  for(int tt=1;tt<=T;tt++) {
    bool ans = solve();
    printf("Case #%d: ", tt);
    if(ans) {
      printf("GABRIEL\n");
    } else {
      printf("RICHARD\n");
    }
  }
}
