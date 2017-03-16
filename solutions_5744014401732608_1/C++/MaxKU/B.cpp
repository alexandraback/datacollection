#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
bool a[110][110];

void solve(int n, long long m)
{
    memset(a,0,sizeof(a));
    for (int i=n-2;i>0;i--)for (int j=i+1;j<n;j++) a[i][j]=1;
    long long max_f=1ll<<(n-2);
    if (m>max_f) puts("IMPOSSIBLE");
    else
    {
        puts("POSSIBLE");
        if (m==max_f)   for (int j=1;j<n;j++) a[0][j]=1;
        else
        {
            for (int k=0;n-2-k>=0;k++)    if ((m>>k)&1) a[0][n-2-k]=1;
        }
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++) printf("%d",a[i][j]);
            puts("");
        }
    }
}


int main()
{
    freopen("B.in","r",stdin);
    freopen("B.out","w",stdout);
    int T;
    scanf("%d",&T);
    for (int cas=1;cas<=T;cas++)
    {
        long long B, M;
        scanf("%lld%lld",&B,&M);
        printf("Case #%d: ",cas);
        solve(B, M);
    }
    return 0;
}
