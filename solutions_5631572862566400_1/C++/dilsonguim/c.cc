#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

pair<int, int> dfs(vector<int>& chain, vector<int>& p, vector<bool>& vis, int u){
    vis[u] = true;
    pair<int, int> r(1, chain[u]);
    if(not vis[p[u]]){
        auto t = dfs(chain, p, vis, p[u]);
        r.first += t.first;
        r.second += t.second;
    }
    return r;
}

int main(){
    int T;
    cin >> T;
    for(int tc = 1; tc <= T; tc++){
        int n;
        cin >> n;
        vector<int> p(n);
        vector<int> indeg(n);
        for(auto& pi : p){
            cin >> pi;
            pi--;
            indeg[pi]++;
        }

        vector<int> chain(n);
        queue<int> q;
        for(int i = 0; i < n; i++) if(not indeg[i]) q.push(i);
        while(not q.empty()){
            int u = q.front();
            q.pop();

            chain[p[u]] = max(chain[p[u]], chain[u] + 1);

            if(not --indeg[p[u]]) q.push(p[u]);
        }

        int sol = 0;
        int sum = 0;

        vector<bool> vis(n);
        for(int i = 0; i < n; i++){
            if(indeg[i] and not vis[i]){
                auto r = dfs(chain, p, vis, i);
                if(r.first > 2){
                    sol = max(sol, r.first);
                }else{
                    sum += r.first + r.second;
                }
            }
        }

        sol = max(sol, sum);

        cout << "Case #" << tc << ": " << sol << endl;
        
    }
}
