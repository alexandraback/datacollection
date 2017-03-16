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
int n,m,map[105][105];
void init()
{
    scanf("%d%d",&n,&m);
    int i,j;
    met(map,0);
    FOR(i,1,n)
    {
        FOR(j,1,m)
        {
            scanf("%d",&map[i][j]);
        }
    }
}

string work()
{
    int i,j,k,t1,t2;
    FOR(i,1,n)
    {
        FOR(j,1,m)
        {
            t1=1;
            FOR(k,1,n)
            {
                if(map[k][j]>map[i][j])
                {
                    t1=0;
                    break;
                }
            }
            t2=1;
            FOR(k,1,m)
            {
                if(map[i][k]>map[i][j])
                {
                    t2=0;
                    break;
                }
            }
            if(t1+t2==0)return "NO";
        }
    }
    return "YES";
}

int main()
{
    int i,T;
    scanf("%d",&T);
    FOR(i,1,T)
    {
        init();
        printf("Case #%d: ",i);
        cout<<work()<<endl;
    }
}
