#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int n, m, l;
string s1, s2;
map<string, int> M1, M2;
int matched[N];
bool vis[N], isMatched[N];
vector<int> V[N];

bool DFS(int w) {
    vis[w] = true;

    for (int i = 0; i < V[w].size(); i++) {
        int u = V[w][i];
        if (matched[u] == 0 || (vis[matched[u]] == false && DFS(matched[u]))) {
            matched[u] = w;
            isMatched[w] = true;
            return true;
        }
    }

    return false;
}

int maxMatching() {
    bool path = true;
    int ret = 0;
    while (path) {
        path = false;
        for (int i = 1; i <= n; i++) {
            vis[i] = false;
        }
        for (int i = 1; i <= n; i++) {
            if (!vis[i] && !isMatched[i] && DFS(i)) {
                path = true;
                ret++;
            }
        }
    }
    return ret;
}

void test() {
    cin >> l;
    n = m = 0;
    M1.clear();
    M2.clear();
    for (int i = 1; i <= l; i++) {
        cin >> s1 >> s2;
        int a, b;
        if (M1.count(s1) == false) {
            M1[s1] = ++n;
        }
        a = M1[s1];
        if (M2.count(s2) == false) {
            M2[s2] = ++m;
        }
        b = M2[s2];
        V[a].push_back(b);
    }
    cout << l - (n + m - maxMatching()) << "\n";;

    for (int i = 1; i <= n; i++) {
        V[i].clear();
        isMatched[i] = false;
    }
    for (int i = 1; i <= m; i++) {
        matched[i] = 0;
    }
}

int main() {

    ios_base::sync_with_stdio(0);
    int tests;
    cin >> tests;
    for (int t = 1; t <= tests; t++) {
        cout << "Case #" << t << ": ";
        test();
    }

    return 0;
}