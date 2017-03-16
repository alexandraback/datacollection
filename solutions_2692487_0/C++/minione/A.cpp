#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int T;
int A,n;
int a[200];
int f[200][200];
int g[200][200];

int Max(int x, int y)
{
    if (x>y) return x;
    else return y;
}

int main()
{
    freopen("A-small-attempt1.in","r",stdin);
    freopen("A-small-attempt1.out","w",stdout);
    cin>>T;
    for (int tt=1; tt<=T; ++tt)
    {
        cin>>A>>n;
        int ans=0;
        for (int i=0; i<200; ++i)
            for (int j=0; j<200; ++j)
            {
                f[i][j]=0;
                g[i][j]=false;
            }
        for (int i=1; i<=n; ++i) cin>>a[i];
        sort(a+1,a+n+1);
        f[0][0]=A;
        g[0][0]=true;
        for (int i=1; i<=n; ++i) { f[0][i]=f[0][i-1]*2-1; g[0][i]=true; }
        for (int i=1; i<=n; ++i)
        {
            for (int j=0; j<n; ++j)
                if (g[i-1][j])
                {
               //     cout<<i-1<<"   "<<j<<endl;
                 //   cout<<f[i-1][j]<<endl;
                    f[i][j+1]=f[i-1][j];
                    g[i][j+1]=true;
                    if (f[i-1][j]>a[i])
                    {
                        f[i][j]=Max(f[i][j],f[i-1][j]+a[i]);
                        g[i][j]=true;
                   //     cout<<"~~"<<i<<" "<<j<<endl;
                    }
                }
            int c=0;
            for (int j=0; j<n; ++j)
                if (g[i][c]) break;
            for (int j=c; j<n; ++j)
                f[i][j+1]=Max(f[i][j+1],f[i][j]*2-1);
        }
        for (ans=0; ans<=n; ++ans)
            if (f[n][ans]) break;
        cout<<"Case #"<<tt<<": "<<ans<<endl;
    }
    return 0;
}
