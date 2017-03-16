#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
#include <cstdlib>
#include <cmath>

using namespace std;


typedef long long LL;
LL num[30];
int n;
const int maxn = 30;

int work()
{
    LL i,sum,b,ans1,ans2;
    for(i=0;i<n;++i)
    {
        scanf("%I64d",&num[i]);
    }

    map <LL,LL> m;
    b=(LL)1<<20;
    ans1=-1,ans2=-1;
    for(i=1;i<b;++i)
    {
        sum=0;
        for(int j=0;j<20;++j)
            if(i&(1<<j))
               sum+=num[j];
        if(m.find(sum)!= m.end() && (m[sum]&i)==0)
        {
            ans1=m[sum];
            ans2=i;
        }
        else
            m[sum]=i;
    }
    if(ans1 == -1)
    {
       printf("Impossible\n");
    }
    else
    {
        LL ans[2][40];
        int cnt1=0,cnt2=0;
        for(int i=0;i<20;++i)
           if(ans1&(1<<i))
              ans[0][cnt1++]=num[i];
        for(int i=0;i<cnt1-1;++i)
           printf("%I64d ",ans[0][i]);
        printf("%I64d\n",ans[0][cnt1-1]);
        cnt1=0;
        for(int i=0;i<20;++i)
           if(ans2&(1<<i))
              ans[0][cnt1++]=num[i];
        for(int i=0;i<cnt1-1;++i)
           printf("%I64d ",ans[0][i]);
        printf("%I64d\n",ans[0][cnt1-1]);
    }
    return 0;
}

int main()
{
    freopen("small.in","r",stdin);
    freopen("small.out","w",stdout);
    int cn,cas = 0;
    scanf("%d",&cn);
    while(cas < cn)
    {
        printf("Case #%d:\n",++cas);
        scanf("%d",&n);
        work();
    }
    return 0;
}
