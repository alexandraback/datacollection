#include<stdio.h>
#include<iostream>
#include <string.h>
using namespace std;
#define Maxn 2000200
int A,B;
long long ans[Maxn];
int cc(int x)
{
    int zz=1;
    int aa=10;
    while(aa<=x)
    {
        int y=x%aa,z=x/aa;
        int j;
       // cout<<x<<' '<<aa<<endl;

        j=10;
        while(j<=z)j*=10;
        int x1=z+y*j;
        if(x1==x){aa*=10;continue;}
        if(A<=x1&&x1<=B&&ans[x1]==-1)
        {
            ans[x1]=1;
            zz++;
        }
        aa*=10;

    }
    return zz;
}
int main()
{
    freopen("in3.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int cas=1;cas<=t;++cas)
    {
        memset(ans,-1,sizeof(ans));
        scanf("%d%d",&A,&B);
        for(int i=A;i<=B;++i)
        {
            if(ans[i]==-1)
            {
                ans[i]=cc(i);

            }
            //cout<<i<<' '<<ans[i]<<endl;
        }
        long long answer=0;
        for(int i=A;i<=B;++i)
        {
            if(ans[i]==1)continue;
            answer+=ans[i]*(ans[i]-1)/2;
        }
        printf("Case #%d: %lld\n",cas,answer);
    }
}
