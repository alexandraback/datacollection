#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <map>
#include <set>

using namespace std;

int tests;
int n, m;
int a[105][105];

int main() {
    cin >> tests;
    for (int test_id = 1; test_id <= tests; ++test_id) {
        cin >> n >> m;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> a[i][j];
        string res = "YES";
        while (1) {
            int r = -1;
            int c = -1;
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < m; ++j)
                    if (a[i][j] != -1 && (r == -1 || a[i][j] < a[r][c])) {
                        r = i;
                        c = j;
                    }
            if (r == -1) break;
            bool ok1 = true;
            for (int i = 0; i < n; ++i)
                if (a[i][c] > a[r][c])
                    ok1 = false;
            if (ok1)
                for (int i = 0; i < n; ++i)
                    a[i][c] = -1;
            bool ok2 = true;
            for (int j = 0; j < m; ++j)
                if (a[r][j] > a[r][c])
                    ok2 = false;
            if (ok2)
                for (int j = 0; j < m; ++j)
                    a[r][j] = -1;
            if (!(ok1 || ok2)) {
                res = "NO";
                break;
            }
        }
        cout << "Case #" << test_id << ": " << res << endl;
    }
    return 0;
}
