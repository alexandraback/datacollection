#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int a[1005];
int vis[1005];
int n,ans;
vector<int> v;

void dfs(int x){
    if(vis[a[x]]){
        int sum = v.size();
        if(a[x] != v[0] && a[x] != v[sum-2])
            --sum;
        if(a[v[sum-1]] == v[sum-2]){
            for(int i = 1; i <= n; ++i){
                if(!vis[i] && a[i] == v[sum-1]){
                    ++sum;
                    vis[i] = 1;
                    break;
                }
            }
        }
        ans = max(ans,sum);
        return ;
    }
    vis[a[x]] = 1;
    v.push_back(a[x]);
    dfs(a[x]);
}

int main(){
    freopen("C-small-attempt1.in","r",stdin);
    freopen("out.txt","w",stdout);
    int T,t = 1;
    scanf("%d",&T);
    while(T--){
        ans = 0;
        scanf("%d",&n);
        for(int i = 1; i <= n; ++i)
            scanf("%d",&a[i]);
        for(int i = 1; i <= n; ++i){
            memset(vis,0,sizeof(vis));
            v.clear();
            v.push_back(i);
            vis[i] = 1;
            dfs(i);
        }
        printf("Case #%d: %d\n",t++,ans);
    }
    return 0;
}
