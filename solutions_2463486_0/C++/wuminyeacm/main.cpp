#include <stdio.h>
#include <math.h>
#include <string.h>
bool deal(int t)
{
    char tem[100];
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
bool work(int k)
{
    int t=(int)sqrt(k);
    if (t*t!=k) return false;
    if (deal(k) && deal(t)) return true;
    return false;
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T,cas=0;
    scanf("%d",&T);
    while (T--)
    {
        int a,b,cnt=0;
        scanf("%d%d",&a,&b);
        for (int i=a;i<=b;++i)
        {
            if (work(i)) ++cnt;
        }
        printf("Case #%d: %d\n",++cas,cnt);
    }
}
