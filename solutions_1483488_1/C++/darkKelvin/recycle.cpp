#include <cstdio>
#include <algorithm>
#define MAXVAL 10000500

using namespace std;

int mod10[MAXVAL],div10[MAXVAL];

int lb,ub,dig,tp,tt;
int visited[MAXVAL]={0},visid=0;

inline int length(int x) {
   int l=0;
   while(x) {
      x/=10;
      l++;
   }
   return l;
}
inline int p10(int p) {
   int m=1;
   for(int i=0;i<p;i++)
      m*=10;
   return m;
}

inline int solve() {
   int sol=0;
   dig=length(ub);
   tt=p10(dig-1);
   for(int i=lb;i<=ub;i++) {
      int x=i;
      ++visid;
      for(int j=0;j<dig;j++) {
         if(i<x&&x<=ub) {
            if(visited[x]<visid) {
               sol++;
               visited[x]=visid;
            }
         }
         x=div10[x]+mod10[x]*tt;
      }
   }
   return sol;
}

int main(void)
{
   int t,cas=1;
   for(int i=0;i<MAXVAL;i++) {
      div10[i]=i/10;
      mod10[i]=i%10;
   }
   scanf("%d",&t);
   while(t--) {
      scanf("%d %d",&lb,&ub);
      printf("Case #%d: %d\n",cas++,solve());
   }
   return 0;
}
