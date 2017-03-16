#include<bits/stdc++.h>
using namespace std;
#define sd(x) scanf("%d",&x)
#define slld(x) scanf("%lld",&x)
#define ss(x) scanf("%s",x)
#define ll long long
#define mod 1000000007
#define bitcount    __builtin_popcountll
#define pb push_back
int main()
{
    freopen("codejambffsin.txt","r",stdin);
    freopen("codejambffsout2.txt","w",stdout);
    int t,n,i,j,k,a[1003],b[1003],x,max1,cnt,cnt1,k1,l,r,y;
    sd(t);
    for(x=1;x<=t;x++)
    {
        sd(n);
        for(i=1;i<=n;i++)
        {
            sd(a[i]);
        }
        max1=1;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
                b[j]=0;
            l=1;
            cnt=1;
            b[i]=1;
            r=i;
            k=i;
            while(a[k]!=i&&a[k]!=r&&cnt!=n)
            {
                r=k;
                k=a[k];
                b[k]=1;
                cnt++;
            }
            if(a[k]==i)
            {
                //printf("%d ",cnt);
                max1=max(cnt,max1);
            }
            if(a[k]==r)
            {
                max1=max(max1,cnt);
                for(y=1;y<=n;y++)
                {
                    if(b[y]==0)
                    {
                        k1=y;
                        cnt1=1;
                        b[y]=1;
                        while(a[k1]!=k&&b[a[k1]]!=1)
                        {
                            r=k1;
                            k1=a[k1];
                            b[k1]=1;
                            cnt1++;
                        }
                        if(a[k1]==k)
                        {
                            max1=max(max1,cnt+cnt1);
                        }
                    }
                }
            }
        }
        printf("Case #%d: %d\n",x,max1);
    }
    return 0;
}
