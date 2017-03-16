#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <map>
using namespace std;
const int maxn = 22;
long long num[22];
int n;

void solve()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i)
           scanf("%lld",&num[i]);

    map <long long,long long> m;
    long long b=(long long)1<<20;
    long long ans1=-1,ans2=-1;
    for(long long i=1;i<b;++i)
    {
        long long sum=0;
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
       printf("Impossible\n");
    else
    {
        long long ans[2][40];
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
    return;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int casn,cas = 0;
    scanf("%d",&casn);
    while(cas < casn)
    {
        printf("Case #%d:\n",++cas);
        solve();
    }
    return 0;
}
