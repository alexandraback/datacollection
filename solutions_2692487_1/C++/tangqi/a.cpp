#include <cstdio>
#include <cstring>
#include <algorithm>
#define LL long long
#define maxn 105
int a[maxn];
int main()
{
    int T,n,A;
    freopen("A-large.in","r",stdin);
    freopen("outA2.txt","w",stdout);
    scanf("%d",&T);
    for(int cas=1;cas<=T;++cas)
    {
      scanf("%d%d",&A,&n);
      for(int i=0;i<n;++i)scanf("%d",a+i);
      std::sort(a,a+n);
      int tmp=0;
      int ans=n;
      if(A!=1)
      {
      for(int i=0;i<n;++i)
       if(a[i]<A)A+=a[i];
       else 
       {
            if(tmp+n-i<ans)ans=tmp+n-i;
            while(A<=a[i]) 
             {
              A+=A-1;
              ++tmp;
             }
             A+=a[i];            
       }
       if(tmp<ans)ans=tmp;
      }
      printf("Case #%d: %d\n",cas,ans);
    }
    return 0;
}
