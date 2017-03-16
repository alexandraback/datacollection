#include <bits/stdc++.h>

using namespace std;

int getInt() {
  int n;
  cin >> n;
  return n;
}

int f(int W, int C) {
  int rv;
  if(C <= W) {
    rv = W;
  } else if (C > 2*W-1) {
    rv = 1+f(W, C-W);
  } else {
    rv = W+1;
  }
  //printf("%d %d %d\n", W, C, rv);
  return rv;
}

int main() {
  int T = getInt();
  for(int tt=1;tt<=T;tt++) {
    int R = getInt();
    int C = getInt();
    int W = getInt();

    // probes
    
    int ans = (((C - 1) / W) + 1 ) * (R - 1);
    ans += f(W, C);
    printf("Case #%d: %d\n", tt, ans);
  }
}
