#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

bool mark[20][20];
int h[20][20];
int m, n;

bool check() {
    memset(mark, false, sizeof(mark));
//row
    for (int i = 1; i <= m; i++) {
        int ok = 1;
        for (int j = 1; j <= n; j++)
            if (h[i][j] == 2) ok = 0;

        if (ok) {
            for (int j = 1; j <= n; j++)
                mark[i][j] = true;
        }
    }
//colum
    for (int j = 1; j <= n; j++) {
        int ok = 1;
        for (int i = 1; i <= m; i++)
            if (h[i][j] == 2) ok = 0;

        if (ok) {
            for (int i = 1; i <= m; i++)
                mark[i][j] = true;
        }
    }

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            if (h[i][j] == 1 && !mark[i][j]) return false;
    return true;
}

int main() {
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("b.out", "w", stdout);

    int ntest;
    cin >> ntest;
    for (int test = 1; test <= ntest; test++) {
        cout << "Case #" << test << ": ";

        cin >> m >> n;
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                cin >> h[i][j];
        if (check()) cout <<"YES" << endl;
        else cout <<"NO" << endl;
    }

}
