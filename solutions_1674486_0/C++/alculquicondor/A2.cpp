#include<iostream>
#include<vector>

using namespace std;

int n,M[1001][1001];
vector<int> adj[1001];

int DP(int ini,int fin) {
    int &ans = M[ini][fin];
    if(ans>=0)
        return ans;
    if(ini==fin)
        return ans=1;
    ans=0;
    for(int x:adj[ini])
        ans += DP(x,fin);
    return ans;
}

int main() {
    int T;
    cin>>T;
    for(int caso=1;caso<=T;caso++) {
        cout<<"Case #"<<caso<<": ";
        cin>>n;
        for(int i=0;i<n;i++) {
            adj[i].clear();
            for(int j=0;j<n;j++)
                M[i][j]=-1;
        }
        for(int i=0,t;i<n;i++) {
            cin>>t;
            int tt;
            while(t--) {
                cin>>tt;
                tt--;
                adj[i].push_back(tt);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++) {
                ans = max(ans,DP(i,j));
         //       cout<<i+1<<" "<<j+1<<": "<<DP(i,j)<<"\n";
            }
        if(ans>=2)
            cout<<"Yes";
        else
            cout<<"No";
        cout<<"\n";
    }
}
