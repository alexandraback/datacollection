#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
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
int f[15][8],v[15];
void updata(int &a,const int b)
{
    if(b>a)a=b;
}

int work()
{
    int e,r,n,i,j,k,ans=0;
    scanf("%d%d%d",&e,&r,&n);
    FOR(i,1,n)scanf("%d",v+i);
    met(f,-1);
    f[0][e]=0;
    FOR(i,1,n)
    {
        FOR(j,0,e)
        if(f[i-1][j]!=-1)
        {
            FOR(k,0,j)
            {
                updata(f[i][min(j-k+r,e)],f[i-1][j]+v[i]*k);
            }
        }
    }
    FOR(j,0,e)ans=max(ans,f[n][j]);
    return ans;
}

int main()
{
    int i,t;
    scanf("%d",&t);
    FOR(i,1,t)
    {
        printf("Case #%d: %d\n",i,work());
    }
}
