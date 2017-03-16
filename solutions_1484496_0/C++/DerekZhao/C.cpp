
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

int n,num[22],fres,res[2][22],sum[1111111],f[11111111],ressum;

int cmp(const void *a,const void *b)
{
    return (*(int *)a)-(*(int *)b);
}

int dfs(int k,int now)
{
    if(k>=n)
    {
        int i,tmp;
        sum[now]=0;
        tmp=now;
        for(i=0; i<n; i++)
        {
            sum[now]+=(tmp&1)*num[i];
            tmp=tmp>>1;
        }
        f[sum[now]]++;
        return 0;
    }
    dfs(k+1,(now<<1)+1);
    dfs(k+1,(now<<1));
    return 0;
}

int main()
{
    int i,tc,ti,tmp,j,k;
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C-small-attempt0.out","w",stdout);
    scanf("%d",&tc);
    for(ti=1; ti<=tc; ti++)
    {
        fres=0;
        memset(f,0,sizeof(f));
        scanf("%d",&n);
        for(i=0; i<n; i++)
        {
            scanf("%d",num+i);
        }
        dfs(0,0);
        for(i=0; i<11111111; i++)
        {
            if(f[i]>1)
            {
                ressum=i;
                fres=1;
                break;
            }
        }
        if(fres)
        {
            for(i=0; i<(1<<n); i++)
            {
                if(sum[i]==ressum)
                {
                    tmp=i;
                    k=0;
                    for(j=0; j<n; j++)
                    {
                        if(tmp&1)res[0][++k]=num[j];
                        tmp=tmp>>1;
                    }
                    res[0][0]=k;
                    break;
                }
            }
            i++;
            for(; i<(1<<n); i++)
            {
                if(sum[i]==ressum)
                {
                    tmp=i;
                    k=0;
                    for(j=0; j<n; j++)
                    {
                        if(tmp&1)res[1][++k]=num[j];
                        tmp=tmp>>1;
                    }
                    res[1][0]=k;
                    break;
                }
            }
        }
        if(fres)
        {
            printf("Case #%d:\n",ti);
            printf("%d",res[0][1]);
            for(i=1; i<res[0][0]; i++)
            {
                printf(" %d",res[0][i+1]);
            }
            printf("\n%d",res[1][1]);
            for(i=1; i<res[1][0]; i++)
            {
                printf(" %d",res[1][i+1]);
            }
        }
        else
        {
            printf("Impossible");
        }
        printf("\n");
    }
    return 0;
}
