#include <iostream>
#include <vector>
using namespace std;

int gcd(int m, int n) {
  m = abs(m);
  n = abs(n);
  if (m < n) swap(m, n);
  if (n == 0) return m;
  return gcd(n, m % n);
}

int solve(int H, int W, int D, vector<string>& hall) {
  int posX, posY;
  for (int r = 0; r < H; r++) {
    for (int c = 0; c < W; c++) {
      if (hall[r][c] == 'X') {
        posY = r - 1;
        posX = c - 1;
      }
    }
  }
  int h = H - 2;
  int w = W - 2;

  vector<pair<int, int> > result;
  for (int i = -(D / h) - 2; i <= (D / h) + 2; i++) {
    int y = h * i + (abs(i) % 2 == 0 ? 0 : ((h - posY - 1) - posY));
    for (int j = -(D / w) - 2; j <= (D / w) + 2; j++) {
      int x = w * j + (abs(j) % 2 == 0 ? 0 : ((w - posX - 1) - posX));
      if (i != 0 || j != 0) {
        if (y * y + x * x <= D * D) {
          int g = gcd(x, y);
          pair<int, int> p = make_pair(x / g, y / g);
          if (find(result.begin(), result.end(), p) == result.end()) {
            result.push_back(p);
          }
        }
      }
    }
  }
  return result.size();
}

int main() {
  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    int H, W, D; cin >> H >> W >> D;
    vector<string> hall(H);
    for (int i = 0; i < H; i++) cin >> hall[i];
    
    int answer = solve(H, W, D, hall);
    cout << "Case #" << t << ": " << answer << endl;
  }

}
