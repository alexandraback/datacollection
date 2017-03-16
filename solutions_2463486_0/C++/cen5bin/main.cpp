#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
bool judge(LL n)
{
    int a[20];
    int cnt = 0;
    while(n) a[cnt++] = n % 10, n/= 10;
    for(int i=0; i<cnt/2; i++)
    if(a[i]!=a[cnt-1-i]) return 0;
    return 1;
}
LL p[10000];
int main()
{
    freopen("a.in","r",stdin);
    freopen("out.txt","w",stdout);
    int cnt = 0;
    for(LL i=1; i<10000000; i++)
    if(judge(i))
    {
        LL tmp = i*i;
        if(judge(tmp)) p[cnt++] = tmp;
    }
    int T;
    scanf("%d",&T);
    for(int t=1; t<=T; t++)
    {
        LL a,b;
        scanf("%I64d%I64d",&a,&b);
        LL x1 = lower_bound(p,p+cnt,a) - p;
        LL x2 = lower_bound(p,p+cnt,b) - p;
        LL ans = x2 - x1;
        if(p[x2]==b) ans++;
        printf("Case #%d: %I64d\n",t,ans);
    }
    return 0;
}
