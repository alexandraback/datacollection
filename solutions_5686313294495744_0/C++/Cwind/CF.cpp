#include <bits/stdc++.h>

using namespace std;

int T,cas=0;
int n;
int a[300][2];
map<string,int> M;
int dp[1<<16];
int DP(int s){
    if(dp[s]!=-1) return dp[s];
    if(s==((1<<n)-1)) return dp[s]=0;
    int &ans=dp[s];
    ans=0;
    for(int i=0;i<n;i++){
        if(s&(1<<i)) continue;
        int f1=0,f2=0;
        for(int j=0;j<n;j++){
            if(s&(1<<j)){
                if(a[j][0]==a[i][0]) f1=1;
                if(a[j][1]==a[i][1]) f2=1;
            }
        }
        ans=max(ans,DP(s|(1<<i))+(f1&f2));
    }
    return ans;
}
int main(){
    freopen("./in","r",stdin);
    freopen("./out","w",stdout);
    cin>>T;
    while(T--){
        memset(dp,-1,sizeof dp);
        cin>>n;
        printf("Case #%d: ",++cas);
        M.clear();
        string tmp;
        int sz=0;
        for(int i=0;i<n;i++){
            cin>>tmp;
            if(M.find(tmp)!=M.end()) a[i][0]=M[tmp];
            else a[i][0]=M[tmp]=sz++;
            cin>>tmp;
            if(M.find(tmp)!=M.end()) a[i][1]=M[tmp];
            else a[i][1]=M[tmp]=sz++;
        }
        printf("%d\n",DP(0));
    }
    return 0;
}