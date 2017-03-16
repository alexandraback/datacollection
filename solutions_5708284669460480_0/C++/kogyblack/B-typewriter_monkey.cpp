#include <cstdio>
#include <map>
#include <set>
using namespace std;

map<char, double> ks;
char target[200];

int main()
{
  int t, k, l, s;
  scanf("%d", &t);

  for (int tt = 1; tt <= t; ++tt) {
    printf("Case #%d: ", tt);

    ks.clear();

    scanf("%d%d%d", &k, &l, &s);

    char c;
    for (int i = 0; i < k; ++i) {
      scanf(" %c", &c);
      if (ks.find(c) != ks.end())
        ks[c] += 1.0 / k;
      else
        ks[c] = 1.0 / k;
    }

    bool ok = true;
    int rep = 0;
    double w = 1.0;
    double r = 1.0;
    for (int i = 0; i < l; ++i) {
      scanf(" %c", &c);

      if (!ok)
        continue;

      if (ks.find(c) == ks.end())
        ok = false;
      else {
        target[i] = c;
        if (i > 0 && c == target[rep]) {
          rep++;
          r *= ks[c];
        } else {
          w *= r;
          r = 1.0;
          rep = 0;
          if (i > 0 && c == target[rep]) {
            rep++;
          } else {
            w *= ks[c];
          }
        }
      }
    }

    if (ok) {
      int wc = (s - rep) / (l - rep);
      double pay = wc - wc * w * r;
      printf("%.7f\n", pay);
    } else {
      printf("0.0\n");
    }
  }

  return 0;
}
