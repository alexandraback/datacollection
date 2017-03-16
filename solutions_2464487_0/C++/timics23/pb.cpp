#include<stdio.h>
#include<iostream>

long long r,t;
int T;

int caut(long long a,long long b)
{
    int st=1;
    int dr=1000000000;
    int ret=0;
    while(st<=dr)
    {
        int mij=(st+dr)/2;
        long long c=mij*(2*mij+2*a-1);
        if(c>b)
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

