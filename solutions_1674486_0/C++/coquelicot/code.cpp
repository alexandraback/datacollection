#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>

std::vector<int> edge[1010];

bool test(int ob, int n){

    std::queue<int> que;
    que.push(ob);

    static int vis[1010];
    memset(vis, 0, (n + 1) * sizeof(int));
    vis[ob] = 1;

    while(!que.empty()){
        int now = que.front(); que.pop();
        for(int i = 0; i < edge[now].size(); i++){
            if(vis[edge[now][i]]) return false;
            else{
                vis[edge[now][i]] = 1;
                que.push(edge[now][i]);
            }
        }
    }

    return true;

}

int main(){

    int t;
    scanf("%d" ,&t);

    for(int T = 1; T <= t; T++){

        int n;
        scanf("%d" ,&n);

        for(int i = 1; i <= n; i++){

            int m, g;
            scanf("%d" ,&m);

            while(m--){
                scanf("%d" ,&g);
                edge[i].push_back(g);
            }

        }

        bool flag = true;
        for(int i = 1; i <= n && flag; i++){
            flag = test(i, n);
        }

        printf("Case #%d: %s\n" ,T ,flag? "No": "Yes");

        for(int i = 1; i <= n; i++){
            edge[i] = std::vector<int>();
        }

    }

}
