#include <bits/stdc++.h>
using namespace std;

struct trio{
   int x, y, z;
   trio(int x=0, int y=0, int z=0):
      x(x), y(y), z(z) {}
};

int main() {
//   freopen("input.txt", "r", stdin);

   int tc;
   cin >> tc;
   for (int cs = 1; cs <= tc; cs ++) {
      cout << "Case #" << cs << ": ";
      cerr << "Case #" << cs << ": ";

      int a, b, c, k;
      cin >> a >> b >> c >> k;
      vector <trio> v;
      for (int i = 0; i < a; i ++){
         for (int j = 0; j < b; j ++) {
            for (int l = 0; l < c; l ++) {
               v.emplace_back(i, j, l);
            }
         }
      }
      int ab[a][b], ac[a][c], bc[b][c];
      int ans = 0, subset;

      for (int sub = 1; sub < 1 << v.size(); sub += 2) {
         memset(ab, 0, sizeof ab);
         memset(ac, 0, sizeof ac);
         memset(bc, 0, sizeof bc);

         for (int i = 0; i < v.size(); i ++) if (sub & 1 << i) {
            trio t = v[i];
            ab[t.x][t.y] ++;
            ac[t.x][t.z] ++;
            bc[t.y][t.z] ++;
         }
         bool ok = true;
         for (int i = 0; i < a; i ++) {
            for (int j = 0; j < b; j ++) if (ab[i][j] > k) ok = false;
         }
         for (int i = 0; i < a; i ++) {
            for (int j = 0; j < c; j ++) if (ac[i][j] > k) ok = false;
         }
         for (int i = 0; i < b; i ++) {
            for (int j = 0; j < c; j ++) if (bc[i][j] > k) ok = false;
         }
         if (ok) {
            if (__builtin_popcount(sub) > ans) {
               ans = __builtin_popcount(sub);
               subset = sub;
            }
         }
      }
      cout << ans << endl;
      for (int i = 0; i < v.size(); i ++) if (subset & 1 << i) {
         trio t = v[i];
         cout << t.x + 1 << " " << t.y + 1 << " " << t.z + 1 << endl;
      }
   }
}
