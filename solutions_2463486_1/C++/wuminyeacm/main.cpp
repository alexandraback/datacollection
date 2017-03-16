#include <stdio.h>
#include <math.h>
#include <string.h>
bool deal(long long  t)
{
    char tem[60000];
    int j=0;
    while (t)
    {
        tem[j++]=t%10;
        t/=10;
    }
    tem[j--]='\0';
    int i=0;
    while (i<j)
    {
        if (tem[i]!=tem[j]) return false;
        ++i,--j;
    }
    return true;
}
long long data[50000000];
int dn;
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    dn=0;
    for (int i=1;i<=10000000;++i)
    {
            long long tem=(long long)i*i;
            if (deal(i) && deal(tem) )
            {
                data[dn++]=tem;
            }
    }
    int T,cas=0;
    scanf("%d",&T);
    while (T--)
    {
        long long  a,b,cnt=0;
        scanf("%I64d%I64d",&a,&b);
        for (int i=0;i<dn;++i)
         if (data[i]<=b && data[i]>=a) ++cnt;
        printf("Case #%d: %I64d\n",++cas,cnt);
    }
}
