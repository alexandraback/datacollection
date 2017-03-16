
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define PB push_back
#define MP make_pair

#define REP(i,n) for(i=0;i<(n);++i)
#define FOR(i,l,h) for(i=(l);i<=(h);++i)
#define FORD(i,h,l) for(i=(h);i>=(l);--i)

#define ZERO (1e-9)
#define INF (2100000000)
#define LLINF (9200000000000000000)

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

int cmp(const void *a,const void *b)
{
    return (*(int *)a)-(*(int *)b);
}

int ind[1111],n,vis[1111],queu[1111],lef,righ;

VI node[1111];

int main()
{
    int tc,ti,i,tmp,j,u,v,res;
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    scanf("%d",&tc);
    for(ti=1;ti<=tc;ti++)
    {
        res=0;
        memset(ind,0,sizeof(ind));
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            node[i].clear();
        }
        for(i=1;i<=n;i++)
        {
            scanf("%d",&tmp);
            REP(j,tmp)
            {
                scanf("%d",&u);
                node[i].PB(u);
                ind[u]++;
            }
        }
        FOR(i,1,n)
        {
            if(!ind[i])
            {
                memset(vis,0,sizeof(vis));
                lef=0;righ=0;vis[i]=1;
                queu[righ]=i;righ=(righ+1)%1010;
                while(lef!=righ)
                {
                    tmp=queu[lef];
                    lef++;
                    REP(j,node[tmp].size())
                    {
                        if(vis[node[tmp][j]])
                        {
                            res=1;
                            break;
                        }
                        else
                        {
                            vis[node[tmp][j]]=1;
                            queu[righ]=node[tmp][j];righ=(righ+1)%1010;
                        }
                    }
                    if(res)break;
                }
                if(res)break;
            }
        }
        if(res)printf("Case #%d: Yes\n",ti);
        else printf("Case #%d: No\n",ti);
    }
    return 0;
}
