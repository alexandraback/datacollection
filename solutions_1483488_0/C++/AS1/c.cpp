#include <cstdio>
#include <vector>
#include <set>

using namespace std;

int main (void) {
  int tn;
  scanf ("%d", &tn);
  for (int tt = 1; tt <= tn; tt++) {
    int a, b;
    scanf ("%d%d", &a, &b);
    int res = 0;
    for (int x = a; x <= b; x++) {
      int p10 = 1;
      vector <int> p;
      while (x >= p10) {
        p.push_back(p10);
        p10 *= 10;
      }
      int pn = (int)p.size();
      set <int> nx_set;
      for (int i = 1; i < pn; i++) {
        int nx = x / p[i] + x % p[i] * p[pn - i];
        if (nx > x && a <= nx && nx <= b) {
          nx_set.insert (nx);
        }
      }
      res += (int)nx_set.size();
    }
    printf ("Case #%d: %d\n", tt, res);
  }
  return 0;
}