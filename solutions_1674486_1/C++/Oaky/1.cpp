#include <cstdio>
#include <algorithm>
#include <vector>

#define N 5000

using namespace std;

vector<int> G[N];
bool visit[N];

bool dfs(int node){
    if(visit[node]) return true;
    visit[node] = true;
    for(int i = 0; i < G[node].size(); ++i){
        if(dfs(G[node][i])) return true;
    }
    return false;
}

bool newprob(){
    int n, v, val;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        scanf("%d", &v);
        G[i].clear();
        for(int j = 1; j <= v; ++j){
            scanf("%d", &val);
            G[i].push_back(val);
        }
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j) visit[j] = false;
        if(dfs(i)) return true;
    }
    return false;
}

int main(){
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; ++i){
        printf("Case #%d: %s\n", i, newprob() ? "Yes" : "No");
    }
    return 0;
}
