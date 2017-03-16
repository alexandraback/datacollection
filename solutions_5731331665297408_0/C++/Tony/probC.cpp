
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#define MAXN 50

using namespace std;

int N, M;
string zip[MAXN];
bool adj[MAXN][MAXN];

bool check(const vector <int> &ord) {
    vector <int> v;
    v.push_back(ord[0]);
    for (int j = 1; j < N; j++) {
        int i = ord[j];
        while (v.size() > 0 && !adj[v.back()][i])
            v.pop_back();
        if (v.size() == 0)
            return false;
        v.push_back(i);
    }
    return true;
}

string calc() {
    if (N == 1)
        return zip[0];

    vector <int> ord(N);
    for (int i = 0; i < N; i++)
        ord[i] = i;

    string best_zips = "";
    do {
        if (check(ord)) {
            string cur_zips = "";
            for (int i : ord)
                cur_zips += zip[i];
            if (best_zips.size() == 0 || best_zips > cur_zips)
                best_zips = cur_zips;
        }
    } while (next_permutation(ord.begin(), ord.end()));

    return best_zips;
}

void solve() {
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> zip[i];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            adj[i][j] = false;
    for (int k = 0; k < M; k++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u][v] = adj[v][u] = true;
    }

    string zips = calc();
    cout << zips << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }
}

