#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

bool mark[200][200];
int h[200][200];
int m, n;

bool check() {
    memset(mark, false, sizeof(mark));
//row
    for (int i = 1; i <= m; i++) {
        int hmax = 0;
        for (int j = 1; j <= n; j++)
            hmax = max(hmax, h[i][j]);

        for (int j = 1; j <= n; j++)
                mark[i][j] |= (h[i][j] == hmax);
    }
//colum
    for (int j = 1; j <= n; j++) {
        int hmax = 0;
        for (int i = 1; i <= m; i++)
            hmax = max(hmax, h[i][j]);

        for (int i = 1; i <= m; i++)
             mark[i][j] |= (h[i][j] == hmax);
    }

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            if (!mark[i][j]) return false;
    return true;
}

int main() {
    freopen("B-large.in", "r", stdin);
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
