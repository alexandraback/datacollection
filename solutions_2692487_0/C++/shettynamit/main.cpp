#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#define N 101
using namespace std;

multiset<int> osmo;
typedef long long LL;
int solve(LL a)
{
    while(!osmo.empty())
    {
        if(*(osmo.begin())<a)
            a += *(osmo.begin());
        else
            break;
        osmo.erase(osmo.begin());
    }
    if(osmo.empty())
        return 0;
    int ans = osmo.size();
    a = (a*2-1);
    if(a==1)
        return ans;
    return min(ans,1+solve(a));
}

int main()
{
    freopen("small.in","r",stdin);
    freopen("small.out","w",stdout);
    int A,t,casenum,n,x,i;
    scanf("%d",&t);
    for(casenum=1;casenum<=t;casenum++)
    {
        osmo.clear();
        scanf("%d%d",&A,&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&x);
            osmo.insert(x);
        }
        printf("Case #%d: %d\n",casenum,solve((LL)A));
    }

    return 0;
}
