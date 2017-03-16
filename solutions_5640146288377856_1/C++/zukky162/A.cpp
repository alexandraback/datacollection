#include <bits/stdc++.h>
using namespace std;
const int INF = 1<<28;

int R, C, W;
int mem[21][21][2];

int rec(int l, int r, int f) {
  int &res = mem[l][r][f];
  if(res != -1) return res;
  if(r - l == W) {
    if(f) return res = INF;
    else return res = W;
  }
  if(r - l < W) {
    if(f) return res = 0;
    else return res = INF;
  }
  res = INF;
  for(int i = l; i < r; ++i) {
    int a = INF, b = INF;
    // hit
    if(!f) {
      a = 1 + W;
    }
    // miss
    {
      int tmp = -1;
      if(!f) {
        if(i - l >= W)
          tmp = max(tmp, rec(l, i, 0) + rec(i+1, r, 1));
        if(r - (i+1) >= W)
          tmp = max(tmp, rec(l, i, 1) + rec(i+1, r, 0));
      } else {
        tmp = max(tmp, rec(l, i, 1) + rec(i+1, r, 1));
      }
      if(tmp != -1)
        b = 1 + tmp;
    }
    res = min(res, max(a, b));
  }
  return res;
}

int main() {
  int T; cin >> T;
  for(int tc = 1; tc <= T; ++tc) {
    cout << "Case #" << tc << ": ";
    cin >> R >> C >> W;
    int res = (R - 1) * (C / W);
    memset(mem, -1, sizeof(mem));
    res += rec(0, C, 0);
    cout << res << endl;
  }
  return 0;
}
