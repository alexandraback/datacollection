#include<stdio.h>
int k,T;
long long y,b[45],A,B;
int is_palin(long long x)
{
    int a[16],k=0;
    long long z=x;
    while(z)
    {
        ++k;
        a[k]=z%10;
        z=z/10;
    }
    for(int j=1;j<=(k+1)/2;++j)
        if(a[j]!=a[k+1-j])
            return 1;
    return 0;
}

int main()
{
    freopen("input.in","r",stdin);
    freopen("bla.out","w",stdout);
    for(int i=1;i<=10000000;++i)
    {
        if(is_palin(i)==0)
        {
            y=1LL*i*i;
            if(is_palin(y)==0)
            {
                ++k;
                b[k]=y;
            }
        }
    }

    scanf("%d",&T);
    for(int i=1;i<=T;++i)
    {
        scanf("%lld%lld",&A,&B);
        int s=1;
        for(s=1;s<=k;++s)
        {
            if(b[s]>=A)
                break;
        }
        int t=s;

        for(t=s;t<=k;++t)
        {
            if(b[t]>B)
                break;
        }

        printf("Case #%d: %d\n",i,t-s);
    }
    return 0;
}
