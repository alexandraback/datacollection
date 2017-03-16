#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <cmath>
#define N 10005
#define INF 0x6f6f6f6f
#define debug(a) cout<<#a<<' '<<a<<endl;
typedef long long LL;
using namespace std;
int last[N],a[N];
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("/home/longmenwaideyu/下载/4.in","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
    int e,r,n;
    int T,cas=1;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d %d",&e,&r,&n);
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
        }
        memset(last,-1,sizeof(last));
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
                if(a[j]>=a[i])
                {
                    last[i]=j;
                    break;
                }
        }
        LL ans=0,now=e,has;
        for(int i=1;i<n;i++)
        {
            if(last[i]==-1)
            {
                ans+=a[i]*(now);
                now=r;
                continue;
            }
            has=(last[i]-i)*r;
            if(now+has>e)
            {
                if(now<=has)
                {
                    ans+=a[i]*now;
                    now=r;
                }else
                {
                    ans+=a[i]*has;
                    now=now-has+r;
                }
            }else
            {
                now+=r;
            }
        }
        ans+=now*a[n];
        printf("Case #%d: %lld\n",cas++,ans);
    }
	return 0;
}
