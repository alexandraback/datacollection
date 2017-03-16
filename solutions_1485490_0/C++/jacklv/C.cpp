#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
const int maxn=110;
ll a[maxn],A[maxn],b[maxn],B[maxn];
ll ans;
ll f[maxn][maxn];
ll sa[maxn][maxn],sb[maxn][maxn];
int n,m,ty;
ll max(ll a, ll b)
{
    if (a>b) return a; else return b;
}
ll min(ll a,ll b)
{
    if (a>b) return b; else return a;
}
void init()
{
    scanf("%d%d",&n,&m);
    ty=0;
    for (int i=1; i<=n; i++)
    {
        scanf("%lld%lld",&a[i],&A[i]);
        if (ty<A[i]) ty=A[i];
        for (int j=0; j<=100; j++)
        sa[j][i]=sa[j][i-1];
        sa[A[i]][i]+=a[i];
    }
    for (int i=1; i<=m; i++)
    {
        scanf("%lld%lld",&b[i],&B[i]);
        if (ty<B[i]) ty=B[i];
        for (int j=0; j<=100; j++)
        sb[j][i]=sb[j][i-1];
        sb[B[i]][i]+=b[i];
    }
    for (int i=0; i<=n; i++)
    for (int j=0; j<=m; j++)
    f[i][j]=0;
}
void run()
{
    for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
    {
        for (int k=1; k<=i; k++)
        for (int t=1; t<=j; t++)
        for (int typ=1; typ<=ty; typ++)
        f[i][j]=max(f[i][j],f[i-k][j-t]+min(sa[typ][i]-sa[typ][i-k],sb[typ][j]-sb[typ][j-t]));
    }
}
int main()
{
    freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    int T; cin>>T;
    for (int tt=1; tt<=T; tt++)
    {
        init();
        run();
        ans=f[n][m];
        printf("Case #%d: %lld\n",tt,ans);
    }
}
