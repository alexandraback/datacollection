#include <cstdio>
#include <assert.h>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <cstring>
#include <hashtable.h>

using namespace std;
typedef long long ll;
int i, j, k, m, n;
char ss[10002];
int h[100][100], a[100], b[100];

int main()
{
    freopen("x.in", "r", stdin);
    freopen("x.txt", "w", stdout);

    int ti, tn;
    cin >> tn;
    gets(ss);
    for (ti = 1; ti <= tn; ti++)
    {
        cin >> m >> n;
        for (i = 0; i < 100; i++) a[i] = b[i] = 0;
        for (i = 0; i < m; i++)
            for (j = 0; j < n; j++)
            {
                cin >> h[i][j];
                a[i] = max(a[i], h[i][j]);
                b[j] = max(b[j], h[i][j]);
            }
        string ans = "YES";

        for (i = 0; i < m; i++)
            for (j = 0; j < n; j++)
                if (h[i][j] < a[i] && h[i][j] < b[j]) ans = "NO";

        cout << "Case #" << ti << ": " << ans << endl;
    }

    return 0;
}
