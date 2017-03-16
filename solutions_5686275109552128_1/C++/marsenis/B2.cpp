#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> h, g;
int n, m, s;

bool possible(int x, int m) {
   g = h;
   g.resize(n+m);
   int j = n;
   int oldm = m;
   for (int i = 0; i < n + oldm && i < m; i++) {
      if (g[i] > x) {
         g[j++] = g[i] - x;
         g[i] = x;
      } else m++;
   }
   m = oldm;
   for (int i = 0; i < n+m; i++)
      if (g[i] > x)
         return false;
   return true;
}

int main() {
   int T, mx, ans;

   scanf("%d", &T);

   for (int t = 1; t <= T; t++) {
      scanf("%d", &n);
      h.resize(n);

      mx = 0;
      s = 0;
      for (int i = 0; i < n; i++) {
         scanf("%d", &h[i]);
         s += h[i];
         mx = max(mx, h[i]);
      }
      ans = mx;

      sort(h.rbegin(), h.rend());

      for (int m = 1; m <= ans; m++) {
         int a, b, c;
         a = 0;
         b = mx;
         while (a < b-1) {
            c = (a+b) / 2;
            if (possible(c, m)) b = c;
            else a = c;
         }
         //printf("m = %d, a = %d, b = %d\n", m, a, b);
         if (possible(a, m)) ans = min(ans, a + m);
         else ans = min(ans, b + m);
         //printf("pos(%d)=%d\n", b, possible(b, m));

         /*
         if (m >= n)
            mx = (int)ceil(s / (1.0*n+m));
         else {
            mx = h[m];
            for (int i = 0; i < m; i++)
               mx = max(mx, (h[i] > h[m]) ? h[i] - h[m] : h[i]);
         }
         ans = min(ans, mx + m);
         */
      }

      printf("Case #%d: %d\n", t, ans);

   }
	return 0;
}
