#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;
long long k,c;
vector<long long> an;
long long tg;
long long wk(long long bf,int df)
{
    if(df==c+1)
        return bf+1;
    bf*=k;
    bf+=min(tg,k)-1;
    tg++;
    return wk(bf,df+1);
}
int main()
{
    freopen("D-small-attempt0.in","r",stdin);
    freopen("D.out","w",stdout);
    int t,s;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        scanf("%lld%lld%d",&k,&c,&s);
        an.clear();
        tg=1;
        while(tg<=k)
            an.push_back(wk(0,1));
        printf("Case #%d: ",i);
        if(an.size()>s)
        {
            printf("IMPOSSIBLE\n");
            continue;
        }
        for(int j=0;j<an.size();j++)
            printf("%lld ",an[j]);
        printf("\n");
    }
}
