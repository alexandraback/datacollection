#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
typedef long long ll;

int a,n,siz[1000];


int main() {
   int Te;
   scanf("%d",&Te);
   REP(te,Te) {
      scanf("%d%d",&a,&n);
      REP(i,n) scanf("%d",&siz[i]);
      sort(siz,siz+n);
      int best = n;

      if (a>1) {
         for(int nowen = 0; nowen <= n; ++nowen) {
            int koszt = n - nowen;
            ll aa = a;
            REP(i,nowen) {
               while (aa <= siz[i]) {
                  aa += aa-1;
                  koszt++;
               }
               aa += siz[i];
            }
            best = min(best,koszt);
         }
      }


      printf("Case #%d: %d\n", te+1,best);
   }
}
