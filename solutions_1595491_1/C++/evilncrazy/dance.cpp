#include <cstdio>
#include <algorithm>
#include <map>

#define ABS(x) ((x) < 0 ? -(x) : (x))

int scores[1000];
int surpc[100], normc[100];

int surp(int x) {
   //if(surpc[x]) return surpc[x];
   
   int max = -1;
   for(int i = 0; i <= 8; i++) {
      int j = i + 2, k = x - (i + j);
      if(k >= 0 && k <= 10 && ABS(k - j) <= 2 && ABS(k - i) <= 2) {
         max = std::max(i, std::max(j, k));
      }
   }
   return surpc[x] = max;
}

int norm(int x) {
   //if(normc[x]) return normc[x];
   
   int max = -1;
   for(int i = 0; i <= 10; i++) {
      for(int j = 0; j <= 10; j++) {
         for(int k = 0; k <= 10; k++) {
            if(i + j + k == x && ABS(i - j) < 2 && ABS(i - k) < 2 && ABS(j - k) < 2) {
               max = std::max(i, std::max(j, k));
            }
         }
      }
   }
   return normc[x] = max;
}

int main() {
   freopen("in.txt","r",stdin);
   freopen("out.txt","w",stdout);
   
   int tc;
   scanf("%d", &tc);
   
   for(int t = 1; t <= tc; t++) {
      int n, s, p;
      scanf("%d %d %d", &n, &s, &p);
      for(int i = 0; i < n; i++) {
         scanf("%d", &scores[i]);
      }

      int count = 0;
      for(int i = 0; i < n; i++) {
         if(s > 0 && norm(scores[i]) < p && (surp(scores[i]) >= p)) {
            count++;
            s--;
         } else {
            count += (norm(scores[i]) >= p);
         }
      }
      
      printf("Case #%d: %d\n", t, count);
   }
}
