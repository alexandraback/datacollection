#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int main()
{
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    int i,j,n,T,cnt=1;
    long long r,t,ans,tmp;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lld%lld",&r,&t);
        ans=0;
        tmp=2*r+1;
        printf("Case #%d: ",cnt++);
        if (tmp<t)
        {
            printf("0\n");
            continue;
        }
        t-=tmp;
        ans=1;
        while(1)
        {
            tmp=tmp+4;
            if (tmp>t) break;
            t-=tmp;
            ans++;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
