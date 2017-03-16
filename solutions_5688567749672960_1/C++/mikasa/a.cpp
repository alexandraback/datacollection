#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>

#define pb push_back
#define mkp make_pair

using namespace std;
typedef long long ll;
const int maxn = 10001;
const int maxh = 40;
ll pw[maxh];
int vis[maxn];
int q[maxn];

ll rev(ll x)
{
    ll r = 0;
    while(x)
    {
        ll t = x%10;
        r = 10*r + t;
        x/=10;
    }
    return r;
}
void bfs()
{
    vis[1] = 1;
    int front =1,tail = 0;
    q[++tail] = 1;
    while(tail>=front)
    {
        int t= q[front++];
        if(t+1<maxn&&vis[t+1]==0)
        {
            q[++tail] = t+1;
            vis[t+1] = vis[t]+1;
        }
        if(rev(t)<maxn&&vis[rev(t)]==0)
        {
            q[++tail] = rev(t);
            vis[rev(t)] = vis[t]+1;
        }
    }
    //puts("end");
    //for(int i=1;i<maxn;i++)
      //  printf("vis[%d]=%d\n",i,vis[i]);
}

int cnt(ll x)
{
    int r=0;
    while(x)
    {
        r++;
        x/=10;
    }
    return r;
}
int sol(ll x)
{
    if(x<maxn)
        return vis[x];
    int le = cnt(x);
    ll base,cha,bc;
    if(le&1)
    {
        cha = pw[le/2-1];
        bc = pw[le/2+1];
        int y = (le-5)/2;
        base = 1 + pw[y+3] + pw[2*y+4];
    }
    else
    {
        int y = (le-4)/2;
        base = 1+pw[y+2]+pw[2*y+3];
        bc = pw[le/2];
        cha = pw[le/2-1];
    }
    //printf("x=%lld,base=%lld\n",x,base);
    if(base==x)
        return sol(rev(x))+1;
    if(base>x)
    {
        return sol(pw[le-1]-1)+x-(pw[le-1]-1);
    }
    //printf("bc=%lld,cha=%lld\n",bc,cha);
    ll pre =  (x-base)/bc*bc+base;
    if(pre==x)
    {
        return sol(rev(x))+1;
    }
    return sol(pre)+x-pre;
}
int main()
{
    pw[0] = 1;
    for(int i=1;i<maxh;i++)
        pw[i] = pw[i-1]*10;
    //printf("%d\n",rev(432));
    bfs();int cn = 0;
    /*for(int i=1+maxn/10;i<maxn;i++)
    {
        if(vis[i]!=vis[i-1]+1)
        {
            printf("vis[%d]=%d\n",i,vis[i]);
            cn++;
        }
    }*/
        int t,cas;ll a;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&a);
        printf("Case #%d: %d\n",++cas,sol(a));
    }
}
