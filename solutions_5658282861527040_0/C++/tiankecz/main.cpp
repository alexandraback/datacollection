#include <cstring>
#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define LL __int64
LL dp[31][2][2][2];
int a[31],b[31],c[31];
void fun(int *p,int x)
{
    int i;
    for(i = 0; i <= 30; i ++)
    {
        if(x&(1<<i))
            p[i] = 1;
        else
            p[i] = 0;
    }
}
LL dfs(int pos,int ta,int tb,int tc)
{
    if(pos == -1)
    return 1;
    LL & res = dp[pos][ta][tb][tc];
    int x,y,z;
    if(res == -1)
    {
        res = 0;
        for(x = 0; x < 2; x ++)
        {
            for(y = 0; y < 2; y ++)
            {
                z = x&y;
                if((!ta||(x <= a[pos]))&&(!tb||(y <= b[pos]))&&(!tc||(z <= c[pos])))
                {
                    res += dfs(pos-1,ta&&(x == a[pos]),tb&&(y == b[pos]),tc&&(z == c[pos]));
                }
            }
        }
    }
    return res;
}
int main()
{
    int x,y,z,t,cas = 1;
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    scanf("%d",&t);

    while(t --)
    {
        scanf("%d%d%d",&x,&y,&z);
        memset(dp,-1,sizeof(dp));
        x --;
        y --;
        z --;
        fun(a,x);
        fun(b,y);
        fun(c,z);
        printf("Case #%d: %I64d\n",cas++,dfs(30,1,1,1));
    }
    return 0;
}
/*
5
1000000000 1000000000 1000000000
*/
