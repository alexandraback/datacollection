#include <bits/stdc++.h>
using namespace std;

int T;

bool v[1005] = {0};
int d[1005] = {0};
int p[1005] = {0};
vector<int> adj[1005];
vector<int> mid;
int depth(int x, int b){
    //cout << "call " << x << " " << b << endl;
    int m = 1;
    for(int i = 0; i<adj[x].size(); i++){
        if (adj[x][i] == b) continue;
        int k = depth(adj[x][i], b) + 1;
        m = max(m, k);
    }
    d[x] = m;
    v[x] = true;
    return m;
}





int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &T);



    for (int cas = 1; cas<=T; cas++){
        printf("Case #%d: ", cas);


        for(int i = 0; i<1005; i++){
            adj[i].clear();
        }
        mid.clear();


        memset(d, -1, sizeof d);
        memset(v, 0, sizeof v);
        int n;
        scanf("%d", &n);


        for(int i = 1; i<=n; i++){
            scanf("%d", &p[i]);
            adj[p[i]].push_back(i);
        }


        for(int i = 1; i<=n; i++){
            if (i == p[p[i]]) mid.push_back(i);
        }


        //case 1: 1 big cycle
        int best = 0;
        if (mid.empty()){
            for(int i = 1; i<=n; i++){
                int cur = i;
                if (d[cur] != -1) continue;
                d[cur] = 0;
                memset(v, 0, sizeof v);
                v[cur] = true;
                while (d[p[cur]] == -1){
                    d[p[cur]] = d[cur] + 1;
                    cur = p[cur];
                    v[cur] = true;
                }

                if (!v[p[cur]]) continue;
                best = max(best, d[cur] - d[p[cur]] + 1);
            }



        }
        // case 2: many midpoints
        else{
            for(int i = 0; i<mid.size(); i++){
                int x = depth(mid[i], p[mid[i]]);
                best = best + x;

            }
            for(int i = 1; i<=n; i++){
                int cur = i;
                if (d[cur] != -1) continue;
                d[cur] = 0;
                memset(v, 0, sizeof v);
                v[cur] = true;
                while (d[p[cur]] == -1){
                    d[p[cur]] = d[cur] + 1;
                    cur = p[cur];
                    v[cur] = true;
                }

                if (!v[p[cur]]) continue;
                best = max(best, d[cur] - d[p[cur]] + 1);
            }

        }

        printf("%d\n", best);








    }


}
