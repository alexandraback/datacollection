#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<set>
#include<bitset>
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
#define N 405
#define M 20
int k,n,a[N],t[N],d[N],key[N][N],ans[N];
set<ULL> visit;

void init()
{
    scanf("%d%d",&k,&n);
    met(a,0);
    int i,t1,j;
    FOR(i,1,k)
    {
        scanf("%d",&t1);
        a[t1]++;
    }
    FOR(i,1,n)
    {
        scanf("%d%d",&t[i],&d[i]);
        FOR(j,1,d[i])scanf("%d",&key[i][j]);
    }
}

ULL hash()
{
    ULL tmp=0;int i;
    FOR(i,1,200)
    {
        (tmp*=233)+=a[i]*7;
    }
    return tmp;
}

bool dfs(int ii,ULL b)
{
    int i,j;
    if(ii>n)
    {
        FOR(i,1,n)printf(" %d",ans[i]);
        printf("\n");
        return 1;
    }else
    {
        ULL p;
        FOR(i,1,n)
        if(!((b>>(i-1))&1))
        {
            if(a[t[i]])
            {
                p=b;
                p+=(1<<(i-1));
                if(visit.count(p))continue;
                visit.insert(p);
                a[t[i]]--;
                ans[ii]=i;
                FOR(j,1,d[i])a[key[i][j]]++;
                if(dfs(ii+1,p))return 1;
                FOR(j,1,d[i])a[key[i][j]]--;
                a[t[i]]++;
            }
        }
        return 0;
    }
}

void work()
{
    visit.clear();
    if(!dfs(1,0ULL))puts(" IMPOSSIBLE");
}

int main()
{
    int i,T;
    scanf("%d",&T);
    FOR(i,1,T)
    {
        printf("Case #%d:",i);
        init();
        work();
    }
}
