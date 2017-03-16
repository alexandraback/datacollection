#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[1000001],ans;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int tt,test,now,tmp,i;
    scanf("%d",&test);
    for(tt=1;tt<=test;tt++)
    {
                           if(tt==3)
                           printf("");
      scanf("%d%d",&now,&n);
      for(i=1;i<=n;i++)scanf("%d",&a[i]);
      sort(&a[1],&a[n]+1);
      tmp=0;
      ans=n;
      if(now>1)
      {
        for(i=1;i<=n;i++)
        {
          if(a[i]>=now)
            while(a[i]>=now)
            {
              now+=now-1;
              tmp++;
            }
          now+=a[i];
          if(tmp+n-i<ans)ans=tmp+n-i;
        }
      }
      printf("Case #%d: %d\n",tt,ans);
    }
    return 0;
}
