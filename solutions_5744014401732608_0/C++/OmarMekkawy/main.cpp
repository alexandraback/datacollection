#include <bits/stdc++.h>

using namespace std;
int n,m;
vector<vector<int> > adjlist(7);
int dp[7];
int cntpaths(int node)
{
    if(node==n)return 1;
    if(dp[node]!=-1)return dp[node];
    dp[node]=0;
    for(int i=0;i<adjlist[node].size();i++){
        dp[node]+=cntpaths(adjlist[node][i]);
    }
    return dp[node];

}
bool backtrack(int node,int indexOFList)
{
    if(node==n){
        memset(dp,-1,sizeof dp);
        if(m==cntpaths(1))return true;
        return false;
    }
    if(indexOFList>n)return false;
    for(int i=max(indexOFList,node+1);i<=n;i++){
        adjlist[node].push_back(i);
        if( backtrack(node,i+1)|| backtrack(node+1,0) )
            return true;
        adjlist[node].pop_back();
    }
    return false;
}
int ans[7][7];
int main()
{
    freopen("ii.in","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    int cases=0;
    while(t--){
        cases++;
        cin>>n>>m;
        adjlist.clear();
        memset(dp,-1,sizeof dp);
        adjlist.resize(n+1);
        cout<<"Case #"<<cases<<": ";
        if(backtrack(1,0)){
            cout<<"POSSIBLE\n";
            memset(ans,0,sizeof ans);
            for(int i=1;i<=n;i++)
                for(int j=0;j<adjlist[i].size();j++){
                    ans[i][adjlist[i][j]]=1;
                }

            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                {
                    cout<<ans[i][j];
                    if(j==n)cout<<"\n";
                }

        }
        else
            cout<<"IMPOSSIBLE\n";

    }
    return 0;
}
