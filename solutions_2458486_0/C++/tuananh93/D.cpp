#include <cstdlib>
#include <cstdio>
#include <vector>
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

vector <int> key[1000];
int cnt[1000], t[1000], trace[(1 << 20) + 20];
queue <int> Q;
int n, k;

void findPath(int u) {
    if (u == 0) return;
    findPath(u - (1 << (trace[u] - 1)) );
    printf("%d ", trace[u]);
}

int bit (int x, int i) {
    return (x & (1 << i)) > 0;
}

int BFS() {
    memset(trace, 0, sizeof(trace));
    trace[0] = -1;
    while (!Q.empty()) Q.pop();
    Q.push(0);

    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();

        memset(cnt, 0, sizeof(cnt));

        for (int i = 0; i < key[0].size(); i++)
            cnt[key[0][i]] ++;

        for (int i = 1; i <= n; i++)
            if (bit(u, i - 1)) {
                cnt[t[i]] --;
                for (int j = 0; j < key[i].size(); j++)
                    cnt[key[i][j]] ++;
            }

        for (int i = 1; i <= n; i++)
            if (!bit (u, i - 1) && cnt[t[i]]) {
                int v = u | (1 << (i - 1));
                if (trace[v] == 0) {
                    trace[v] = i;
                    Q.push(v);
                }
            }
    }

    return trace[(1 << n) - 1] != 0;
}

int main() {
    freopen("D-small-attempt0.in", "r", stdin);
    freopen("a.out", "w", stdout);

    int ntest;
    cin >> ntest;

    for (int test = 1; test <= ntest; test++) {
        cout << "Case #" << test << ": ";
        cin >> k >> n;
        for (int i = 0; i <= n; i++) key[i].clear();

        for (int i = 1; i <= k; i++) {
            int u;
            cin >> u;
            key[0].push_back(u);
        }

        for (int i = 1; i <= n; i++) {
            cin >> t[i];
            int cnt;
            cin >> cnt;


            for (int j = 1; j <= cnt; j++) {
                int u;
                cin >> u;
                key[i].push_back(u);
            }
        }

        if (BFS()) findPath((1 << n) - 1);
        else cout << "IMPOSSIBLE";
        cout << endl;
    }
}
