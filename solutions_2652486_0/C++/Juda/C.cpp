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
int R,n,m,K,a[105][8],bj[105];

void init()
{
    cin>>R>>n>>m>>K;
    int i,j;
    FOR(i,1,R)
    {
        FOR(j,1,K)
        {
            scanf("%d",&a[i][j]);
        }
    }
}


void work()
{
    int i,j,k,ii,ok,i2,tmp;
    init();
    FOR(i,2,m)
    {
        FOR(j,2,m)
        {
            FOR(k,2,m)
            {
                FOR(ii,1,R)
                if(!bj[ii])
                {
                    ok=1;
                    FOR(i2,1,K)
                    {
                        tmp=a[ii][i2];
                        if(tmp%i==0)tmp/=i;
                        if(tmp%j==0)tmp/=j;
                        if(tmp%k==0)tmp/=k;
                        if(tmp!=1)
                        {
                            ok=0;
                            break;
                        }
                    }
                    if(ok)
                    {
                        bj[ii]=i*100+j*10+k;
                    }
                }
            }
        }
    }
    FOR(i,1,R)
    {
        if(bj[i])printf("%d\n",bj[i]);else printf("222\n");
    }
}

int main()
{
    freopen("C.in","r",stdin);
    scanf("%*d");
    printf("Case #1:\n");
    work();
}
