#include <iostream>
using namespace std;

void swap(int &a, int &b) {
     int t = a;
     a = b;
     b = t;
}


int main() {
    freopen("2.in","r",stdin);
    freopen("2.out","w",stdout);
    int tt, a[1010], b[1010], n, ans, now, star;
    bool aa[1010], bb[1010];
    cin >> tt;
    for (int ttt = 0; ttt < tt; ++ttt) {
        cin >> n;
        ans = 0;
        star = 0;
        for (int i = 0; i < n; ++i) cin  >> a[i] >> b[i];
        memset(aa,0,sizeof(aa));
        memset(bb,0,sizeof(bb));
        for (int i = 0; i < n-1; ++i)
         for (int j = n-1; j > i; --j)
          if (b[j-1] < b[j]) {
              swap(a[j], a[j-1]);
              swap(b[j], b[j-1]);
          }     
        
        while (star < 2*n) {
              now = 0;
              for (int i = 0; i < n; ++i) 
               if (!bb[i] && !aa[i] && b[i] <= star) {
                   now = 2;
                   aa[i] = true;
                   bb[i] = true;
                   break;
               }
              
              if (now > 0) {
                  star += now;
                  ++ans;
                  continue;
              }
              
              
              for (int i = 0; i < n; ++i) 
               if (!bb[i] && b[i] <= star) {
                   now = 1;
                   bb[i] = true;
                   break;
               }
              
              if (now > 0) {
                  star += now;
                  ++ans;
                  continue;
              }
              
              
              for (int i = 0; i < n; ++i)
               if (!aa[i] && a[i] <= star) {
                   now = 1;
                   aa[i] = true;
                   break;
               }
              
              if (now > 0) {
                  star += now;
                  ++ans;
                  continue;
              }
              
              break;
        }
        printf("Case #%d: ", ttt+1);
        if (star < 2*n) printf("Too Bad\n"); else printf("%d\n", ans);
        
    }
    
    return 0;
}
