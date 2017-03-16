#include <iostream>

using namespace std;

int t;
int k, n;

int a[200];
int v[200];
int u[200];
int b[200][400];
int r[200];
bool o[200];
bool h = false;

bool hassu(int k) {
    if (a[v[k]] > 1) return false;
    for (int j = 0; j < u[k]; j++) if (b[k][j] == v[k]) return false;
    int x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        if (i == k || o[i]) continue;
        for (int j = 0; j < u[i]; j++) {
            if (v[i] == v[k] && b[i][j] == v[k]) x = 1;
            if (v[i] != v[k] && b[i][j] == v[k]) y = 1;
        }
    }
    return x == 1 && y == 0;
}

void haku(int k, int l) {
    if (l == n) {
        h = true;
        return;
    }
    if (hassu(k)) return;
    a[v[k]]--;
    o[k] = true;
    for (int i = 0; i < u[k]; i++) {
        a[b[k][i]]++;
    }
    for (int i = 0; i < n; i++) {
        if (o[i] || a[v[i]] == 0) continue;
        r[l] = i+1;
        haku(i, l+1);
        if (h) return;
    }
    a[v[k]]++;
    o[k] = false;
    for (int i = 0; i < u[k]; i++) {
        a[b[k][i]]--;
    }
}

int aa[200];
int vv[200];

bool huono() {
    for (int i = 0; i < 200; i++) aa[i] = a[i];
    for (int i = 0; i < 200; i++) vv[i] = 0;
    for (int i = 0; i < n; i++) {
        vv[v[i]]++;
        for (int j = 0; j < u[i]; j++) {
            aa[b[i][j]]++;
        }
    }
    for (int i = 0; i < 200; i++) {
        if (vv[i] > aa[i]) return true;
    }
    return false;
}

void laske(int m) {
    h = false;
    for (int i = 0; i < 200; i++) a[i] = 0;
    for (int i = 0; i < 200; i++) o[i] = false;
    cin >> k >> n;
    int d;
    for (int i = 0; i < k; i++) {
        cin >> d;
        a[d-1]++;
    }
    for (int i = 0; i < n; i++) {
        cin >> v[i] >> u[i];
        v[i]--;
        for (int j = 0; j < u[i]; j++) {
            cin >> d;
            b[i][j] = d-1;
        }
    }
    if (huono()) goto loppu;
    for (int i = 0; i < n; i++) {
        if (a[v[i]] == 0) continue;
        r[0] = i+1;
        haku(i, 1);
        if (h) break;
    }
    loppu:
    cout << "Case #" << m << ":";
    if (h) {
        for (int i = 0; i < n; i++) {
            cout << " " << r[i];
        }
        cout << "\n";
    } else {
        cout << " IMPOSSIBLE\n";
    }
}

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        laske(i+1);
    }
}
