//    A
//   A A
//  AAAAA
// A     A

#include <cstdio>
#include <queue>
#include <vector>

#define PB push_back

const int MAX = 1010;

std::vector<int> G[MAX];
bool V[MAX];

bool diamond(int v) {
    bool found = false;
    std::queue<int> q;
    
    for (int i = 0; i < MAX; i++)
        V[i] = 0;
    q.push(v);
    V[v] = 1;
    
    while (!q.empty()) {
        v = q.front();
        q.pop();
        
        for (std::vector<int>::iterator it = G[v].begin(); it != G[v].end(); it++) {
            if (!V[(*it)]) {
                q.push((*it));
                V[(*it)] = 1;
            } else
                found = true;
        }
    }
    
    return found;
}

int main() {
    int t, n, a, m;
    bool found;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        found = 0;
        scanf("%d", &n);
        for (int j = 0; j < n; j++) {
            G[j].clear();
            V[j] = 0;
            scanf("%d", &m);
            for (int k = 0; k < m; k++) {
                scanf("%d", &a);
                G[j].PB(--a);
            }
        }
        
        for (int j = 0; j < n; j++) {
            if (diamond(j))
                found = 1;
        }
        
        printf("Case #%d: ", i+1);
        if (found)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}