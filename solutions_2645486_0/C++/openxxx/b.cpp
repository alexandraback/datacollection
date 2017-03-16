#include<cstdio>
#include<cmath>
#include<vector>
#include<cstring>
#include<map>
#include<algorithm>
#include<iostream>
using namespace std;

int T,E,R,N;
int v[20];
int dp[20][20];

int main()
{
    //freopen("B-small-attempt0.in","r",stdin);
    //freopen("B-small-attempt0.out","w",stdout);
    cin>>T;
    for(int ca=1;ca<=T;ca++)
    {
        cin>>E>>R>>N;
        for(int i=1;i<=N;i++) cin>>v[i];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<=E;j++)
            {
                for(int k=0;k<=j;k++)
                {
                    int tmp=min(E,j-k+R);
                    dp[i+1][tmp]=max(dp[i+1][tmp],dp[i][j]+v[i+1]*k);
                }
            }
        }
        int ans=0;
        for(int i=0;i<=E;i++) ans=max(ans,dp[N][i]);
        cout<<"Case #"<<ca<<": "<<ans<<endl;
    }
    return 0;
}







































