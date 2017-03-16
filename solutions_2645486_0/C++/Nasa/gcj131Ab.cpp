#include <iostream>
using namespace std;

int v[10001],E,R,N;
int dp[10001][6];

int main(){
    int u,t,i,j,k;
    cin>>t;
    for (u=0; u<t; u++){
        cin>>E>>R>>N;
        cout<<"Case #"<<(u+1)<<": ";
        for (i=0; i<N; i++) cin>>v[i];
        memset(dp,0,sizeof(dp));
        for (i=1; i<=N; i++)
            for (j=0; j<=E; j++)
                for (k=0; j+k<=E; k++)
                    dp[i][min(E,j+R)]=max(dp[i][min(E,j+R)],dp[i-1][j+k]+v[i-1]*k);
        for (j=1; j<=E; j++) dp[N][0]=max(dp[N][0],dp[N][j]);
        cout<<dp[N][0]<<endl;
    }
    return 0;
}

