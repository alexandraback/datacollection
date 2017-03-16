#include <stdio.h>

int a[1007], tail[1007];
bool b[1007];
int visit[1007];

int max(int x, int y){ return x > y ? x : y; }

void clear(int n){
   for(int i=1; i<=n; ++i)
      visit[i] = -1;
}

int cycle(int x){
   int now = x, mark = 0;
   while(visit[now] == -1){
      visit[now] = mark;
      mark += 1;
      now = a[now];
   }
   tail[now] = max(tail[now], visit[now]);
   return mark - visit[now];
}

void run(int x){
   if(visit[x] != -1) return;
   run(a[x]);
   visit[x] = visit[a[x]] + 1;
}


int main(){
   int T, n, ans1, ans2, tmp;
   bool flg;
   scanf("%d", &T);
   for(int t=1; t<=T; ++t){
      printf("Case #%d: ", t);
      scanf("%d", &n);
      for(int i=1; i<=n; ++i){
         scanf("%d", &a[i]);
         tail[i] = 0;
      }
      ans1 = ans2 = 0;
      for(int i=1; i<=n; ++i){
         clear(n);
         ans1 = max(ans1, cycle(i));
      }
      
      for(int i=1; i<=n; ++i){
         if(a[i] > i && a[a[i]] == i){
            ans2 += (2 + tail[i] + tail[a[i]]);
         }
      }
      
      printf("%d\n", max(ans1, ans2));
   }
   return 0;
}
