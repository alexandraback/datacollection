#include <stdio.h>
#include <stdlib.h>
int isp(int x)
{
    int a[3],l=0,i;
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
            if(a[i]!=a[l-i]) return 0;
        }
        return 1;
    }
}
int main()
{
    int T,c,a,b,cnt,i,j,p[11]={1,2,3,4,5,6,7,8,9,11,22};
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C-small-attempt0.out","w",stdout);
    scanf("%d",&T);
    for(c=1;c<=T;c++)
    {
        printf("Case #%d: ",c);
        cnt=0;
        scanf("%d%d",&a,&b);
        for(i=a;i<=b;i++)
        {
            if(isp(i))
            {
                for(j=0;j<11;j++)
                {
                    if(p[j]*p[j]==i) cnt++;
                }
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
