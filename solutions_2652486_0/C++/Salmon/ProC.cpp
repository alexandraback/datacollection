#include <cstdio>
int r,n,m,k;
int fi()
{
    int pr=1,tem,ans=0;
    bool us[10];
    for(int j=0;j<7;j++)
    {
        scanf("%d",&tem);
        pr*=tem;
        if(tem%5==0&&!us[5])
        {
            us[5]=1;
            ans*=10+5;
        }
        if(tem==2&&!us[2])
        {
            us[2]=1;
            ans*=10+2;
        }
        if(tem%3==0&&!us[3])
        {
            us[3]=1;
            ans*=10+3;
        }
    }
    for(int i=5;i>=2;i--)
    {
        if(us[i]&&pr%(i*i)==0)
            pr/=i*i;
    }
    for(int i=5;i>=2;i--)
    {
        while(ans<100&&pr%(i*i)==0)
        {
            ans=10*ans+i;
            pr/=i*i;
        }
    }
    while(ans<100)
        ans=ans*10+2;
    printf("\n%d",ans);
}
int main()
{
    freopen("c.in","r",stdin);
    freopen("c.out","w",stdout);
    scanf("%d",&r);
    printf("Case #1:");
    scanf("%d%d%d%d",&r,&n,&m,&k);
    for(int i=0;i<r;i++)
    {
        fi();
    }
}
