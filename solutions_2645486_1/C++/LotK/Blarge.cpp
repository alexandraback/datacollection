#include <algorithm>
#include <cstdio>

using namespace std;

int energy, r, n;
int v[10000010], p[10000010];

int main() {
  int t, tt, i, j;
  scanf("%d", &tt);
  for(t=0; t<tt ;t++) {
    scanf("%d%d%d", &energy, &r, &n);
    for(i=0 ; i<n ; i++) {
      scanf("%d", &v[i]);
    }

    int e = energy;
    for(i=0 ; i<n ; i++) {
      if(i>0) e=r;
      if(e>energy) e = energy;

      for(j=i-1 ; j>=0 ; j--) {
        if(v[i] > v[j]) {
          if(p[j]+e < energy) {
            e+=p[j]; p[j]=0;
          }
          else if(p[j]+e == energy) {
            e+=p[j]; p[j]=0;
            break;
          }
          else {
            p[j]-=energy-e;
            e = energy;
            break;
          }
        }
        else break;
      }
      p[i] = e;
    }
    long long ans = 0;
    for(i=0 ; i<n ; i++) {
      //printf("%d ", p[i]);
      ans += ((long long)p[i]) * v[i];
    }
    //printf("\n");
    printf("Case #%d: %lld\n", t+1, ans);
  }

}
