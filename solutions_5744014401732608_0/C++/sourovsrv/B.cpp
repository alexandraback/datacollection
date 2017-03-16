#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll Mat[8][8];
ll pos(ll nw)
{
    ll pw=1;
    while(nw)
    {
        nw--;
        pw*=2;
    }
    return pw;
}
ll ar[100];
ll createbinary(ll n)
{
    ll nw=0,i=0;
    while(n!=0)
    {
        nw=n%2;
        n/=2;
        ar[i++]=nw;
    }
    return i;
}
int main()
{
    //freopen("B-small-attempt2.in","r",stdin);
    //freopen("B-small-attempt2.out","w",stdout);
    ll t,cs,n,i,in,b,m,nw,j,ln;
    scanf("%lld",&t);
    for(cs=1;cs<=t;cs++)
    {
        scanf("%lld%lld",&b,&m);
        //cout<<b<<" "<<m<<endl<<endl;
        ll psb=pos(b-2);
        if(psb<m)
        {
            printf("Case #%lld: IMPOSSIBLE\n",cs);
            continue;
        }

        memset(Mat,0,sizeof(Mat));
        Mat[1][b]=1;
        for(i=1;i<m;i++)
        {
            ll len=createbinary(i);
            nw=1;
            for(j=0;j<len;j++)
            {
                //cout<<ar[j];
                if(ar[j]==1)
                {
                    Mat[nw][j+2]=1;
                    nw=j+2;
                }
            }
            //cout<<endl;
            Mat[nw][b]=1;

        }
        printf("Case #%lld: POSSIBLE\n",cs);
        for(i=1;i<=b;i++)
        {
            for(j=1;j<=b;j++)
            {
                printf("%lld",Mat[i][j]);
            }
            printf("\n");
        }

    }

    return 0;
}
