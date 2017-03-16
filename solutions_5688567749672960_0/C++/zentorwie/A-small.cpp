#include <bits/stdc++.h>

using namespace std;

bool vis[1000010];
int N;
int dist[1000010];

int cnt(int s) {
    int ans = 0;
    while (s) {
        ans++;
        s /= 10;
    }
}

int rev(int s) {
    int ans = 0;
    while (s) {
        ans = ans * 10 + s % 10;
        s /= 10;

    }
    return ans;
}

int bfs() {
    memset(vis, 0, sizeof(vis));
    queue<int> q;
    vis[1] = 1;
    dist[1] = 1;
    q.push(1);
    int p;
    while (!q.empty()) {
        p = q.front(); q.pop();
        if (p == N) return dist[p];
        if (!vis[p+1] && p+1 <= N) {
            dist[p+1] = dist[p] + 1;
            vis[p+1] = 1;
            q.push(p+1);
        }

        int x = rev(p);
        
        if (!vis[x] && x <= N) {
            vis[x] = 1;
            dist[x] = dist[p] + 1;
            q.push(x);
        }
    }
    return -1;
}

    

int main() {
    int T;
    scanf("%d", &T);
    for (int kase = 1; kase <= T; kase++) {
        scanf("%d", &N);
        printf("Case #%d: %d\n", kase, bfs());
    }

    
    return 0;
}
