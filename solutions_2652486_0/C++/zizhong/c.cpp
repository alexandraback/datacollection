#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <list>
#include <queue>
using namespace std;
typedef long long ll;

int r, n, m ,k;
int num[8008][16];
bool f[9 * 9 * 9 + 1];
bool ok(int x) {
  for(int i = 0; i < k; ++ i) {
    if (f[num[x][i]] == false) {
      return false;
    }
  }
  return true;
}
int a[4] = {0};
void process(int i, int &x) {
  for(int h = 0; h < (1 << n); ++ h) {
    int tmp = 1;
    for(int t = 0; t < n; ++ t) if ((h >> t) & 1) {
      tmp *= a[t];
    }
    f[tmp] = true;
  }
  if (ok(i)) {
    x = 0;
    for(int h = 0; h < n; h ++) cout << a[h];cout << endl;
  }

}
int main()
{
#ifdef _ZZZ_
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int T;
  cin >> T;
  for(int tt = 1; tt <= T; ++ tt) {
    cin >> r >> n >> m >> k;
    for(int i = 0; i < r; ++ i) {
      for(int j = 0; j < k; ++ j) {
        cin >> num[i][j];
      }
    }
    cout << "Case #1:" << endl;
    if (n <= 3) {
      for(int i = 0; i < r; ++ i) {

        memset(f, false, sizeof(f));

        int x = 1;


        for(a[0] = 2;x && n >= 1 && a[0] <= m; a[0] ++) {
          if (n == 1) {
            process(i, x);
          } else {
            for(a[1] = 2;x && n >= 2 && a[1] <= m; a[1] ++) {
              if (n == 2) {
                process(i, x);
              } else {
                for(a[2] = 2;x && n >= 3 && a[2] <= m; a[2] ++) {
                  process(i, x);
                }
              }
            }
          }
        }

      }
    }
  }


}















