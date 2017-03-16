#include <iostream>
#include <string.h>
#include <cstdio>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstdlib>
#include <limits.h>
#include <vector>
#include <string>
#include <ctype.h>
#include <complex>
#include <cmath>
#include <bitset>
using namespace             std;
const int                   Maxn=32,Maxm=1200,Mo=7340033,oo=INT_MAX>>2;
int                         d,r,i,j,k,n,e,cs,tt,                   f[Maxn][Maxm],tmp[Maxm],v[Maxn];
int main()
{
    ios::sync_with_stdio(0);
    freopen("/Users/MAC/Desktop/Error202/Error202/1.in","r",stdin);
    freopen("/Users/MAC/Desktop/Error202/Error202/1.out","w",stdout);
    cin>>cs;
    while(cs--)
    {
        cout<<"Case #"<<++tt<<": ";
        memset(f, 0, sizeof(f));
        cin>>e>>r>>n;
        for (i=1;i<=n;i++) cin>>v[i];
        for (i=1;i<=n;i++)
            for (j=0;j<=e;j++)
            {
                for (k=0;k<=j;k++)
                {
                    int tmp=j-k+r;
                    int val=k*v[i];
                    if (tmp>e) tmp=e;
                    f[i+1][tmp]=max(f[i+1][tmp],val+f[i][j]);
                }
            }
        int ans=0;
        for (i=0;i<=e;i++) ans=max(ans,f[n+1][i]);
        cout<<ans<<endl;
    }
    
}