#include <iostream>

using namespace std;

int t;
int n, m;
int a[100][100];

bool vaaka(int y, int r) {
    for (int i = 0; i < m; i++) {
        if (a[y][i] > r) return false;
    }
    return true;
}

bool pysty(int x, int r) {
    for (int i = 0; i < n; i++) {
        if (a[i][x] > r) return false;
    }
    return true;
}

void laske(int k) {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    string v = "YES";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vaaka(i, a[i][j])) continue;
            if (pysty(j, a[i][j])) continue;
            v = "NO";
            goto loppu;
        }
    }
    loppu:
    cout << "Case #" << k << ": " << v << "\n";
}

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        laske(i+1);
    }
}
