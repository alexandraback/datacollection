#include<stdio.h>
#include<iostream>
long long r,t;
int T,a[40];

void inmul(long long x)
{
    long long carry=0;
    for(int i=1;i<=a[0];++i)
    {
        long long y=a[i]*x+carry;
        a[i]=y%10;
        carry=y/10;
    }
    while(carry>0)
    {
        ++a[0];
        a[a[0]]=carry%10;
        carry=carry/10;
    }
}

void afisare ()
{
    for(int i=a[0];i>=1;--i)
        printf("%d",a[i]);
}

int cmp(long long x)
{
    int b[40];
    b[0]=0;
    while(x>0)
    {
        ++b[0];
        b[b[0]]=x%10;
        x=x/10;
    }

    if(b[0]>a[0])
    {
        return 0;
    }
    if(b[0]<a[0])
    {
        return 1;
    }
    int k=b[0];
    while(a[k]==b[k] && k>=1)
        --k;

    if(a[k]>b[k])
        return 1;

    if(a[k]<=b[k])
        return 0;
}

int caut(long long x,long long y)
{
    int st=1;
    int dr=1000000000;
    int ret=0;

    while(st<=dr)
    {
        a[0]=1;
        a[1]=1;
        long long mij=(st+dr)/2;
        long long z=2*mij+2*x-1;
        inmul(z);
        inmul(mij);

        if(cmp(y)==1)
        {
            dr=mij-1;
        }
        else
        {
            ret=mij;
            st=mij+1;
        }
    }
    return ret;
}

int main()
{
    freopen("input.in","r",stdin);
    freopen("bla.out","w",stdout);
    scanf("%d",&T);
    for(int i=1;i<=T;++i)
    {
        scanf("%lld%lld",&r,&t);
        printf("Case #%d: %d\n",i,caut(r,t));
    }
    return 0;
}

