#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>
#define forup(i,a,b) for (int i=a;i<=b;i++)
#define fordown(i,a,b) for (int i=a;i>=b;--i)

using namespace std;

int T,A,N,a[101];

int main(){
    freopen("1.txt","r",stdin);
    freopen("2.txt","w",stdout);
    scanf("%d",&T);
    forup(uu,1,T)
    {
         scanf("%d%d",&A,&N);
         forup(i,1,N) scanf("%d",&a[i]);
         sort(a+1,a+N+1);
         int ans=1<<30;
         if (A==1) ans=N;
         else
         forup(i,0,N)
         {
               int now=i,cnt=A,use=1;
               bool ok=true;
               forup(j,1,N-i)
                   if (cnt>a[j]) cnt+=a[j]; 
                   else
                   {
                       while (cnt<=a[j]) cnt+=cnt-1,++now;
                       if (cnt<=a[j]) 
                       {
                           ok=false;
                           break;
                       }
                       cnt+=a[j];
                   }
               if (ok) 
                   ans=min(ans,now);
         }
         printf("Case #%d: %d\n",uu,ans);
    }
}                   
