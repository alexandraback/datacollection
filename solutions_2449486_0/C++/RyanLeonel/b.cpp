#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int a[100][100], m, n;

bool aa(int x, int y)
{
    int a1[100][100], i, j, i1[10], j1[10], temp;
    for (i = 0; i < n; i++) for (j = 0; j < m; j++) a1[i][j] = 2;
    temp = x; for (i = 0; i < n; i++) { i1[i] = temp % 2; temp /= 2; }
    temp = y; for (j = 0; j < m; j++) { j1[j] = temp % 2; temp /= 2; }
    for (i = 0; i < n; i++) { if (i1[i]) { for (j = 0; j < m; j++) a1[i][j] = 1; } }
    for (j = 0; j < m; j++) { if (j1[j]) { for (i = 0; i < n; i++) a1[i][j] = 1; } }
    for (i = 0; i < n; i++) for (j = 0; j < m; j++) if (a1[i][j] != a[i][j]) return false;
    return true;
}

int main()
{
    bool ok;
    int cnt, i, j, k, m1, n1, t;
    string status;
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    cin >> t;
    for (cnt = 1; cnt <= t; cnt++)
    {
        cin >> n; cin >> m; ok = false;
        for (i = 0; i < n; i++) for (j = 0; j < m; j++) cin >> a[i][j];
        n1 = 1; for (i = 0; i < n; i++) n1 *= 2;
        m1 = 1; for (i = 0; i < m; i++) m1 *= 2;
        for (i = 0; i < n1; i++)
        {
            for (j = 0; j < m1; j++)
            {
                if (aa(i, j)) ok = true;
                if (ok) break;
            }
            if (ok) break;
        }
        status = (ok ? "YES" : "NO");
        cout << "Case #" << cnt << ": " << status << endl;
    }
    return 0;
}
