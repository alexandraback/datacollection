#include <cstdio>
#include <algorithm>

using namespace std;

int cnt (long long val)
{
    if (val==0)
        return -1;
    int ret=0;
    int proc=0;
    while (proc!=(1<<10)-1)
    {
        ret++;
        long long cp=val*ret;
        while (cp)
        {
            proc|=1<<(cp%10);
            cp/=10;
        }
    }
    return ret;
}

int main()
{
    freopen("D:/in.txt","r",stdin);
    freopen("D:/out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for (int it=1; it<=t; it++)
    {
        printf("Case #%d: ",it);
        long long x;
        scanf("%lld",&x);
        long long code=cnt(x);
        if (code==-1)
            printf("INSOMNIA\n");
        else
            printf("%lld\n",x*code);
    }
}
