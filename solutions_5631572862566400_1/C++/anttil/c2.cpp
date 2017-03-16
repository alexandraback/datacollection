#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t;
int n;
int f[3333];
int z[3333];
vector<pair<int,int>> u[3333];

int laske1(int x) {
    int c = 1;
    int k = x;
    while (f[k] != x) {
        k = f[k];
        c++;
        if (c > n) return 0;
    }
    return c;
}

void laske2(int x) {
    if (z[x]) return;
    int c = 1;
    int k = x;
    while (f[k] != x) {
        if (z[f[k]]) {
            u[z[f[k]]].push_back({c,k});
            return;
        }
        k = f[k];
        c++;
        if (c > n) return;
    }
}

int tutki(int x) {
    sort(u[x].rbegin(), u[x].rend());
    int r[3333] = {0};
    int b[3333] = {0};
    int s = 2;
    int c = 0;
    for (int i = 0; i < u[x].size(); i++) {
        if (r[u[x][i].second]) continue;
        if (b[f[u[x][i].second]]) continue;
        r[u[x][i].second] = 1;
        b[f[u[x][i].second]] = 1;
        s += u[x][i].first;
        c++;
        if (c == 2) break;
    }
    return s;
}

void solve(int x) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> f[i];
    int p = 0;
    for (int i = 1; i <= n; i++) p = max(p,laske1(i));
    for (int i = 1; i <= n; i++) {
        z[i] = 0;
        u[i].clear();
    }
    int c = 0;
    for (int i = 1; i <= n; i++) {
        if (f[i] > i && f[f[i]] == i) {
            c++;
            z[i] = c;
            z[f[i]] = c;
        }
    }
    for (int i = 1; i <= n; i++) laske2(i);
    int w = 0;
    for (int i = 1; i <= n; i++) {
        if (f[i] > i && f[f[i]] == i) {
            w += tutki(z[i]);
        }
    }
    p = max(p,w);
    cout << "Case #" << x << ": " << p << "\n";
}

int main() {
    cin >> t;
    for (int i = 1; i <= t; i++) solve(i);
}
