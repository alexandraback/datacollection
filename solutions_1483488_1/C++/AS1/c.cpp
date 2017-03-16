#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> ne[2000010];

int main (void) {
  int tn;
  scanf ("%d", &tn);
  
  int a, b;
  a = 1;
  b = 2000000;
  for (int x = a; x <= b; x++) {
    int p10 = 1;
    vector <int> p;
    while (x >= p10) {
      p.push_back(p10);
      p10 *= 10;
    }
    int pn = (int)p.size();
    vector <int> &nx_set = ne[x];
    for (int i = 1; i < pn; i++) {
      int nx = x / p[i] + x % p[i] * p[pn - i];
      if (nx > x && a <= nx && nx <= b) {
        nx_set.push_back (nx);
        
      }
    }
    sort (nx_set.begin(), nx_set.end());
    nx_set.erase (unique (nx_set.begin(), nx_set.end()), nx_set.end());
  }
  for (int tt = 1; tt <= tn; tt++) {
    fprintf (stderr, "tt = %d\n", tt);
    int a, b, res = 0;
    scanf ("%d%d", &a, &b);
    for (int x = a; x <= b; x++) {
      for (int j = 0; j < (int)ne[x].size(); j++) {
        if (ne[x][j] > b) {
          break;
        }
        res++;
      }
    }
    printf ("Case #%d: %d\n", tt, res);
  }
  return 0;
}