#include <vector>
#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

bool bfs(vector<vector<int> > &edges, vector<bool> &vis, int n) {
    if(vis[n]) {
        return true;

    }
    else {
        vis[n] = true;
        for(int i = 0; i < edges[n].size(); i++) {
            if(bfs(edges, vis, edges[n][i]))
                return true;
        }
        return false;
    }
}

int main() {
    int T;
    cin >> T;

    for(int TT = 1; TT <= T; TT++) {
        int N;
        cin >> N;

        vector<vector<int> > edges(N, vector<int>());
        for(int i = 0; i < N; i++) {
           int M;
           cin >> M;

           for(int j = 0; j < M; j++) {
               int V;
               cin >> V;

               edges[V-1].push_back(i);
           }
        }

        bool exists = false;
        for(int i = 0; i < N; i++) {
            vector<bool> vis(N, 0);
            if(bfs(edges, vis, i)) {
                exists = true;
                break;
            }
        }

        if(exists) {
            printf("Case #%d: Yes\n", TT);
        } else {
            printf("Case #%d: No\n", TT);
        }
    }

    return 0;
}
