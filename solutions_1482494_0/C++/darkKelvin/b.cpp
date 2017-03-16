#include <stdio.h>
#define MAXN 1050

const int inf=100000000;

int n;
int req[MAXN][3];

inline int solve() {
   int own=0;
   int status[MAXN];
   for(int i=0;i<n;i++)
      status[i]=0;
   int t,complete=0;
   for(t=0;complete<n;t++) {
      int w1=-1,w2=-1,s2=-1;
      for(int i=0;i<n;i++) {
         if(status[i]==2) continue;
         if(status[i]==0&&own>=req[i][2]) {
            w2=i;
            break;
         } else if(status[i]==1&&own>=req[i][2]) {
            w1=i;
            s2=inf;
         } else if(status[i]==0&&own>=req[i][1]&&req[i][2]>s2) {
            w1=i;
            s2=req[i][2];
         }
      }
      if(w1<0&&w2<0) return -1;
      if(w2>=0) {
         status[w2]+=2;
         own+=2;
         complete++;
      } else {
         status[w1]++;
         own++;
         if(status[w1]==2) complete++;
      }
   }
   return t;
}

int main(void)
{
   int t,cas=1;
   scanf("%d",&t);
   while(t--) {
      scanf("%d",&n);
      for(int i=0;i<n;i++)
         scanf("%d %d",req[i]+1,req[i]+2);
      int ret=solve();
      if(ret<0) printf("Case #%d: Too Bad\n",cas++);
      else printf("Case #%d: %d\n",cas++,ret);
   }
   return 0;
}
