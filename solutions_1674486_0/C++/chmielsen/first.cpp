#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

const int MAXN = 1001;


bool visited[MAXN];

void clear() {
    for(int i = 0; i < MAXN; i++)
        visited[i] = false;
}

// reversed
vector<int> neigh[MAXN];
vector<int> starters;
//set<int> paths; //DFS

bool DFS(int start) {
    //printf("DFS od %d\n", start);
    if(visited[start])
        return true;
    visited[start] = true;
    if(neigh[start].size() == 0)
        return false;
    for(int i = 0; i < neigh[start].size(); i++) {
        if(DFS(neigh[start][i]))
            return true;
    }
    return false;
}

int main() {
    int tests;
    scanf("%d", &tests);
    for(int t = 1; t <= tests; t++) {
        int n;
        scanf("%d", &n);
        for(int c = 1; c <= n; c++) {
            int inh;
            scanf("%d", &inh);
            for(int i = 1; i <= inh; i++) {
                int ancestor;
                scanf("%d", &ancestor);
                neigh[ancestor].push_back(c);
            }
            if(inh == 0) 
                starters.push_back(c);
        }
        bool res;
        for(int i = 0; i < starters.size(); i++) {
            res = DFS(starters[i]);
            clear();
            if(res == true)
                break;
        }
        starters.clear();
        for(int i = 0; i< MAXN; i++)
            neigh[i].clear();
        printf("Case #%d: ", t);
        if(res)
            printf("Yes\n");
        else printf("No\n");

    }
}
