#include <bits\stdc++.h>
using namespace std;

bool DFS(bool G[][6], bool V[], int n, int cur) {
    for (int i = 0; i < n; i++) {
        if (i == cur)    continue;
        if (!G[i][cur])  continue;
        if (V[i])    return true;
        V[cur] = true;
        if (DFS(G, V, n, i))
            return true;
        V[cur] = false;
    }
    return false;
}

bool hasCycle(bool G[][6], int n) {
    bool V[6] = { false };

    V[0] = true;
    return DFS(G, V, n, 0);
}

int calculatePath(bool G[][6], int n) {
    int DP[6] = { 0 };
    int in[6] = { 0 };

    queue<int> Q;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (G[i][j])
                in[j]++;
    for (int i = 0; i < n; i++)
        if (in[i] == 0)
            Q.push(i);
    DP[0] = 1;
    while (!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        for (int i = 0; i < n; i++) {
            if (!G[cur][i])  continue;
            DP[i] += DP[cur];
            if (--in[i] == 0)
                Q.push(i);
        }
    }
    return DP[n - 1];
}

int main() {
    freopen("B-small-attempt1.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t, c = 1;
    scanf("%d", &t);
    while (t--) {
        int B, M;
        bool G[6][6] = { false };
        scanf("%d%d", &B, &M);
        printf("Case #%d:", c++);
        if (pow(2, (B - 2)) < M)
            puts(" IMPOSSIBLE");
        else {
            bool found = false;
            srand(time(0));
            for (int i = 0; i <= 100000000 && !found; i++) {
                int a, b;
                do {
                    a = rand() % B;
                } while (a == B - 1);
                do {
                    b = rand() % B;
                } while (b == a);
                G[a][b] = !G[a][b];
                if (!hasCycle(G, B) && M == calculatePath(G, B))
                    found = true;
                
            }
            if (found) {
                puts(" POSSIBLE");
                for (int i = 0; i < B; i++) {
                    for (int j = 0; j < B; j++) 
                        printf("%d", G[i][j]);
                    putchar('\n');
                }
            }
            else
                puts(" IMPOSSIBLE");
        }        
    }
    return 0;
}