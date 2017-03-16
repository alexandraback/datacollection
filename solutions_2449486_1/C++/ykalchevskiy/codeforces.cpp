#include <algorithm>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

#define mp make_pair
#define pb push_back

void f(int k) {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > v(n + 1, vector<int> (m + 1, 0));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            cin >> v[i][j];
            v[n][j] = max(v[n][j], v[i][j]);
            v[i][m] = max(v[i][m], v[i][j]);
        }
    
    /*for (int i = 0; i < n + 1; ++i) {
        for (int j = 0; j < m + 1; ++j) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }*/
    
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (v[i][j] < v[n][j] && v[i][j] < v[i][m]) {
                cout << "Case #" << k << ": " << "NO" << endl;
                return;
            }
    
    cout << "Case #" << k << ": " << "YES" << endl;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        f(i);
    return 0;
}
