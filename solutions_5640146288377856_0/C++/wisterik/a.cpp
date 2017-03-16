#include <iostream>
#include <vector>
#include <cstring>

#define rep(i, n) for(int i = 0; i < n; i++)

using namespace std;

int memo[25];

/* Count until knowing that there is no ship */
int f(int c, int w) {
  if(c < w) {
    return 0;
  }
  if(c == w) {
    return 1;
  }
  int d = memo[c];
  if(d != -1) return d;
  int ans = 1 << 29;
  rep(i, c) {
    ans = min(ans, 1 + f(i, w) + f(c - i - 1, w));
  }
  return d = ans;
}

int solve(int r, int c, int w) {
  rep(i, 25) {
    memo[i] = -1;
  }
  int ans = f(c, w) * r + w;
  if(c % w == 0) ans -= 1;
  return ans;
}

int main() {

  int T;
  cin >> T;

  rep(i, T) {
    int R, C, W;
    cin >> R >> C >> W;
    cout << "Case #" << (i+1) << ": " << solve(R, C, W) << endl;
  }

  return 0;
}
