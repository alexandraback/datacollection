#include <iostream>
#include <cstdio>
#include<map>
using namespace std;
#define LL long long
int n;
LL num[505];
void work()
{
    map<LL,LL> m;
    LL zt=(LL)1<<20;
    LL ans1=-1,ans2=-1;
    for(LL i=1;i<zt;++i)
    {
        LL sum=0;
        for(int j=0;j<20;++j)
            if(i&(1<<j))
               sum+=num[j];
        if(m.find(sum)!=m.end()&& (m[sum]&i)==0)
        {
            ans1=m[sum];
            ans2=i;
        }
        else
            m[sum]=i;
    }
    if(ans1==-1)
       printf("Impossible\n");
    else
    {
        LL ans[2][40];
        int cnt1=0,cnt2=0;
        for(int i=0;i<20;++i)
           if(ans1&(1<<i))
              ans[0][cnt1++]=num[i];
        for(int i=0;i<cnt1-1;++i)
           printf("%lld ",ans[0][i]);
        printf("%lld\n",ans[0][cnt1-1]);
        cnt1=0;
        for(int i=0;i<20;++i)
           if(ans2&(1<<i))
              ans[0][cnt1++]=num[i];
        for(int i=0;i<cnt1-1;++i)
           printf("%lld ",ans[0][i]);
        printf("%lld\n",ans[0][cnt1-1]);
    }
}
int main()
{
        freopen("C-small-attempt0.in", "r", stdin);
        freopen("out.txt", "w", stdout);
     int cn,cc=0;
     scanf("%d",&cn);
     while(cn--)
     {
         scanf("%d",&n);
         for(int i=0;i<n;++i)
           scanf("%lld",&num[i]);

          printf("Case #%d:\n",++cc);
          work();
     }
     return 0;

}
