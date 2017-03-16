#include<cstdio>
#include<iostream>
#include <cstring>
using namespace std;
const int Maxn=int(2e6)+10;
int A,B;
int cnt[Maxn];
int check(int x)
{
    int ret=1;
    for(int tmp=10;tmp<=x;tmp*=10)
    {
        int y=x%tmp,z=x/tmp;
        int j;
        for(j=10;j<=z;j*=10);
        int x1=z+y*j;
        if(x1==x)continue;
        if(A<=x1&&x1<=B&&cnt[x1]==-1)
        {
            cnt[x1]=1;
            ret++;
        }
    }
    return ret;
}
typedef __int64 ll;
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t;scanf("%d",&t);
    for(int cas=1;cas<=t;++cas)
    {
        memset(cnt,-1,sizeof(cnt));
        scanf("%d%d",&A,&B);
        for(int i=A;i<=B;++i)
        {
            if(cnt[i]==-1)
            {
                cnt[i]=check(i);
            }
        }
        ll ans=0;
        for(int i=A;i<=B;++i)
        {
            if(cnt[i]==1)continue;
            ans+=cnt[i]*(cnt[i]-1)/2;
        }
        printf("Case #%d: %I64d\n",cas,ans);
    }
}
