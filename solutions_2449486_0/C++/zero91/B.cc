#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <functional>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>

using namespace std;

#define MAXN 110
#define MAXM 110
#define INF 200

int
main ()
{
    int T, m, n;
    int matrix[MAXN][MAXM];
    int row_max[MAXN], col_max[MAXM];
    bool ans;

    scanf ("%d", &T);
    for (int k = 1; k <= T; ++k) {
        scanf ("%d %d", &n, &m);

        memset (row_max, 0, sizeof (row_max));
        memset (col_max, 0, sizeof (col_max));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                scanf ("%d", &matrix[i][j]);
                row_max[i] = max(row_max[i], matrix[i][j]);
                col_max[j] = max(col_max[j], matrix[i][j]);
            }
        }
        ans = true;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] != row_max[i] && matrix[i][j] != col_max[j]) {
                    ans = false;
                }
            }
        }
        if (ans) printf ("Case #%d: YES\n", k);
        else printf ("Case #%d: NO\n", k);
    }
    return 0;
}
