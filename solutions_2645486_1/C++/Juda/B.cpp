#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
#define DEBUG 0
#define debug(cc) if(DEBUG)cout<<#cc<<" : "<<cc<<endl;
#define REP(i,n) for(i=0;i<n;++i)
#define FOR(i,j,k) for(i=j;i<=k;++i)
#define FORD(i,j,k) for(i=j;i>=k;--i)
#define met(i,j) memset(i,j,sizeof(i))
#define PB push_back
#define MK make_pair
#define sz(x) ((int)x.size())
#define IOopen ios_base::sync_with_stdio(false)
const int inf=2147483647;
typedef pair<int, int> PII;
typedef long long LL;
typedef unsigned long long ULL;
#define N 10004
LL v[N],ans,e,r;
int n,f[16][N];

void init()
{
    int i,j,t1,t2;
    FOR(i,1,n)f[0][i]=i;
    FOR(j,1,15)
    {
        FOR(i,1,n)
        if(i+(1<<j)-1<=n)
        {
            t1=f[j-1][i];
            t2=f[j-1][i+(1<<(j-1))];
            if (v[t1]>=v[t2]) f[j][i]=t1;else f[j][i]=t2;
        }else break;
    }
}

int getmax(int t1,int t2)
{
    int s1,s2,k;
    k=int(log(double(t2-t1+1))/log(2.));
    s1=f[k][t1];
    s2=f[k][t2-(1<<k)+1];
    return v[s1]>=v[s2]?s1:s2;
}

LL F(LL x)
{
    return x>0?x:0;
}

void calc(int t1,int t2,LL s,LL t)
{
    if(t1>t2)return;
    if(t1==t2)
    {
        ans+=v[t1]*F(s-(t-r));
    }else
    {
        int k;LL s1,s2;
        k=getmax(t1,t2);
        s1=min(e,s+r*(k-t1));
        if(r*(t2-k)<t-r)s2=t-r-r*(t2-k);else s2=0;
        ans+=v[k]*(s1-s2);
        calc(t1,k-1,s,s1);
        calc(k+1,t2,s2+r,t);
    }
}

void work()
{
    scanf("%I64d%I64d%d",&e,&r,&n);
    int i;
    FOR(i,1,n)scanf("%I64d",v+i);
    init();
    calc(1,n,e,r);
}

int main()
{
    int i,t;
    scanf("%d",&t);
    FOR(i,1,t)
    {
        ans=0;
        work();
        printf("Case #%d: %I64d\n",i,ans);
    }
}
