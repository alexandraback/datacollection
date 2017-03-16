#include <iostream>

using namespace std;

int t;
int n;
int c[3333];

void solve(int x) {
    cin >> n;
    for (int i = 1; i <= 2500; i++) c[i] = 0;
    for (int i = 0; i < 2*n-1; i++) {
        for (int j = 0; j < n; j++) {
            int u;
            cin >> u;
            c[u]++;
        }
    }
    cout << "Case #" << x << ": ";
    for (int i = 1; i <= 2500; i++) {
        if (c[i]%2 == 1) cout << i << " ";
    }
    cout << "\n";
}

int main() {
    cin >> t;
    for (int i = 1; i <= t; i++) solve(i);
}
