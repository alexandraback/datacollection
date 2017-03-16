#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;
const int MaxN = 10000005;
int f[MaxN],Cnt;
char s[30];
int check()
{
    int len = strlen(s);
    for(int i = 0; i < len/2; i++)
        if(s[i]!=s[len-1-i])
            return 0;
    return 1;
}

void init()
{
    Cnt = 0;
    for(int i = 1; i < MaxN; i++)
    {
        sprintf(s,"%d",i);
        if(!check())continue;
        sprintf(s,"%I64d",(LL)i*(LL)i);
        if(!check())continue;
        f[Cnt++] = i;
    }

    return;
}

int main()
{
    freopen("C-large-1.in","r",stdin);
    freopen("C.out","w",stdout);
    init();
    int T,cas=0;scanf("%d",&T);
    LL A,B;
    while(T--)
    {
        scanf("%I64d%I64d",&A,&B);
        int lo,hi,l,r,mid;
        lo = -1, hi = Cnt;
        while(lo+1 < hi)
        {
            mid = (lo+hi)/2;
            if((LL)f[mid]*(LL)f[mid] >= A)hi = mid;
            else lo = mid;
        }
        l = hi;

        lo = -1, hi = Cnt;
        while(lo+1 < hi)
        {
            mid = (lo+hi)/2;
            if((LL)f[mid]*(LL)f[mid] <= B)lo = mid;
            else hi = mid;
        }
        r = lo;
        printf("Case #%d: %d\n",++cas,r-l+1);
    }

    return 0;
}
