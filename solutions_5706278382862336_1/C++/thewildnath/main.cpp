#include<stdio.h>

int bun(long long x,long long y)
{
    if(x>y||x<0||y<=0)return 0;
    if(x==y||x==0)return 1;

    int nr=0;
    long long ax,ay;


    while(y>2*x&&y%2==0)y/=2,++nr;
    ax=2*x-y;ay=y;++nr;

    if(bun(ax,ay))return nr;
    else return 0;
}

int main()
{
    //freopen("date.in","r",stdin);
    //freopen("date.out","w",stdout);
    int test,t,ok;
    long long x,y;

    scanf("%d",&test);
    for(t=1;t<=test;++t)
    {
        scanf("%lld/%lld",&x,&y);

        ok=bun(x,y);

        printf("Case #%d: ",t);
        if(!ok)printf("impossible\n");
        else printf("%d\n",ok);
    }

    return 0;
}
