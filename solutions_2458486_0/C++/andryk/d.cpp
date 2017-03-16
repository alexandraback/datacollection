#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;

vector< vector<int> > g;
vector<int> start_keys;
vector<int> start_chest;
vector<int> types;
vector< vector<int> > keys;
vector< vector<int> > by_types;

vector<int> topo;
vector<int> marked;
bool cycle;
void dfs(int v) {
    //cout << v << endl;
    marked[v] = 1;
    for(int i = 0; i < g[v].size(); i++) {
        if(marked[g[v][i]] == 1) {
            //cycle = true;
            //return;
        } else
        if(marked[g[v][i]] == 0) {
            dfs(g[v][i]);
        }
    }
    marked[v] = 2;

    topo.push_back(v);
}

bool cmp(int v1, int v2) {
    return g[v1].size() < g[v2].size() || g[v1].size() == g[v2].size() && v1 < v2;
}

void run(int t) {
    int k,n;
    cin>>k>>n;
    g.clear();
    g.resize(n+1);
    start_keys.clear();
    start_keys.resize(k);
    start_chest.clear();
    types.clear();
    types.resize(n+1);
    keys.clear();
    keys.resize(n+1);
    by_types.clear();
    by_types.resize(201);
    topo.clear();
    marked.clear();
    marked.resize(n+1, 0);
    cycle = false;
    for(int i = 0 ; i < k ; i++) {cin>>start_keys[i];}

    for(int i = 1; i <= n; i++) {
        cin>>types[i];
        int q;
        cin>>q;
        keys[i].resize(q);
        for(int j =0; j < q; j++) {cin>>keys[i][j];};
    }

    for(int i = 1; i <= n; i++) {
        by_types[types[i]].push_back(i);
    }



    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < keys[i].size(); j++) {
            int key = keys[i][j];
            for(int z = 0; z < by_types[key].size(); z++) {
                int e = by_types[key][z];
                if(e != i)
                    g[i].push_back(e);
            }
        }

        sort(g[i].rbegin(), g[i].rend());
    }

/*
    for(int i = 1; i <= n; i++) {
        cout << i << ": ";
        for(int j = 0; j < g[i].size(); j++) {
            cout << g[i][j] << " ";
        }
        cout << endl;
    }
    */

    for(int i = 0; i < start_keys.size(); i++) {
        int key = start_keys[i];
        if(key <= n) {
            for(int j = 0; j < by_types[key].size(); j++) {
                start_chest.push_back(by_types[key][j]);

            }
        }
    }
    sort(start_chest.rbegin(), start_chest.rend(), cmp);



    for(int i = 0; i < start_chest.size(); i++) {
        //cout << start_chest[i];
        if(!marked[start_chest[i]]) {
           dfs(start_chest[i]);
        }
    }


    reverse(topo.begin(), topo.end());



    cout << "Case #"<<t<<": ";
    if(topo.size() == n && !cycle) {
        for(int i = 0; i < topo.size(); i++) {
            cout << topo[i] << " ";
        }

    } else {
        cout << "IMPOSSIBLE";
    }
    cout << endl;








}






int main() {




    int t;
    cin>>t;
    for(int i = 0; i < t ; i++) {
        //cout <<t << endl;
        run(i+1);
    }


}
