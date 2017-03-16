#include  <stdio.h>
#include  <string>
#include  <string.h>

using namespace std;

int mat[110][110];

bool hasGreaterInRow(int i, int j, int m) {
    for (int k = 0; k < m; k++)
        if (mat[i][k] > mat[i][j])
            return true;

    return false;
}

bool hasGreaterInColumn(int i, int j, int n) {
    for (int k = 0; k < n; k++)
        if (mat[k][j] > mat[i][j])
            return true;

    return false;
}

int main() {
    int t, n, m, in;
    string r;
    bool ans;

    scanf(" %d", &t);

    for (int c = 1; c <= t; c++) {
        ans = true;
        memset(mat, 0, sizeof(mat));

        scanf(" %d %d", &n, &m);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf(" %d", &mat[i][j]);
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (hasGreaterInRow(i, j, m) && hasGreaterInColumn(i, j, n)) {
                    ans = false;
                    break;
                }
            }

            if (!ans)
                break;
        }

        r = ans ? "YES" : "NO";

        printf("Case #%d: %s\n", c, r.c_str());
    }

    return 0;
}

