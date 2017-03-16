#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <cmath>
#include <algorithm>

using namespace std;

int e,r,n,v[11];
int ans;

void dfs(int remain,int id,int gain)
{
    //printf("%d %d %d %d\n", e, r, id, gain);
    if (id == n)
    {
        ans = max(ans, gain);
        return;
    }
    for (int i=0;i<=remain;++i)
    {
        dfs(min(remain-i+r,e), id+1, gain+v[id]*i);
    }
    return;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
//    freopen("B-small-attempt1.in","r",stdin);
//    freopen("B-small-attempt1.out","w",stdout);
    int t;
    scanf("%d",&t);
    for (int cases=1;cases<=t;++cases)
    {
        ans = 0;
        scanf("%d%d%d",&e,&r,&n);
        for (int i=0;i<n;++i)
        {
            scanf("%d",&v[i]);
        }
        dfs(e,0,0);
        printf("Case #%d: %d\n",cases,ans);
    }
    return 0;
}
