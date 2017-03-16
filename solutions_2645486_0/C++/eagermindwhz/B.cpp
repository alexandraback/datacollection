#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
long long f[10000][10000],v[100000],e,r;
int n;
int main()
{
    freopen("B1.in","r",stdin);
    freopen("B1.txt","w",stdout);
    int T;
    cin>>T;
    for (int cas = 1; cas <= T; cas++){
        cin>>e>>r>>n;
        int i,j,k;
        for (i = 1; i <= n; i++) cin>>v[i];
        memset(f,-1,sizeof(f));
        //cout<<f[1][1]<<endl;
        f[0][e] = 0;
        for (i = 1; i <= n; i++)
            for (j = 0; j <= e; j++)
                for (k = 0;k <= j; k++)
                    f[i][min(e,j-k+r)] = max(f[i-1][j]+k*v[i],f[i][min(e,j-k+r)]);
        long long ans = 0;
        for (j = 0; j <= e; j++) ans = max(ans,f[n][j]);
        cout<<"Case #"<<cas<<": "<<ans<<endl;
    }
    return 0;
}
