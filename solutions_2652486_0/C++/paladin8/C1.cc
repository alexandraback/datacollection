#include <iostream>
#include <memory.h>
using namespace std;

int a[16], hist[64][128];

int main() {
  memset(hist, 0, sizeof(hist));
  for (int i = 2; i <= 5; i++)
    for (int j = 2; j <= 5; j++)
      for (int k = 2; k <= 5; k++) {
        int idx = 16*(i-2) + 4*(j-2) + (k-2);
        hist[idx][1]++;
        hist[idx][i]++;
        hist[idx][j]++;
        hist[idx][k]++;
        hist[idx][i*j]++;
        hist[idx][i*k]++;
        hist[idx][j*k]++;
        hist[idx][i*j*k]++;
      }

  int t; cin >> t; cout << "Case #" << t << ":" << endl;
  int r, n, m, k; cin >> r >> n >> m >> k;
  while (r--) {
    for (int i = 0; i < k; i++) cin >> a[i];

    int best = 0, bestv = -1;
    for (int i = 0; i < 64; i++) {
      int curv = 1;
      for (int j = 0; j < k; j++) curv *= hist[i][a[j]];
      if (curv > bestv) {
        bestv = curv;
        best = i;
      }
    }

    int x = 2 + best % 4; best /= 4;
    int y = 2 + best % 4; best /= 4;
    int z = 2 + best % 4;
    cout << z << y << x << endl;
  }
  return 0;
}
