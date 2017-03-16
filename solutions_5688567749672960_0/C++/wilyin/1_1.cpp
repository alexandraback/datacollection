#include<bits/stdc++.h>
#define scf scanf
#define ptf printf
#define forp(i,j,k) for(int i=j;i<k;i++)
#define form(i,j,k) for(int i=j;i>k;i--)
#define sz(x) (int)x.size()
#define pb push_back
#define fst first
#define scd second
#define m_p make_pair
#define pct __builtin_popcount
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;

vector<int>lis;

int rv(int x)
{
    lis.clear();
    for(;x;x/=10)lis.pb(x%10);
    int res=0;
    forp(i,0,sz(lis))
        res=res*10+lis[i];
    return res;
}

int st[10000100],q[10000010];

int main()
{
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    int T;
    scf("%d",&T);
    int l=0,r=1;
    q[l]=1;st[1]=1;
    for(;l!=r;l++)
    {
        int u=q[l];
        if(u>1e6)continue;
        if(!st[u+1])
        {
            st[u+1]=st[u]+1;
            q[r++]=u+1;
        }
        int t0=rv(u);
        if(!st[t0])
        {
            st[t0]=st[u]+1;
            q[r++]=t0;
        }
    }
    int n;
    forp(tcnt,0,T)
    {
        scf("%d",&n);
        ptf("Case #%d: %lld\n",tcnt+1,st[n]);

    }
    return 0;
}
