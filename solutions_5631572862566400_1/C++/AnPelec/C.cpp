#include <bits/stdc++.h>

#define MAXN 1010

#define cin fin
#define cout fout

using namespace std;

ifstream fin("C-large.in");
ofstream fout("C-large.out");

typedef vector < int > vi;

int T, N;

int F[MAXN];
int sub[MAXN];

bool vis[MAXN];
bool isActive[MAXN];

vector < vi > adj;
stack < int > active;

int fullCircle;

void dfs(int x) {
    if (isActive[x]) {
        int tempCircle = 1;
        isActive[x] = false;
        while (!active.empty() && active.top() != x) {isActive[active.top()] = false; active.pop(); tempCircle ++;}
        if (!active.empty()) active.pop();
        fullCircle = max(fullCircle, tempCircle);
        return;
    }
    isActive[x] = true;
    active.push(x);
    dfs(F[x]);
    if (isActive[x] && !active.empty() && active.top() == x) active.pop();
    isActive[x] = false;
}

void traverse(int now) {
    if (vis[now]) return;
    vis[now] = true;
    int maxChild = 0;
    for (int i=0; i<adj[now].size(); i++) if (!vis[adj[now][i]]) {
        traverse(adj[now][i]);
        maxChild = max(maxChild, sub[adj[now][i]]);
    }
    sub[now] = maxChild+1;
}

int main()
{
    cin >> T;

    for (int t=1; t<=T; t++) {
        fullCircle = 1;
        adj.clear();
        cin >> N;
        adj.assign(N+1, vi());
        for (int i=1; i<=N; i++) {
            cin >> F[i];
            adj[F[i]].push_back(i);
        }

        for (int i=1; i<=N; i++)
            dfs(i);

        int yoloCircle = 0;

        for (int i=1; i<=N; i++) {
            vis[i] = false;
            sub[i] = 0;
        }

        for (int i=1; i<=N; i++) if (F[F[i]] == i && i < F[i])
            traverse(i);

        for (int i=1; i<=N; i++) {  /// fix i as a root
            traverse(i);
            int max1=0, max2=-MAXN*MAXN;
            for (int j=0; j<adj[i].size(); j++) {
                if (F[i] != adj[i][j]) max1 = max(max1, sub[adj[i][j]]);
                else max2 = max(max2, sub[adj[i][j]]);
            }
            if (F[F[i]] == i && i < F[i]) yoloCircle += max1+max2+1;
        }

        cout << "Case #" << t << ": " << max(fullCircle, yoloCircle) << endl;
    }


    return 0;
}
