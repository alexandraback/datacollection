#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <ctime>
#include <utility>
using namespace std;

#define forn(i, n) for(int i = 0; i < n; i++)


int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    forn(test, t) {
        int n, m;
        vector<int> row, col;
        vector<vector<int> > a;
        cin >> n >> m;
        a.resize(n);
        row.resize(n, 0);
        col.resize(m, 0);
        forn(i, n) {
            a[i].resize(m);
            forn(j, m) {
                cin >> a[i][j];
                row[i] = max(a[i][j], row[i]);
                col[j] = max(a[i][j], col[j]);
            }
        }
        bool fail = false;
        cout << "Case #" << test + 1 << ": ";
        forn(i, n) {
            forn(j, m) {
                if (!fail  &&  a[i][j] != row[i]  &&  a[i][j] != col[j]) {
                    fail = true;
                    cout << "NO\n";
                }
            }
        }
        if (!fail) {
            cout <<"YES\n";
        }
    }
	return 0;
}
