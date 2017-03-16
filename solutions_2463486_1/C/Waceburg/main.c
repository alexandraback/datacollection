#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef long long LL;
int p[1000000],cnt=0;
int isp(LL x)
{
    int a[14],l=0,i;
    while(x)
    {
        a[l++]=x%10;
        x/=10;
    }
    if(l%2)
    {
        l>>=1;
        for(i=1;i<=l;i++)
        {
            if(a[l-i]!=a[l+i]) return 0;
        }
        return 1;
    }
    else
    {
        for(i=0;i<(l>>1);i++)
        {
            if(a[i]!=a[l-i-1]) return 0;
        }
        return 1;
    }
}
int bs1(int x)
{
    int l=0,r=cnt-1,mid=(l+r)>>1;
    while(l<=r)
    {
        if(p[mid]>=x) r=mid-1;
        else l=mid+1;
        mid=(l+r)>>1;
    }
    return l;
}
int bs2(int x)
{
    int l=0,r=cnt-1,mid=(l+r)>>1;
    while(l<=r)
    {
        if(p[mid]>x) r=mid-1;
        else l=mid+1;
        mid=(l+r)>>1;
    }
    return r;
}
int main()
{
    int T,c,tot,low,high,s,t,i;
    double aa;
    LL a,b,temp;
    for(i=1;i<10000000;i++)
    {
        if(isp(i)) p[cnt++]=i;
    }
    freopen("C-large-1.in","r",stdin);
    freopen("C-large-1.out","w",stdout);
    scanf("%d",&T);
    for(c=1;c<=T;c++)
    {
        printf("Case #%d: ",c);
        tot=0;
        scanf("%lld%lld",&a,&b);
        aa=sqrt(a);
        high=sqrt(b);
        if(floor(aa)!=aa) low=aa+1;
        else low=aa;
        s=bs1(low);
        t=bs2(high);
        for(i=s;i<=t;i++)
        {
            temp=(LL)p[i]*p[i];
            if(isp(temp)) tot++;
        }
        printf("%d\n",tot);
    }
    return 0;
}
