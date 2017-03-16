#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <queue>
#include <cmath>
#include <stack>
#include <map>
#include <set>

#define LL long long
#define ULL unsigned long long
#define INF 0x3f3f3f3f
#define EPS (1e-8)

using namespace std;

LL dis[1000010];

queue<LL> q;

int num[20];

LL Cal(LL x)
{
    int i;
    LL tmp = 1;
    memset(num,0,sizeof(num));
    for(i = 1;x;i++,x/= 10)
        num[i] = x%10;
    LL anw = 0;
    while(num[i] == 0)
        --i;
    for(tmp = 1;i >= 1; --i,tmp *= 10)
        anw += num[i]*tmp;
    return anw;
}

LL bfs(LL n)
{
    while(q.empty() == false)
        q.pop();

    memset(dis,INF,sizeof(dis));

    q.push(1);
    dis[1] = 1;

    while(q.empty() == false)
    {
        LL f = q.front();
        q.pop();

        if(f == n)
            return dis[f];

        if(dis[f+1] > dis[f]+1)
            q.push(f+1),dis[f+1] = dis[f]+1;
        LL t = Cal(f);
        if(dis[t] > dis[f]+1)
            q.push(t),dis[t] = dis[f]+1;
    }
}

int main()
{
    int T,icase = 1;
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);

    scanf("%d",&T);

    LL n;

    while(T--)
    {
        scanf("%lld",&n);

        printf("Case #%d: %lld\n",icase++,bfs(n));
    }

    return 0;
}











