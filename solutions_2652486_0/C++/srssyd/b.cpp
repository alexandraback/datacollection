#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int Maxn=32,Maxm=1200;
int f[Maxn][Maxm];
int v[Maxn];
int main()
{
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
    int T;
    scanf("%d",&T);
    int casno=0;
    while(T--)
    {
        int e,r,n;
        memset(f, 0, sizeof(f));
        casno++;
        cin>>e>>r>>n;
        for (int i=1;i<=n;i++) cin>>v[i];
        for (int i=1;i<=n;i++)
            for (int j=0;j<=e;j++)
                for (int k=0;k<=j;k++)
                {
                    int tmp=j-k+r;
                    int val=k*v[i];
                    if (tmp>e) tmp=e;
                    f[i+1][tmp]=max(f[i+1][tmp],val+f[i][j]);
                }
        int ans=0;
        for (int i=0;i<=e;i++) ans=max(ans,f[n+1][i]);
        cout<<"Case #"<<casno<<": ";
        cout<<ans<<endl;
    }
    return 0;
}
