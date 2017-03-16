
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <math.h>
#include <cctype>
#include <stdlib.h>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <iterator>
#include <climits>

#define rep(i,n) for(i=1;i<=n;i++)
#define Rep(i,n) for(i=0;i<n;i++)
#define For(i,a,b) for(i=a;i<=b;i++)

#define pb(x) push_back(x)
#define sz(x) x.size()

#define mem(ara,val) memset(ara,val,sizeof(ara))
#define eps 1e-9

#define si(x) scanf("%d",&x)
#define sii(x,y) scanf("%d %d",&x,&y)
#define siii(x,y,z) scanf("%d %d %d",&x,&y,&z)
#define sl(x) scanf("%lld",&x)
#define sll(x,y) scanf("%lld %lld",&x,&y)
#define slll(x,y,z) scanf("%lld %lld %lld",&x,&y,&z)
#define ss(ch) scanf("%s",ch)
#define pi(x) printf("%d",x)
#define pii(x,y) printf("%d %d",x,y)
#define piii(x,y,z) printf("%d %d %d",x,y,z)
#define pl(x) printf("%lld",x)
#define pll(x,y) printf("%lld %lld",x,y)
#define plll(x,y,z) printf("%lld %lld %lld",x,y,z)
#define ps(ch) printf("%s",ch)
#define Afridi 0
#define NL printf("\n")
#define debug(x) printf("wow  %d !!\n",x)
#define Max 1000000
#define INF INT_MAX

typedef long long LL;
typedef unsigned long long ULL;

using namespace std;


///computing cost of every node from source

map <LL,bool> mp;
map <LL,LL> cst;
LL n;

LL rev(LL x)
{
    LL ind = 0,ans = 0,i;
    LL ara[15];
    while(x)
    {
        ara[ind++] = x%10;
        x/=10;
    }
    for(i=0;i<ind;i++)
    {
        ans*=10;
        ans+=ara[i];
    }
    return ans;
}

void bfs()
{
    mp[1] = 1;
    cst[1] = 1;
    queue <LL> q;
    q.push(1);
    LL cnt = 0;
    while(!q.empty())
    {
        LL u = q.front();
        cnt++;
        LL c = cst[u];
        if(cnt == 1000000)return;
        q.pop();
        if(u+1 <= 1000000 && mp.find(u+1) == mp.end())
        {
            mp[u+1] = 1;
            cst[u+1] = c+1;
            q.push(u+1);
        }
        LL v = rev(u);
        if(v<= 1000000 && mp.find(v) == mp.end())
        {
            mp[v] = 1;
            cst[v] = c+1;
            q.push(v);
        }
    }
}



int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("outAsmall.txt","w",stdout);
    LL t,T,ans;
    bfs();
    sl(T);
    rep(t,T)
    {
        sl(n);
        printf("Case #%lld: %lld\n",t,cst[n]);
    }
    return 0;
}


