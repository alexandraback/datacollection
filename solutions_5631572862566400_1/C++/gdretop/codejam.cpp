#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
int height[3000];
int check[1001],in[1001],flag[1001],belong[1001];
vector<int> edge[1001];
vector<int> Dedge[1001];
int mp[1001][1001];
int dfs(int u){
    if(flag[u]) return 0;
    int ans = 1;
    flag[u] = 1;
    for(int i = 0;i < edge[u].size();i++)
        ans += dfs(edge[u][i]);
    return ans;
}
int n;
int dfs2(int u){
    int ans = 0;
    for(int i = 0;i < Dedge[u].size(); i++)
        ans = max(ans,dfs2(Dedge[u][i]));
    return ans+1;
}
int get(int u,int x){
    int ans = 0;
    for(int i = 1;i <= n; i++){
        if(i != x && mp[i][u] == 1){
            ans = max(ans,dfs2(i));
        }
    }
    return ans;
}
int main(){
    int t;
    freopen("C-large.in","r",stdin);
    freopen("ans.out","w",stdout);
    scanf("%d",&t);
    for(int tt = 1; tt <= t; tt++){
        cin>>n;
        memset(in,0,sizeof(in));
        for(int i = 1;i <= n; i++)
            edge[i].clear(),Dedge[i].clear();
        memset(mp,-1,sizeof(mp));
        for(int i = 1;i <= n; i++){
            int u;
            cin>>u;
            in[u]++;
            edge[i].push_back(u);
            mp[i][u] = 1;
            Dedge[u].push_back(i);
        }
        queue<int> que;
        for(int i = 1;i <= n; i++){
            if(in[i] == 0) que.push(i);
        }
        int ans = 0;
        memset(check,0,sizeof(check));
        while(que.size() > 0){
            int u = que.front();
            que.pop();
            check[u] = 1;
            for(int i = 0;i < edge[u].size();i++){
                int v = edge[u][i];
                in[v]--;
                if(in[v] == 0) que.push(v);
            }
        }
        for(int i = 1;i <= n; i++){
            if(check[i] == 0){
                memset(flag,0,sizeof(flag));
                ans = max(ans,dfs(i));
            }
        }
        int res = 0;
        for(int i = 1;i <= n; i++){
            for(int j = i+1;j <= n; j++){
                if(mp[i][j] == 1 && mp[j][i] == 1){
                    res += get(i,j) + get(j,i) + 2;
                }
            }
        }
        ans = max(ans,res);
        printf("Case #%d: %d\n",tt,ans);
    }
    return 0;
}


























