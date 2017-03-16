#include <cstdio>
#include <algorithm>
#include <queue>

struct level {
   int s1, s2;
} lvls[1002];

bool done1[1002], done2[1002];

int main() {
   freopen("in.txt","r",stdin);
   freopen("out.txt","w",stdout);
   
   int tc; scanf("%d", &tc);
   for(int t = 1; t <= tc; t++) {
      int n; scanf("%d", &n);
      
      for(int i = 0; i < n; i++) {
         scanf("%d %d", &lvls[i].s1, &lvls[i].s2);
         done1[i] = false;
         done2[i] = false;
      }
      
      int have = 0, cmp = 0;    
      while(1) {
         int min = -1; bool alldone = true;
         for(int i = 0; i < n; i++) {
            if(!done2[i] && have >= lvls[i].s2 && (min == -1 || lvls[i].s2 < lvls[min].s2)) {
               min = i;
            }
            
            if(!done2[i]) alldone= false;
         }
         
         if(alldone) {
            printf("Case #%d: %d\n", t, cmp);
            break;
         }
         
         if(min == -1) {
            int max = -1;
            for(int i = 0; i < n; i++) {
               if(!done1[i] && have >= lvls[i].s1 && (max == -1 || lvls[i].s2 > lvls[max].s2)) {
                  max = i;
               }
            }
            
            if(max == -1) {
               printf("Case #%d: Too Bad\n", t);
               break;
            }
            
            //printf("did 1 star of %d\n", max);
            done1[max] = true; have++;
            cmp++;
            
         } else {
            //printf("did 2 star of %d\n", min);
            if(done1[min]) have++;
            else have += 2;
            
            done1[min] = true;
            done2[min] = true;
            cmp++;
         }
      }
   }
}
