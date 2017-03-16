#include <stdio.h>
#include <algorithm>
using namespace std;

struct node {
       int d, w, e, s;
}tribes[1000];

int wall[100000];

int cmp(node a,node b) {
    if (a.d == b.d) {
       return a.s < b.s;
    }
    return a.d < b.d;
}

int main () {
    int kase, n, h = 1;
    freopen("C-small-attempt0.in","r",stdin);
    freopen("out3.txt","w",stdout);
    scanf("%d", &kase);
    while (kase--) {
          scanf("%d", &n);
          int count = 0;
          for (int i = 0; i < n; ++i) {
              int d, nn, w, e, s;
              int delta_d, delta_p, delta_s;
              scanf("%d %d %d %d %d %d %d %d", &d,&nn,&w,&e,&s,&delta_d,&delta_p,&delta_s);
              for (int j = 0; j < nn; ++j) {
                  tribes[count].d = d+j*delta_d;
                  tribes[count].w = w+j*delta_p;
                  tribes[count].e = e+j*delta_p;
                  tribes[count++].s = s+j*delta_s;
              }
          }
          sort(tribes,tribes+count,cmp);
          
          memset(wall,0,sizeof(wall));
          int ans = 0;
          for (int i = 0; i < count; ++i) {
              bool success = false;
            //  printf("%d %d\n",2*tribes[i].w+1000,2*tribes[i].e+1000);
              for (int j = 2*tribes[i].w+10000; j <= 2*tribes[i].e+10000; ++j) {
                  if ( tribes[i].s > wall[j] ) {
                     success = true;
                     wall[j] = tribes[i].s;
                  }
              }
              if (success) {
                 ans++;
              }
          }
          printf("Case #%d: %d\n",h++,ans);
    }
    return 0;
}
