#include <cstdio>
#include <vector>

using namespace std;

int rdfs(vector<vector<int>> &, int, int);

int main() {
    int t;
    scanf("%d", &t);
    for (int c = 1; c <= t; c++) {
        int n;
        scanf("%d", &n);
        vector<int> adj(n);
        vector<vector<int>> radj(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &adj[i]);
            adj[i]--;
            radj[adj[i]].push_back(i);
        }
        int resultfromtwocycles = 0;
        for (int i = 0; i < n; i++) {
            if (adj[i] > i && adj[adj[i]] == i) {
                resultfromtwocycles += rdfs(radj, i, adj[i]);
                resultfromtwocycles += rdfs(radj, adj[i], i);
            }
        }
        int resultfromcycles = 0;
        vector<int> seen(n, -1);
        int currtime = 0;
        for (int i = 0; i < n; i++) {
            if (seen[i] != -1) continue;
            int currnode = i;
            int prevnode = i;
            int basetime = currtime;
            while (seen[currnode] == -1) {
                seen[currnode] = currtime++;
                prevnode = currnode;
                currnode = adj[currnode];
            }
            if (seen[currnode] >= basetime) {
                resultfromcycles = max(resultfromcycles, seen[prevnode] - seen[currnode] + 1);
            }
        }
        printf("Case #%d: %d\n", c, max(resultfromtwocycles, resultfromcycles));
    }
    return 0;
}

int rdfs(vector<vector<int>> &radj, int currnode, int avoid) {
    if (radj[currnode].size() == 0) {
        return 1;
    }
    int deepest = 0;
    for (int next : radj[currnode]) {
        if (next == avoid) continue;
        deepest = max(deepest, rdfs(radj, next, avoid));
    }
    return 1 + deepest;
}