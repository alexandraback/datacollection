#include <iostream>
#include <memory.h>
using namespace std;

int a[110][110], maxr[110], maxc[110];

int main() {
  int t; cin >> t;
  for (int c = 1; c <= t; c++) {
    int n, m; cin >> n >> m;
    memset(maxr, 0, sizeof(maxr));
    memset(maxc, 0, sizeof(maxc));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        cin >> a[i][j];
        maxr[i] = max(maxr[i], a[i][j]);
        maxc[j] = max(maxc[j], a[i][j]);
      }

    bool ok = true;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        ok = ok && (a[i][j] == maxr[i] || a[i][j] == maxc[j]);
    cout << "Case #" << c << ": " << (ok ? "YES" : "NO") << endl;
  }
  return 0;
}
