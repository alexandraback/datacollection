#include <iostream>
#include <string>

const int maxn = 110;

int a[maxn][maxn], colmax[maxn], rowmax[maxn];

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    cin >> T;
    for (int sc = 1; sc <= T; sc++) {
        int n, m, i, j;
        cin >> n >> m;

        for (i = 0; i < n; i++)
            rowmax[i] = 0;

        for (j = 0; j < m; j++)
            colmax[j] = 0;

        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                cin >> a[i][j];
                if (a[i][j] > rowmax[i]) rowmax[i] = a[i][j];
                if (a[i][j] > colmax[j]) colmax[j] = a[i][j];
            }
        }

        bool ok = true;
        for (i = 0; i < n; i++)
            for (j = 0; j < m; j++)
                if (a[i][j] != rowmax[i] && a[i][j] != colmax[j])
                    ok = false;

        cout << "Case #" << sc << ": ";
        if (ok) cout << "YES"; else cout << "NO";
        cout << endl;
    }

    fclose(stdin);
    fclose(stdout);
}
