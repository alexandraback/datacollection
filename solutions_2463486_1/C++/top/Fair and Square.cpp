#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define llg long long

vector<llg> V,ans;

int main () {
  for (llg i = 1;i < 10000;i ++) {
    llg x = i,y = 0,mul = 1;
    while (x > 0ll) {
      y = y*10ll+(x%10ll);
      x /= 10ll;
      mul *= 10ll;
    }
    V.push_back (i*mul+y);
    V.push_back ((i/10ll)*mul+y);
  }

  for (int i = 0;i < V.size ();i ++) {
    llg x = V[i]*V[i],y = x,z = 0;
    while (y > 0ll) {
      z = z*10ll+(y%10ll);
      y /= 10ll;
    }
    if (z == x && z <= 1e14) ans.push_back (x);
  }
  sort (ans.begin (), ans.end ());
  int test;
  scanf ("%d", &test);
  for (int Case = 1;Case <= test;Case ++) {
    llg a,b;
    scanf ("%lld %lld", &a, &b);

    printf ("Case #%d: %d\n", Case, int(upper_bound (ans.begin (), ans.end (), b)-lower_bound (ans.begin (), ans.end (), a)));
  }
}
