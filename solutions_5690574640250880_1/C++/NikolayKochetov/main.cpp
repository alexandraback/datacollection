#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool solve(int h, int w, int m, vector < string > &ans) {
    ans.assign(h, string(w, '.'));
    if (h * w == m + 1) {
        ans.assign(h, string(w, '*'));
        ans[0][0] = 'c';
        return true;
    }
    if (h == 1) {
        ans[0][w - 1] = 'c';
        if (w == 1)
            return true;
        if (m > w - 1)
            return false;
        for (int i = 0; i < m; i++)
            ans[0][i] = '*';
        return true;
    }
    if (h == 2) {
        if (m % 2) {
            return false;
        } else {
            if (h * w - 4 < m)
                return false;
            for (int i = 0; i < m / 2; i++)
                ans[0][i] = ans[1][i] = '*';
            ans[0][w - 1] = 'c';
            return true;
        }
    }
    for (int i = 0; i < h - 2 && m; i++)
        for (int j = 0; j < w - 2 && m; j++) {
            ans[i][j] = '*';
            m--;
        }
    ans[h - 1][w - 1] = 'c';
    if (m == 0)
        return true;
    if (m % 2 == 0) {
        if (2 * (w + h) - 8 < m)
            return false;
        for (int i = 0; i < h - 2 && m; i++) {
            ans[i][w - 1] = ans[i][w - 2] = '*';
            m -= 2;
        }
        for (int i = 0; i < w - 2 && m; i++) {
            ans[h - 1][i] = ans[h - 2][i] = '*';
            m -= 2;
        }
        return true;
    } else {
        ans[h - 3][w - 3] = '.';
        m++;
        if (2 * (w + h - 6) < m)
            return false;
        for (int i = 0; i < h - 3 && m; i++) {
            ans[i][w - 1] = ans[i][w - 2] = '*';
            m -= 2;
        }
        for (int i = 0; i < w - 3 && m; i++) {
            ans[h - 1][i] = ans[h - 2][i] = '*';
            m -= 2;
        }
        return true;
    }
}

int main() {
    freopen("C-large.in", "rt", stdin);
    freopen("output.txt","wt", stdout);
    int n;
    cin >> n;
    for (int test = 1; test <= n; test++) {
        int x, y, k;
        cin >> y >> x >> k;
        cout << "Case #" << test << ":\n";
        vector < string > ans;
        if (y <= x) {
            if (solve(y, x, k, ans)) {
                for (int i = 0; i < y; i++) {
                    for (int j = 0; j < x; j++)
                        cout << ans[i][j];
                    cout << endl;
                }
            } else {
                cout << "Impossible" << endl;
            }
        } else {
            if (solve(x, y, k, ans)) {
                for (int i = 0; i < y; i++) {
                    for (int j = 0; j < x; j++)
                        cout << ans[j][i];
                    cout << endl;
                }
            } else {
                cout << "Impossible" << endl;
            }
        }
    }
    return 0;
}