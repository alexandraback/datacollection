#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<map>
using namespace std;
typedef long long LL;
typedef vector<int> VI;
typedef vector<double> VD;
typedef pair<int,int> PII;
#define PB push_back
#define MP make_pair
#define fi first
#define se second
#define inf 1e9
#define eps 1e-9
LL v[10005];
LL m,r,ret;
LL dfs(int s,int e,LL se, LL ee)
{
    int i, mj;
    LL ma = -1;
    if(s>e)
        return 0;
    for(i=s;i<=e;i++)
    {
        if(v[i]>ma)
        {
            ma = v[i];
            mj = i;
        }
    }
    LL be = min(se + (mj - s)*r, m), ae = max(0ll, ee - (e - mj + 1)*r);
    //printf("%d %d %lld %lld\n",s,e,be,ae);
    if( ae >= be )
        return 0;
    LL ret = (be - ae)*v[mj];
    ret += dfs(s, mj - 1, se, be);
    ret += dfs(mj + 1, e, min(ae + r, m), ee);
    return ret;
}
int main()
{
    int n,t;
    int i,j,k;

    freopen("bs.in","r",stdin);
    freopen("bs.out","w",stdout);
    scanf("%d",&t);
    for(int cnt = 1;cnt<=t;cnt++)
    {
        scanf("%lld%lld%d",&m,&r,&n);
        for(i=0;i<n;i++)
            scanf("%lld",v+i);
        ret = 0;
        if(r>=m)
        {
            for(i=0;i<n;i++)
                ret+=v[i]*m;
            printf("Case #%d: %lld\n",cnt,ret);
            continue;
        }
        ret = dfs(0,n-1,m,0);
        printf("Case #%d: %lld\n",cnt,ret);
    }
    return 0;
}
