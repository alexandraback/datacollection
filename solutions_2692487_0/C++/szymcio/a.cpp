#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <utility>
#include <cstdlib>

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz size
#define FOR(I,X) for(int I=0;I<(X);I++)
#define FORD(I,X) for(int I=(X)-1;I>=0;I--)
#define REP(I,V,X) for(int I=(V);I<=(X);I++)
#define REPD(I,V,X) for(int I=(V);I>=(X);I--)

using namespace std;

typedef pair<int,int> PII;
typedef vector<int> VI;

int t, aa, a, n, added, res, poz;
VI m;
bool up, one;

int main()
{
  scanf("%d", &t);
  FOR(i,t) {
   scanf("%d %d", &a, &n); m.clear();
   FOR(j,n) scanf("%d", &aa), m.pb(aa);
   sort(m.begin(), m.end());
   res = n; poz = added = 0; up = one = false;
   if (a == 1) up = one = true;
   else while (poz < n) {
    while (poz < n && a > m[poz]) a += m[poz++];
    if (poz < n)
    {
      up = true;
      res = min(res, added+n-poz);
      while (a <= m[poz]) a += a-1, added++;
      a += m[poz];
      poz++;
    }
   }
   if (!up) res = 0;
   else if (!one) res = min(res, added);
   printf("Case #%d: %d\n", i+1, res);
  }
  return 0;
}
