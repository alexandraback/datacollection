#include<bits/stdc++.h>
using namespace std;
int i, j, k, l, x, y, z, n, m, ans, t;
int bff[12];
vector < int > cnt[12];
int vis[12];

void dfs(int node, int lvl, int prev_node)
{
    if(vis[node]){

        if(node != i && prev_node != bff[node]) return;

        //cout << i << ' '  << node << ' ' << lvl << endl;

        if(node == i && prev_node == bff[node]){
            bool flag = false;

            //cout << cnt[prev_node].size() << endl;

            for(int j = 0; j < cnt[prev_node].size(); j++){
                if(!vis[cnt[prev_node][j]])flag = true;
            }

            if(flag) ans = max(ans, lvl);
            else ans = max(ans, lvl - 1);
            return;

        }
        if(node == i){
            ans = max(ans, lvl - 1);
            return;
        }
        else{
            bool flag = false;

            //cout << cnt[prev_node].size() << endl;

            for(int j = 0; j < cnt[prev_node].size(); j++){
                if(!vis[cnt[prev_node][j]])flag = true;
            }

            if(flag) ans = max(ans, lvl);
            else ans = max(ans, lvl - 1);
            return;
        }

    }

    vis[node] = 1;

    dfs(bff[node], lvl + 1, node);

}
int main()
{

    freopen("C-small-attempt0.txt", "r", stdin);
    freopen("output_c_small.txt", "w", stdout);

    cin >> t;

    int cs = 1;

    while(t--){
        ans = 0;
        memset(bff, 0, sizeof(bff));
        //memset(cnt, 0, sizeof(cnt));
        for(i = 0; i < 12; i++)cnt[i].clear();

        cin >> n;

        for(i = 1; i <= n; i++){
            cin >> bff[i];
            cnt[bff[i]].push_back(i);
        }

        for(i = 1; i <= n; i++){
            memset(vis, 0, sizeof(vis));
            dfs(i, 1, i);
        }

        printf("Case #%d: %d\n", cs++, ans);

    }



    return 0;
}
