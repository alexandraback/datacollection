#include <iostream>
#include <cstring>
using namespace std;

int head[2000];
int next[100000];
int q[100000];
bool vis[2000];
int tot;

void add_edge(int a, int b) {
    tot++;
    next[tot] = head[a];
    head[a] = tot;
    q[tot] = b;
}

bool dfs(int id) {
    if (vis[id]) return true;
    vis[id] = true;
    int h = head[id];
    while (h) {
        if (dfs(q[h])) return true;
        h = next[h];
    }
    return false;
}

int main() {
freopen("A-large.in", "r", stdin);
freopen("A-large.out", "w", stdout);
    int T;
    cin >> T;
    int N;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": ";
        cin >> N;
        tot = 0;
        memset(head, 0, sizeof(head));
        for (int i = 1; i <= N; i++) {
            int M;
            cin >> M;
            for (int j = 0; j < M; j++) {
                int r;
                cin >> r;
                add_edge(i, r);
            }
        }
        
        bool ok = false;
        for (int i = 1; i <= N; i++) {
            memset(vis, false, sizeof(vis));
            if (dfs(i)) {
                ok = true;
                break;
            }
        }
        cout << (ok ? "Yes" : "No") << endl;
    }
    return 0;
}

            
        