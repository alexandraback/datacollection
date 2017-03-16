#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define For(i,x) for (int i=0; i<(int)(x); i++)

typedef vector<int> vi;

bool calc(vector<vi>& adj, vi& refs) {
    const int n = adj.size();

    For(i, refs.size()) {
        if (refs[i] == 0) {
            vi used(n+1);
            queue<int> q;
            q.push(i);

            while (!q.empty()) {
                int node = q.front(); q.pop();

                if (used[node]++) return true;

                For(j, adj[node].size()) {
                    //printf("%d -> %d\n", node, adj[node][j]);
                    q.push(adj[node][j]);
                }
            }
        }
    }
    return false;

}

int main() {
    int ncases;
    scanf("%d", &ncases);

    For(cc, ncases) {
        int n;
        scanf("%d", &n);

        vector<vi> adj(n+1);
        vi refs(n+1);
        For(i, n) {
            int m;
            scanf("%d", &m);
            For(j, m) {
                int x;
                scanf("%d", &x);
                adj[i+1].push_back(x);
                ++refs[x];
            }
        }

        printf("Case #%d: %s\n", cc+1, calc(adj, refs) ? "Yes" : "No");
    }
}
